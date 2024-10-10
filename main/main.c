#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "portmacro.h"

void app_main(void)
{
    gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << GPIO_NUM_33),
    };

     gpio_config_t io_conf2 = {
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ULL << GPIO_NUM_1),
    };

    gpio_config(&io_conf);
    gpio_config(&io_conf2);
    gpio_set_level(GPIO_NUM_33, 1);
    
    while(1){
        vTaskDelay(10 / portTICK_PERIOD_MS);
        
            gpio_set_level(GPIO_NUM_33, !gpio_get_level(GPIO_NUM_1));
        
    }

}
