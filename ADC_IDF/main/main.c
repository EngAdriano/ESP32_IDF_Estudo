#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "spi_flash_mmap.h"
#include "driver/gpio.h"
#include "esp_log.h"
//o driver adc herdado está obsoleto, migre para usar sp_adc/adc_oneshot.h e esp_adc/adc_continuous.h para drivers de modo oneshot e modo contínuo, respectivamente
#include "driver/adc.h"
//Não esuqecer de adptar as funções para estas novas bibliotecas
//#include "esp_adc/adc_oneshot.h"        
//#include "esp_adc/adc_continuous.h"

void app_main(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);                            //Definindo a resolução do ADC, podemos trabalhar com taxas menores tipo 8, 9, 10, 11
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);     //Configura o canal e o ganho, neste caso teremos um ganho de 11dB, podemos trabalhar
                                                                    //com ganhos de 0dB, 11dB, 2,5dB e 6dB.
    adc2_config_channel_atten(ADC2_CHANNEL_0, ADC_ATTEN_DB_11);      //Configura o canal e o ganho do ADC

    while(true)
    {
        int val1 = 0;
        int val2 = 0;

        //O ADC1 retorna diretamente o valor para uma variável
        val1 = adc1_get_raw(ADC1_CHANNEL_4);

        //Cuidado, o ADC2 não retorna diretamente o valor e sim uma flag de erro, assim temos que direcionar dentro da chamada de função a variável de armazenadmento
        adc2_get_raw(ADC2_CHANNEL_0, ADC_WIDTH_BIT_12, &val2);      //Passamos o canall, a resolução e o endereço da variável de armazenamento

        printf("ADC1: %fV ADC2 %fV \n", val1*(3.3/4095), val2*(3.3/4095));  //Para converter em valores de tensão faço este cáculo já que Tensão do ESP 3.3 e resolução 12 bits
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}