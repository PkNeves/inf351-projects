/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    * {
      font-family: Arial;
    }
    .content {
      padding: 20px 10px;
    }
  </style>
  <title>INF 351</title>
</head>
<body>
  <div class="content">

    <h1>Programa Analítico de Disciplina</h1>
    <h2>INF 351 - Sistemas Embarcados</h2>
    
    <hr>
    <h3>Catálogo: 2022</h3>
    <p>Número de créditos: 4</p>
    <p>Carga horária semestral: 60h</p>
    <p>Carga horária semanal teórica: 4h</p>
    <p>Carga horária semanal prática: 0h</p>
    <p>Semestres: I e II</p>
    
    <hr>
    <h3>Objetivos</h3>
    <p>Desenvolvimento de projetos com sistemas embarcados.</p>
    
    <hr>
    <h3>Ementa</h3>
    <p>
      História dos Sistemas Embarcados. Arquitetura de Sistemas Embarcados. Protocolos de Comunicação.
      Linguagem e Ambientes de Programação. Projeto com Sistemas Embarcados. Validação de Sistemas
      Embarcados. Interfaceamento analógico e digital. Estado da arte em sistemas embarcados. Programação
      concorrente
    </p>
    
    <hr>
    <h3>Pré e correquisitos</h3>
    <p>INF 112</p>
    
    <hr>
    <a href="/conteudo">Conteudo</a> <br><br>
    <a href="/bibliografia">Bibliografia</a>
  </div>

</body>
</html>)rawliteral";

const char bibliografia[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    * {
      font-family: Arial;
    }
    .content {
      padding: 20px 10px;
    }
    table {
      margin: 20px 10px;
      max-width: 800px;
    }
    tr {
      padding: 5px;
      border: 1px solid;
    }
    td {
      padding: 5px;
      border: 1px solid;
    }
    th {
      background-color: #cfd2d3;
      padding: 5px;
      border: 1px solid;
    }
  </style>
  <title>Bibliografia</title>
</head>
<body>
  <div class="content">

    <h1>INF 351 - Sistemas Embarcados</h1>
  
    <h2>Bibliografia Básica</h2>
    <table>
      <thead>
        <tr>
          <th>Descrição</th>
          <th>Exemplares</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>BERGER, Arnold. Embedded systems design: an introduction to processes, tools, and
            techniques. Lawrence, Kansas [Estados Unidos]: CMP Books, Berkeley [Califórnia, Estados
            Unidos]: Distributed in the U.S. and Canada by Publishers Group West, c2002. xxviii, 237 p. ISBN
            1578200733 (broch.).</td>
          <td>2</td>
        </tr>
        <tr>
          <td>EVANS, Martin; NOBLE, Joshua. Arduino em ação: Martins Evans; Joshua Noble; Jordan
            Hochenbaum. 1. ed., 1. reimpr. São Paulo: Novatec, 2014. 424 p. ISBN 9788575223734 (broch.)</td>
          <td>1</td>
        </tr>
        <tr>
          <td>OLIVEIRA, André Schneider de; ANDRADE, Fernando Souza de. Sistemas embarcados:
            hardware e firmware na prática. 1. ed. São Paulo: Erica, 2006. 316 p. ISBN 8536501057 (broch.).</td>
          <td>1</td>
        </tr>
        <tr>
          <td>PECKOL, James K. Embedded systems: a contemporary design tool. Hoboken, NJ: John Wiley,
            c2008. xlvi, 810 p. ISBN 9780471721802 (enc.).</td>
          <td>2</td>
        </tr>
      </tbody>
    </table>
  
    <h2>Bibliografia Complementar</h2>
    <table>
      <thead>
        <tr>
          <th>Descrição</th>
          <th>Exemplares</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>PEREIRA, Fábio. Microcontroladores PIC: técnicas avançadas. 6 ed. 2. reimpr. São Paulo: África,
            2010. 366 p. ISBN 9788571947276 (broch.).</td>
          <td>1</td>
        </tr>
        <tr>
          <td>PEREIRA, Fábio. Microcontroladores PIC: técnicas avançadas. 6 ed. 3. reimpr. São Paulo: África,
            2011. 366 p. ISBN 9788571947276 (broch.).</td>
          <td>1</td>
        </tr>
      </tbody>
    </table>
    </span>
  
    <a href="/">Voltar</a>
  </div>
</body>
</html>)rawliteral";

const char conteudo[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    * {
      font-family: Arial;
    }
    .content {
      padding: 20px 10px;
    }
    table {
      margin: 20px 10px;
      max-width: 800px;
    }
    tr {
      padding: 5px;
      border: 1px solid;
    }
    td {
      padding: 5px;
      border: 1px solid;
    }
    th {
      background-color: #cfd2d3;
      padding: 5px;
      border: 1px solid;
    }
  </style>
  <title>Conteudo</title>
</head>
<body>
  <div class="content">

    <h1>INF 351 - Sistemas Embarcados</h1>
    <hr>
    <h2>Conteúdo</h2>
    <table>
      <thead>
        <tr>
          <th>Unidade</th>
          <th>T</th>
          <th>P</th>
          <th>ED</th>
          <th>Pj</th>
          <th>To</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>1.História dos Sistemas Embarcados</td>
          <td>2h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>2h</td>
        </tr>
        <tr>
          <td>2.Arquitetura de Sistemas Embarcados</td>
          <td>10h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>10h</td>
        </tr>
        <tr>
          <td>3.Protocolos de Comunicação</td>
          <td>6h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>6h</td>
        </tr>
        <tr>
          <td>4.Linguagem e Ambientes de Programação </td>
          <td>6h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>6h</td>
        </tr>
        <tr>
          <td>5.Projeto com Sistemas Embarcados</td>
          <td>10h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>10h</td>
        </tr>
        <tr>
          <td>6.Validação de Sistemas Embarcados </td>
          <td>6h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>6h</td>
        </tr>
        <tr>
          <td>7.Interfaceamento analógico e digital</td>
          <td>6h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>6h</td>
        </tr>
        <tr>
          <td>8.Estado da arte em sistemas embarcados</td>
          <td>8h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>8h</td>
        </tr>
        <tr>
          <td>9.Programação concorrente</td>
          <td>6h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>6h</td>
        </tr>
        <tr>
          <td><b>Total:</b></td>
          <td>60h</td>
          <td>0h</td>
          <td>0h</td>
          <td>0h</td>
          <td>60h</td>
        </tr>
      </tbody>
    </table>
    <p>Teórica (T); Prática (P); Estudo Dirigido (ED); Projeto (Pj); Total (To);</p>
  
    <a href="/">Voltar</a>
  </div>
</body>
</html>)rawliteral";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
  server.on("/conteudo", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", conteudo);
  });
  server.on("/bibliografia", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", bibliografia);
  });
  
  // Start server
  server.begin();
}
 
void loop(){
  
}