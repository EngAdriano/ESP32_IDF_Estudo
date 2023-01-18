#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "spi_flash_mmap.h"
#include "driver/gpio.h"

#define PIN 2


void app_main() 
{
    //gpio_rom_pad_select_gpio(2);
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    bool status = true;

    while(true)
    {
        status = !status;
        gpio_set_level(PIN, status);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}