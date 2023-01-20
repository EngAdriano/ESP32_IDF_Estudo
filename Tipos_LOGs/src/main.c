#include <stdio.h>
#include "esp_log.h"

void app_main() 
{
    ESP_LOGE("LOG1", "LOG DE ERRO");                    //Primeiro parâmetro serve para
    ESP_LOGW("LOG2", "LOG DE WARNING/AVISO");           //indicar a estrutura que este log está.
    ESP_LOGI("LOG3", "LOG DE INFORMAÇÃO");              //Basicamente para identificar de quem
    ESP_LOGD("LOG4", "LOG DE DEBUG");                   //pertende este LOG.
    ESP_LOGV("LOG5", "LOG DE TEXTO COMUM/VERBOSE");
}