#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

//Protótipo das funções
void pwm_init(void);

void app_main(void)
{
    pwm_init();
    for (int duty = 0; duty < 8192; duty++)                         //Vamos variar o duty cicle para olharmos a variação do tamanho do pulso
    {
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);   //São 13 bits de resolução, logo temos 2^13 = 8192, para duty de 50% teremos então 8192/2 = 4096 (0 - 4095)
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);      //Atualizando do duty cicle
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    
}

void pwm_init(void)
{
    //Estrutura de dados para configurar o PWM
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,                      //Modo de trabalho do PWM
        .timer_num  = LEDC_TIMER_0,                             //O timer a ser utilizado
        .duty_resolution = LEDC_TIMER_13_BIT,                   //Resolução de 13 bits
        .freq_hz = 5000,                                        //Frequência do PWM
        .clk_cfg = LEDC_AUTO_CLK                                //Configuração automática de clock
    };
    ledc_timer_config(&ledc_timer);

    //Estrutura de dados para configurar o canal do PWM
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,                      //Modo de trabalho do canal
        .channel = LEDC_CHANNEL_0,                              //Canal utilizado
        .timer_sel = LEDC_TIMER_0,                              //Utilizar o timer 0, o mesmo do PWM
        .intr_type = LEDC_INTR_DISABLE,                         //Interrupção desabilitada, pelo menos neste exemplo
        .gpio_num = 25,                                         //Número do GPIO utilizado
        .duty = 0,                                              //Duty cicle inicial em zero
        .hpoint = 0                                             //hpoint em zero
    };
    ledc_channel_config(&ledc_channel);
}