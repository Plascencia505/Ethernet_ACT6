#include <UIPEthernet.h>

// --- Definición de pines lógicos ---
const int PIN_LED = 4;
const int PIN_CS_ETHERNET = 5;

// Dirección MAC arbitraria
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Sustituir según la red del enrutador doméstico
IPAddress ip(192, 168, 1, 25);

EthernetServer servidor(80);
bool estadoLED = false;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  Serial.println("\n--- Iniciando Servidor Web ENC28J60 (Modo Enrutador) ---");

  // Inicializar comunicación SPI y levantar la pila TCP/IP
  Ethernet.init(PIN_CS_ETHERNET);
  Ethernet.begin(mac, ip);
  servidor.begin();

  Serial.print("[INFO] Servidor web local iniciado en IP: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // Escuchar a los clientes HTTP en la red local
  EthernetClient cliente = servidor.available();

  if (cliente) {
    String peticion = "";

    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        peticion += c;

        // Validar el final de la cabecera HTTP (\r\n\r\n)
        if (c == '\n' && peticion.endsWith("\r\n\r\n")) {

          // Procesamiento de comandos URI
          if (peticion.indexOf("GET /encender") != -1) {
            estadoLED = true;
            digitalWrite(PIN_LED, HIGH);
            Serial.println("[HTTP] Comando ejecutado: LED ENCENDIDO");
          } else if (peticion.indexOf("GET /apagar") != -1) {
            estadoLED = false;
            digitalWrite(PIN_LED, LOW);
            Serial.println("[HTTP] Comando ejecutado: LED APAGADO");
          }

          // Cabeceras de respuesta HTTP 200 OK
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println("Connection: close");
          cliente.println();

          // Interfaz de Usuario HTML
          cliente.println("<!DOCTYPE HTML>");
          cliente.println("<html><head><title>Control IoT Ethernet</title>");
          cliente.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          cliente.println("<style>body { font-family: Arial; text-align: center; margin-top: 50px; } ");
          cliente.println("button { padding: 15px 30px; font-size: 20px; margin: 10px; cursor: pointer; }</style></head>");
          cliente.println("<body><h1>Panel de Control Ethernet</h1>");

          cliente.print("<h2>Estado del Actuador: ");
          cliente.print(estadoLED ? "<span style='color:green;'>ENCENDIDO</span>" : "<span style='color:red;'>APAGADO</span>");
          cliente.println("</h2>");

          cliente.println("<button onclick=\"location.href='/encender'\">Encender LED</button>");
          cliente.println("<button onclick=\"location.href='/apagar'\">Apagar LED</button>");
          cliente.println("</body></html>");

          break;  // Finalizar transmisión de la página
        }
      }
    }

    // Margen de seguridad para cerrar la conexión TCP
    delay(10);
    cliente.stop();
  }
}