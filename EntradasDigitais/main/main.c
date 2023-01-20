#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "spi_flash_mmap.h"
#include "driver/gpio.h"

#define PIN (2)
#define BT_PIN (34)


void app_main() 
{
    //gpio_rom_pad_select_gpio(2);
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(BT_PIN);
    gpio_set_direction(BT_PIN, GPIO_MODE_INPUT);

    bool status = true;

    while(true)
    {
        status = gpio_get_level(BT_PIN);        //Ler o pino BT_PIN (gpio34)
        gpio_set_level(PIN, status);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}