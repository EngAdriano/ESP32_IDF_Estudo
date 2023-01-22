#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//Variáveis/Handles
static TaskHandle_t taskHandler = NULL;             //Inicialização de um Handller

//Protótipo das funções/Tasks
void Task1(void * params);
void Task2(void * params);

void app_main(void)
{
    xTaskCreate(&Task1, "Task1", 2048, NULL, 2, &taskHandler);
    xTaskCreate(&Task2, "Task2", 2048, NULL, 2, &taskHandler);
}

void Task1(void * params)
{
    while(true)
    {
        xTaskNotifyGive(taskHandler);               //Função para o envio de notificação
        vTaskDelay(2000 / portTICK_PERIOD_MS);      //2 segundos de delay para que possamos acompanhar a execução do envio da notificação
    }
}

void Task2(void * params)
{
    while(true)
    {
        int counter = ulTaskNotifyTake(pdFALSE, portMAX_DELAY);   //primeiro campo não apagar o histórico de notificações, segundo campo esperar até o tempo máximo
        printf("Notificação recebida %d ", counter);
    }
}