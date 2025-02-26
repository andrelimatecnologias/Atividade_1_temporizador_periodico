#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


#define LED_RED_WOKWI 11
#define LED_YELLOW_WOKWI 12
#define LED_GREEN_WOKWI 13

#define LED_RED_PLACA 13
#define LED_GREEN_PLACA 11

#define MODO_WOKWI 0
#define MODO_PLACA 1

static uint8_t modo_operacao;

static volatile uint8_t acao;


void inicializacao(){
    if(modo_operacao==MODO_WOKWI){
        gpio_init(LED_RED_WOKWI);
        gpio_init(LED_YELLOW_WOKWI);
        gpio_init(LED_GREEN_WOKWI);

        gpio_set_dir(LED_RED_WOKWI,GPIO_OUT);
        gpio_set_dir(LED_YELLOW_WOKWI,GPIO_OUT);
        gpio_set_dir(LED_GREEN_WOKWI,GPIO_OUT);

        gpio_put(LED_RED_WOKWI,true);
    }
    if (modo_operacao==MODO_PLACA){
        gpio_init(LED_RED_PLACA);
        gpio_init(LED_GREEN_PLACA);

        gpio_set_dir(LED_RED_PLACA,GPIO_OUT);
        gpio_set_dir(LED_GREEN_PLACA,GPIO_OUT);

        gpio_put(LED_RED_PLACA,true);
    }
}

bool repeating_timer_callback(struct repeating_timer *t){
    if(modo_operacao==MODO_WOKWI){
        acao++;
        if(acao==3){
            acao=0;
            if(gpio_get(LED_RED_WOKWI)){
                gpio_put(LED_RED_WOKWI,0);
                gpio_put(LED_YELLOW_WOKWI,1);
                return true;
            }
            if(gpio_get(LED_YELLOW_WOKWI)){
                gpio_put(LED_YELLOW_WOKWI,0);
                gpio_put(LED_GREEN_WOKWI,1);
                return true;
            }
            if(gpio_get(LED_GREEN_WOKWI)){
                gpio_put(LED_GREEN_WOKWI,0);
                gpio_put(LED_RED_WOKWI,1);
            }
        }
    }
    if (modo_operacao==MODO_PLACA){
        acao++;
        if(acao==3){
            acao=0;
            if(gpio_get(LED_RED_PLACA)&&gpio_get(LED_GREEN_PLACA)){
                gpio_put(LED_RED_PLACA,0);
                return true;
            }
            if(gpio_get(LED_RED_PLACA)){
                gpio_put(LED_GREEN_PLACA,1);
                return true;
            }
            if(gpio_get(LED_GREEN_PLACA)){
                gpio_put(LED_GREEN_PLACA,0);
                gpio_put(LED_RED_PLACA,1);
            }
        }
        
    }
    return true;
}

int main()
{
    stdio_init_all();

    /* 
       A atividade requere 3 LEDs e um deles na cor amarela. No Wokwi é possível montar esta configuração de forma direta, entretanto,
       Na placa BitDogLab as GPIO 11, 12 e 13 são direcionadas para um LED RGB, logo, para configurar a cor amarela será necessário que
       se some a cor verde com a cor vermelha e por causa dessa diferenciação decidi fazer um código que facilite a simulação nos dois
       ambientes

       Mude o valor da variável "modo_operacao" quando quiser escolher se vai simular no wokwi ou se vai executar diretamente na placa.
    */
    modo_operacao = MODO_WOKWI;
    //modo_operacao = MODO_PLACA;

    /*
        A variável "ação" será a representação do contador para determinar a ação de mudar o sinal do semáforo, assim, sempre que o
        contador chegar ao valor 3 a ação será tomada e ele será reiniciado
    */
    acao = 0;
    
    // A função de inicialização configura as portas do microcontrolador para controlar os LEDs definindo o comportamento das GPIO
    inicializacao();

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("falta %ds para mudar o sinal\n",(3-acao));
        sleep_ms(1000);
    }
}
