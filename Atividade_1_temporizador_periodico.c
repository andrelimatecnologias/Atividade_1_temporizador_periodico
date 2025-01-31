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

static uint8_t acao;



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


    acao = 0;
    

    while (true) {
        sleep_ms(1000);
    }
}
