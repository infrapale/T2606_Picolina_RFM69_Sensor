#ifndef __SENSOR_H__
#define __SENSOR_H__

#define I2C_ADDR_BMP180         0x77
#define I2C_ADDR_BMP280         0x11
#define I2C_ADDR_BME680         0x11
#define I2C_ADDR_SHT31          0x44
#define I2C_ADDR_AHT20          0x38
#define I2C_ADDR_VEML7700       0x10

#define SENSOR_LABEL_LEN        10
#define NBR_TEST_SENSOR         4


typedef enum
{
    SENSOR_TYPE_UNDEFINED = 0,
    SENSOR_TYPE_BMP180,
    SENSOR_TYPE_BMP280,
    SENSOR_TYPE_BME680,
    SENSOR_TYPE_AHT20,
    SENSOR_TYPE_SHT31,
    SENSOR_TYPE_DS18B20,
    SENSOR_TYPE_PIR,
    SENSOR_TYPE_VEML7700,
    SENSOR_TYPE_NBR_OF
} sensor_type_et;

typedef enum 
{
    SENSOR_STATUS_OK = 0,
    SENSOR_STATUS_NOT_AVAILABLE,
    SENSOR_STATUS_READ_ERROR
} sensor_status_et;

typedef enum 
{
    SENSOR_SHOW_BM_NONE     = 0b00000000,
    SENSOR_SHOW_BM_TEMP     = 0b00000001,
    SENSOR_SHOW_BM_HUM      = 0b00000010,
    SENSOR_SHOW_BM_PRESS    = 0b00000100,
    SENSOR_SHOW_BM_VALUE    = 0b00001000,
    SENSOR_SHOW_BM_CNTR     = 0b00010000,
} sensor_show_bm_et;

typedef struct
{
    char        label[SENSOR_LABEL_LEN];
    uint8_t     i2c_addr;
    bool        active;
    uint8_t     status;
    bool        updated;
    uint8_t     show_bm;
    uint16_t    counter;
    uint32_t    next_meas;
    uint32_t    next_send;
} sensor_meta_st;



typedef struct 
{
    sensor_meta_st meta;
    uint32_t  pressure;
    float     temperature;
    float     humidity;
    float     float_val;
    bool      on_off;
} sensor_st;

typedef struct 
{
    uint8_t     sender;
    uint8_t     sensor;
    uint32_t    interval;
    float       temp;
    float       min_temp;
    float       max_temp;
    float       delta_temp;
    bool        going_up;
} sensor_test_st;


void sensor_initialize(void);

#endif