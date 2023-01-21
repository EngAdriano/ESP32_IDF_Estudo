#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//Protótipo das funções/tasks
void Task1(void * params);
void Task2(void * params);

void app_main(void)
{
    xTaskCreate(&Task1, "Leitura de temperatura", 2048, "Task 1", 5,  NULL);            //Task sem definir qual núcleo executa ela
    xTaskCreatePinnedToCore(&Task2, "Leitura de Umidade", 2048, "Task 2", 2,  NULL, 1);    //Task onde defino o núcleo que va executar ela (0 - primeiro e 1 - segundo core)
}

void Task1(void * params)
{
    while(true)
    {
        printf("Realizando leitura de temperatura %s \n", (char *) params);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void * params)
{
    while(true)
    {
        printf("Realizando leitura de umidade %s \n", (char *) params);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}