#include <stdio.h>
#include "esp_log.h"

void app_main() 
{
    ESP_LOGE("LOG1", "LOG DE ERRO");                            //Primeiro parâmetro serve para
    ESP_LOGW("LOG1", "LOG DE WARNING/AVISO");                   //indicar a estrutura que este log está.
    ESP_LOGI("LOG1", "LOG DE INFORMAÇÃO");                      //Basicamente para identificar de quem
    ESP_LOGD("LOG1", "LOG DE DEBUG");                           //pertende este LOG.
    ESP_LOGV("LOG1", "LOG DE TEXTO COMUM/VERBOSE");

    int var = 0;
    ESP_LOGE("LOG2", "LOG DE ERRO %d", var++);                  //Primeiro parâmetro serve para
    ESP_LOGW("LOG2", "LOG DE WARNING/AVISO %d", var++);         //indicar a estrutura que este log está.
    ESP_LOGI("LOG2", "LOG DE INFORMAÇÃO %d", var++);            //Basicamente para identificar de quem
    ESP_LOGD("LOG2", "LOG DE DEBUG %d", var++);                 //pertende este LOG.
    ESP_LOGV("LOG2", "LOG DE TEXTO COMUM/VERBOSE %d", var++);   //Podemos colocar valores de variáveis no retorno do LOG

    esp_log_level_set("LOG3", ESP_LOG_WARN);                    //O default é prioridade, assim coloque no LOG máximo que deseja
                                                                //e só então altere em tempo de execução do código.
    ESP_LOGE("LOG3", "LOG DE ERRO");                            //Primeiro parâmetro serve para
    ESP_LOGW("LOG3", "LOG DE WARNING/AVISO");                   //indicar a estrutura que este log está.
    ESP_LOGI("LOG3", "LOG DE INFORMAÇÃO");                      //Basicamente para identificar de quem
    ESP_LOGD("LOG3", "LOG DE DEBUG");                           //pertende este LOG.
    ESP_LOGV("LOG3", "LOG DE TEXTO COMUM/VERBOSE");

}