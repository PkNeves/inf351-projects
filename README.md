# inf351-projects

## [Programa Analítico INF 351](https://github.com/PkNeves/inf351-projects/tree/main/esp32_wifi_INF351_analitic_program)
### Sobre
Projeto que retorna uma página web do programa analítico da matéria INF 351 - Sistemas Embarcados, aessado por uma rede wifi fornecida pelo esp32.

Com a IDE do Arduino instalada, siga os passos do próximo link para adicionar a placa esp32 a sua IDE [Adicionando esp32 a IDE do Arduino](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

A maior parte da configuração do projeto foi utilizando o link [Site Guia do projeto](https://randomnerdtutorials.com/esp32-client-server-wi-fi/#:~:text=The%20ESP32%20server%20creates%20its,the%20ESP32%20server%20wireless%20network.) , que ensina a configurar um servidor pelo wifi usando o esp32.

A parte de renderização de páginas html pode ser encontrada no site [Como exibir páginas web no esp32](https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/)

### Modo de usar
 1. Com o esp32 ligado, procure a rede 'ESP32-Access-Point' no wifi do seu celular ou outro disposivo com essa tecnologia e insira a senha: 123456789.
 2. Com o wifi conectado, abra seu navegador e digite o endereço 192.168.4.1
 3. Pronto! Essa url deverá te fornecer a página web do programa analítico da disciplina de INF 351 - Sistemas Embarcados.

## [Tetris na mesa de led](https://github.com/PkNeves/inf351-projects/tree/main/mesa_led_tetris_millis)

### Sobre

Jogo Tetris feito usando uma mesa de led 16x16 e 4 botões com as funcionalidades: girar peça, mover para direita, mover para esquerda e fazer a peça descer mais rápido.

Inicialmente o jogo já tinha sido desenvolvido por outro aluno, mas utilizava a função `delay()` que gerava alguns atrasos ao apertar o botão. Para melhorar essa parte do código, foi utilizado a função `millis()`, que destrava o fluxo, deixando a funcionalidade de cair a peça independente da funcionalidade de apertar os botões de ação.

## [Sensor de proximidade com Led](https://github.com/PkNeves/inf351-projects/tree/main/sensor_de_proximidade_com_led)

### Sobre

Projeto com um sensor ultrasônico que capta a proximidade de objetos e acende o led de acordo com a proximidade.

O projeto foi primeiro montado no [Tinkercad](tinkercad.com) e depois passado para o projeto físico, montado em protoboard.
Ele utiliza 6 led (2 verdes, 2 amaralos, 2 vermelhos), um sensor de presença e um arduíno.

Os leds estão posicionados um atras do outro na sequência Verde -> Amarelo -> Vermelho. O sensor de presença então capta e computa a distância. Quando mais próximo, mais leds irão se acender, começando pelo primeiro verde.

[Link do Projeto](https://www.tinkercad.com/things/fAI9ovxNcrw-ultrasonicoledgradual/editel?sharecode=pYKlDVMLFdy8B9F-QoZ78CVEZKsYuIm2f86PK23kT5A)

## [Tinkercad Neopixel Led e Botão](https://github.com/PkNeves/inf351-projects/tree/main/tinkercad_neopixel_botao_caminha_led)

### Sobre

Projeto que possui uma fita de led e um botão. Toda vez que o botão é pressionado, o próximo led da fita de led acende em uma cor randômica.

O projeto foi feito no [Tinkercad](tinkercad.com) usando um arduíno, uma fita de led e um botão.

O projeto consiste na idéia primária do jogo corrida de led e pode ser usado para um entendimento mais simples de como a corrida funciona.

[Link do Projeto](https://www.tinkercad.com/things/l69hM65qgVx-acendeledbotao/editel?sharecode=KULfZgp6uiLu-ePZLGjAUw3RDOuuDU-fVLLjw_NwtK0)

## [Tinkercad Sinal Trânsito Millis](https://github.com/PkNeves/inf351-projects/tree/main/tinkercad_sinal_transito_millis)

### Sobre

Um projeto que simula dois sinais de trânsito, quando um fecha o outro abre e vice versa, tendo seus tempos definidos em código.

Foi um dos primeiro projetos passados e é interessante para entender como a função `millis()` funciona e sua vantagem em relação ao `delay()`

[Link do Projeto](https://www.tinkercad.com/things/61INOquJCPC-sinal-de-transito-com-millis-inf-351/editel?sharecode=55GGh4_gTXeSKtbzUXC8MCQ1jOaVLpfPGv1oVy23m9s)

## [Tinkercad Led Gradual](https://github.com/PkNeves/inf351-projects/tree/main/tinkercad_ultrasonico_led_gradual)

### Sobre

Projeto que também utiliza o sensor ultrasônico, mas com um led RGB. A medida que a distância muda, a cor do RGB muda também.

Um projeto bom para entender como fuciona o led RGB.

[Link do Projeto](https://www.tinkercad.com/things/gSkGBH8aQ1w-led-gradual/editel?sharecode=jrZ-L51mCNOmMbWX7hYsUqZjDvUbirvMW8VZTSeuhHE)

## [Tinkercad Ultrasônico e Tone](https://github.com/PkNeves/inf351-projects/tree/main/tinkercad_ultrasonico_sensor_proximidade_tone)

### Sobre

Projeto similar com o sensor de proximidade, mas que utiliza um speaker para emitir um sinal sonoro quando vai chegando mais próximo.

Ele também possui os leds que acendem junto, mas toca um som com uma frequência mais aguda cada vez que vai chegando mais perto.

[Link do Projeto](https://www.tinkercad.com/things/demXq15jxE9-sensorproximidadecomtone/editel?sharecode=IEGGBaeBEbiKXHcCeSETGJw-KQzzfCTrCnbITjKoT2U)