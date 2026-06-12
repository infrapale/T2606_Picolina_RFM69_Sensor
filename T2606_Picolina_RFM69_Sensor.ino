/******************************************************************************
    T2606_Picolina_RFM69_Sensor

*******************************************************************************
    I2C device found at address 0x10  !   VEML7700  
    I2C device found at address 0x44  !   SHT21

*******************************************************************************

******************************************************************************/






#include    <Wire.h>
#include    "main.h"
#include    "secrets.h"
#include    "r69.h"
#include    "atask.h"
#include    "io.h"
#include    "sensor.h"


main_ctrl_st main_ctrl = {
    .next_io_tick = 0,
    .my_addr = "BTN1",
};

void modem_task(void);
void print_debug_task(void);

atask_st modem_handle              = {"Radio Modem    ", 100,0, 0, 255, 0, 1, modem_task};
atask_st debug_th                  = {"Debug Task     ", 2000,    0,     0,  255,    0,  1,  print_debug_task };


void setup() {
    io_initialize();
    Serial1.setTX(PIN_TX0);   
    Serial1.setRX(PIN_RX0);
    Serial.begin(115200);
    Serial1.begin(9600);
    delay(2000);
    //while (!Serial); 

    atask_initialize();
    sensor_initialize();
    r69_initialize(Serial1);



}


void loop() {
    atask_run();

    // char c = butt_read(&status);
    // if(c != '.'){
    //     Serial.printf("%c-%d\n",c, status);
    // }

}