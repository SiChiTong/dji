#include "OurDJI_FUNC.h"
#include "string"

int DJI_Sample_Setup(void)
{

}

void listSerialPort(){
    printf("list possible serial port : \n");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        printf("    portName     : %s\n",info.portName().toStdString().data());
        printf("    description  : %s\n",info.description().toStdString().data());
        printf("    manufacturer : %s\n",info.manufacturer().toStdString().data());
        printf("\n");
    }
}

bool openSerial = false;
void openSerialport(const char* serialPortName)
{
    // argument
    const char* serial = serialPortName;
    int baud = 230400;

    DJI_Pro_Hw *hw_instance = DJI_Pro_Hw::Pro_Hw_Get_Instance();
    // open serial port
    if(!openSerial)
    {
        if(true == hw_instance->Pro_Hw_Setup(serial,baud))
         {
             hw_instance->start();
             printf("serial port %s open success\n",serialPortName);
         }
        else
         {
             printf("serial port %s open failed\n",serialPortName);
        }
        openSerial = true;
    }
    else
    {
        hw_instance->Pro_Hw_Close();
        printf("close serial success\n");
        openSerial = false;
    }

}

// 该变量一定要声明为全局变量或动态变量(new),因为激活的程序官方源码是在独立的线程中运行的,
// 同一进程的不同线程能够共享的只有全局变量的动态变量
activate_data_t user_act_data;
void active(){
    printf("active : \n");
    user_act_data.app_id = 1023480;//QString("1023480").toInt();
    user_act_data.app_api_level = 2;//QString("2").toInt();
    user_act_data.app_ver = SDK_VERSION;
    user_act_data.app_bundle_id[0] = user_act_data.app_bundle_id[1] = 0x12;
    user_act_data.app_key = "1bee7d67ad5cd35364f334f399d524046c39fca18f50b7ce98d98bce1f556f94";//QByteArray("1bee7d67ad5cd35364f334f399d524046c39fca18f50b7ce98d98bce1f556f94").data();

    DJI_Pro_Activate_API(&user_act_data,Activate_Callback);
}
void Activate_Callback(unsigned short res)
{
    char result[][50]={{"SDK_ACTIVATION_SUCCESS"},{"SDK_ACTIVE_PARAM_ERROR"},{"SDK_ACTIVE_DATA_ENC_ERROR"},\
                       {"SDK_ACTIVE_NEW_DEVICE"},{"SDK_ACTIVE_DJI_APP_NOT_CONNECT"},{" SDK_ACTIVE_DIJ_APP_NO_INTERNET"},\
                       {"SDK_ACTIVE_SERVER_REFUSED"},{"SDK_ACTIVE_LEVEL_ERROR"},{"SDK_ACTIVE_SDK_VERSION_ERROR"}};

    if(res >= 0 && res < 9)
    {
        printf("%s\n",*(result+res));
    }
    else
    {
        printf("Unkown ERROR\n");
    }
}

bool obtain = false;
void obtainControl()
{
    if(obtain){
        DJI_Pro_Control_Management(0,NULL);
        obtain = false;
        printf("release control success\n");
    }
    else{
        DJI_Pro_Control_Management(1,NULL);
        obtain = true;
        printf("obtain control success\n");
    }
}

const char* _OurGetSerialPort(){
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        const char* des = info.description().toStdString().data();
        const char* usb2serial = "USB-SERIAL";

        int len = strlen(usb2serial);
        int desLen = strlen(des);
        if(desLen < len) continue;                // descript 不可能是 usb2serial 接口，则切换下一个

        int i;
        for(i = 0; i < len; i++){
            if(des[i] != usb2serial[i]) continue; // descript 不可能是 usb2serial 接口，则切换下一个
        }

        return info.portName().toStdString().data();
    }
    return NULL;
}

void OurSetUp(){
#if (defined(PLATFORM_LINUX) && defined(TINYXML_CFG))
    int ret;
    int baudrate = 115200;
    char uart_name[32] = {"/dev/ttyUSB0"};

    if(DJI_Pro_Get_Cfg(&baudrate,uart_name,NULL,NULL,NULL) == 0)
    {
        /* user setting */
        printf("\n--------------------------\n");
        printf("uart_baud=%d\n",baudrate);
        printf("uart_name=%s\n",uart_name);
        printf("--------------------------\n");
    }
    ret = Pro_Hw_Setup(uart_name,baudrate);
    if(ret < 0)
        return ret;
#endif
    DJI_Pro_Setup(NULL);
}

bool _OurOpenSerial = false;
void OurDoSerialPort(const char* serialPortName=NULL, int baud = 230400){
    DJI_Pro_Hw *hw_instance = DJI_Pro_Hw::Pro_Hw_Get_Instance();
    // open serial port
    if(!_OurOpenSerial)
    {
        if(serialPortName == NULL){
            serialPortName = _OurGetSerialPort();
        }
        if(serialPortName == NULL){
            printf("cannot get enable USB-SERIAL port\n");
            return;
        }

        if(true == hw_instance->Pro_Hw_Setup(serialPortName, baud))
         {
             hw_instance->start();
             printf("serial port %s open success\n",serialPortName);
         }
        else
         {
             printf("serial port %s open failed\n",serialPortName);
        }
        _OurOpenSerial = true;
    }
    else
    {
        hw_instance->Pro_Hw_Close();
        printf("close serial success\n");
        _OurOpenSerial = false;
    }
}

void OurActivate(){

}

void OurActivateCallback(unsigned short res); // 激活函数的回调用函数，用会激活的转态
void OurDoObtain();
