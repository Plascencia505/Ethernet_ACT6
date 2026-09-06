#include <UIPEthernet.h>

// --- Definición de pines ---
const int PIN_LED = 26;
const int PIN_CS_ETHERNET = 5;

// --- Configuración de red ---
// Dirección MAC física (debe ser única en tu red local)
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Dirección IP estática
IPAddress ip(192, 168, 1, 25);

// Iniciar el servidor TCP en el puerto HTTP estándar
EthernetServer servidor(80);

bool estadoLED = false;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  Serial.println("\n--- Iniciando Servidor Web ENC28J60 ---");

  // Configurar el pin CS e iniciar el módulo de red
  Ethernet.init(PIN_CS_ETHERNET);
  Ethernet.begin(mac, ip);
  servidor.begin();

  Serial.print("Servidor web local iniciado en IP: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // Escuchar a los clientes entrantes
  EthernetClient cliente = servidor.available();

  if (cliente) {
    String peticion = "";

    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        peticion += c;

        // Una petición HTTP válida termina con una línea en blanco (\r\n\r\n)
        if (c == '\n' && peticion.endsWith("\r\n\r\n")) {

          // Analizar la cabecera HTTP para buscar los comandos del LED
          if (peticion.indexOf("GET /encender") != -1) {
            estadoLED = true;
            digitalWrite(PIN_LED, HIGH);
            Serial.println("[HTTP] Comando recibido: LED ENCENDIDO");
          } else if (peticion.indexOf("GET /apagar") != -1) {
            estadoLED = false;
            digitalWrite(PIN_LED, LOW);
            Serial.println("[HTTP] Comando recibido: LED APAGADO");
          }

          // Enviar código de respuesta HTTP 200 OK
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println("Connection: close");
          cliente.println();

          // Renderizar la interfaz web en HTML
          cliente.println("<!DOCTYPE HTML>");
          cliente.println("<html><head><title>Control IoT Ethernet</title>");
          cliente.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          cliente.println("<style>body { font-family: Arial; text-align: center; margin-top: 50px; } ");
          cliente.println("button { padding: 15px 30px; font-size: 20px; margin: 10px; cursor: pointer; }</style></head>");
          cliente.println("<body><h1>Panel de Control Ethernet</h1>");

          cliente.print("<h2>Estado del Actuador: ");
          cliente.print(estadoLED ? "<span style='color:green;'>ENCENDIDO</span>" : "<span style='color:red;'>APAGADO</span>");
          cliente.println("</h2>");

          // Botones que envían las peticiones HTTP al microcontrolador
          cliente.println("<button onclick=\"location.href='/encender'\">Encender LED</button>");
          cliente.println("<button onclick=\"location.href='/apagar'\">Apagar LED</button>");
          cliente.println("</body></html>");

          break;  // Salir del bucle una vez entregada la página
        }
      }
    }

    // Dar un breve tiempo al navegador para recibir los datos antes de cerrar
    delay(10);
    cliente.stop();
  }
}