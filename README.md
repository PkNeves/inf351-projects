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
