# Semáforo utilizando temporizador periódico

Este repositório contém o projeto de um semáforo utilizando temporizador periódico

## Componentes
- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (vermelho, amarelo e verde).
- 03 Resistores de 330 Ω.

## Funcionamento

- Os 3 LEDs, vermelho, amarelo e verde de um semáforo acendem em intervalos de 3 segundos
- Através de protocolo UART e USB é possível visualizar uma mensagem exibindo quantos segundos faltam até a troca do sinal.

## Instruções de uso

### Requisitos
- Ambiente de desenvolvimento **VS Code**.
- **Simulador Wokwi** para simulação do hardware.
- Kit de desenvolvimento **Pico SDK**.

### Passos para Execução
1. Clone este repositório:
   ```bash
   git clone https://github.com/andrelimatecnologias/Atividade_1_temporizador_periodico.git
   ```
2. Instale as dependências necessárias para o Pico SDK.
3. Importe o projeto no **VS Code** e configure o simulador Wokwi.
4. Compile o código e inicie a simulação.
5. A simulação é apenas observada, não possui interação com o usuário. 

### Observação
A prática pode ser realizada tanto com o simulador Wokwi, como em hardware real, bastando que apenas escolha o valor da variável "modo_operacao" para:
.  **`MODO_PLACA`** Modo de teste a ser aplicado na placa de desenvolvimento BitDogLab
.  **`MODO_WOKWI`** Modo a ser simulado com o Wokwi

## Vídeo de teste
Um vídeo mostrando o teste desta atividade pode ser acessado no link: https://www.youtube.com/watch?v=ddZUTpptMZ0

## Autor do projeto:
André Souza Lima
