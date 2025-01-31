# Semáforo utilizando temporizador periódico

Este repositório contém o projeto de um semáforo utilizando temporizador periódico

## Componentes
- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (vermelho, amarelo e verde).
- 03 Resistores de 330 Ω.

## Funcionamento

- Os 3 LEDs, vermelho, amarelo e verde de um semáforo acendem em intervalos de 3 segundos
- Através de protocolo UART e USB é possível visualizar uma mensagem exibindo quantos segundos faltam até a troca do sinal.

- A atividade pede que três LEDs sejam inseridos, mas ao utilizar a placa de desenvolvimento BitDogLab iremos usar o LED RGB, portanto, vamos precisar combinar duas cores: o Vermelho e o Verde, para produzir a cor Amarela, enquanto que na simulação vamos escolher diretamente um LED Amarelo. Logo, temos duas versões de softaware em um só arquivo. Para testar em cada um dos modelos precisa-se apenas substituir o valor da variável **modo_operacao**. Siga as Instruções de uso.

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
4. Defina o valor da variável **modo_operacao** na função **main** com alguma dessas constantes:
   
   .  **`MODO_PLACA`** Modo de teste a ser aplicado na placa de desenvolvimento BitDogLab
   
   .  **`MODO_WOKWI`** Modo a ser simulado com o Wokwi
5. Compile o código
7. Coloque a placa em modo Bootsel e transfira o código para iniciar a aplicação ao testar na placa BitDogLab
8. Inicialize o simulador para testar a simulação no Wokwi
9. A simulação é apenas observada, não possui interação com o usuário. 

### Observação
A prática pode ser realizada tanto com o simulador Wokwi, como em hardware real.

## Vídeo de teste
Um vídeo mostrando o teste desta atividade pode ser acessado no link: https://www.youtube.com/watch?v=ddZUTpptMZ0

## Autor do projeto:
André Souza Lima
