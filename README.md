# Facultad de Telemática
**Asignatura:** Entornos inteligentes y tecnologías disruptivas  
**Actividad VI:** Fundamentos y aplicación del módulo ENC28J60  
**Fecha:** 03/09/2026 | **Equipo:** 3  

### 👥 Integrantes del Equipo
* López Barajas Fernando Alonso
* Vega Flores Alejandra Ixchel
* Plascencia Figueroa Gael Alejandro
* Guzman Larios Juan Manuel
* Jimenez Anguiano Miguel Angel
* Diaz Ramirez Dulce Maria

**Profesor:** Esli Castellanos Berjan

---

## 📌 1. Objetivo General

El propósito global de esta actividad es desarrollar la capacidad de diseñar e implementar sistemas de comunicación cableada basados en el módulo Ethernet, integrando detalladamente los conceptos de capa física, enlace de datos y protocolos TCP/IP, con la finalidad de construir soluciones IoT robustas orientadas a entornos inteligentes y tecnologías disruptivas.

---

## 🎯 2. Objetivos Específicos

* **Comprender** los principios de la capa física y de enlace en Ethernet, analizando rigurosamente la configuración de la interfaz SPI y el direccionamiento MAC.
* **Implementar** y validar una aplicación embebida IoT que despliegue comunicación TCP/IP, como HTTP o MQTT, directamente sobre el módulo Ethernet en red local.
* **Explicar** el principio fundamental de funcionamiento de la tecnología LoRa y su rol estratégico dentro de las arquitecturas complejas de sistemas inteligentes.
* **Instruir** paso a paso en la configuración física del hardware y la instalación de dependencias de software, garantizando la total reproducibilidad técnica.
* **Incluir** ejemplos de código exhaustivamente comentados y los resultados de prueba obtenidos para evidenciar la estabilidad operativa del sistema de control de actuadores.

---

## 🚀 3. Competencias

* **Diseño de Infraestructura Física de Red:** Fabricación y ponchado de cables UTP bajo la norma T568B para asegurar una óptima continuidad eléctrica.
* **Integración Hardware-Software Embebido:** Interconexión del controlador Ethernet ENC28J60 mediante el bus SPI para gestionar pines de entrada/salida y direccionamiento físico.
* **Desarrollo de Servicios de Red IoT:** Programación de un servidor web embebido para procesar peticiones HTTP GET y manipular actuadores.
* **Evaluación y Diagnóstico de Redes:** Resolución de fallos en la capa física y de red empleando pruebas de continuidad y herramientas de terminal.
* **Criterio Profesional y Ética en IoT:** Evaluación integral de métricas de rendimiento, latencia y prevención de vulnerabilidades de seguridad en tráfico no cifrado.

---

## 📑 4. Tabla de Contenidos

1. [Objetivo General](#-1-objetivo-general)
2. [Objetivos Específicos](#-2-objetivos-específicos)
3. [Competencias](#-3-competencias)
4. [Tabla de Contenidos](#-4-tabla-de-contenidos)
5. [Descripción](#-5-descripción)
6. [Requisitos](#-6-requisitos)
7. [Instalación y Configuración](#-7-instalación-y-configuración)
8. [Conexiones de Hardware](#-8-conexiones-de-hardware)
9. [Parámetros Técnicos del ENC28J60](#-9-parámetros-técnicos-del-enc28j60)
10. [Uso y ejemplos de Código](#-10-uso-y-ejemplos-de-código)
11. [Resultados de prueba](#-11-resultados-de-prueba)
12. [Consideraciones Éticas y de Seguridad](#-12-consideraciones-éticas-y-de-seguridad)
13. [Solución de Problemas](#-13-solución-de-problemas)
14. [Contribuciones](#-14-contribuciones)
15. [Referencias](#-15-referencias)

---

## 📝 5. Descripción

En el ámbito de IoT y ciudades inteligentes, la red Ethernet representa una infraestructura cableada indispensable por su determinismo, inmunidad a interferencias electromagnéticas y alta disponibilidad operativa. Esta práctica contextualiza la integración del chip ENC28J60 con un microcontrolador para desplegar un servidor web local enfocado en el puerto TCP 80. A través de esta implementación, se habilitan comandos remotos para controlar cargas físicas y emitir interfaces dinámicas, consolidando nodos inmunes al ruido electromagnético.

---

## 🛠️ 6. Requisitos

### Hardware necesario:
* Computadora o laptop.
* Arduino UNO o ESP32.
* Módulo Ethernet ENC28J60.
* Protoboard, LED y Resistencia.
* Cable UTP categoría 5e o 6, Conectores RJ45 y Pinzas ponchadoras.
* Probador de continuidad RJ45 y Router.

### Software y bibliotecas requeridas:
* Arduino IDE y Monitor Serial.
* Biblioteca UIPEthernet para establecer comunicación TCP/IP.
* Navegador web para acceder al servidor local.
* Herramientas de diagnóstico de red del sistema operativo.

### Conocimientos previos imprescindibles:
* Fundamentos de redes Ethernet, Modelo TCP/IP y Direccionamiento IP.
* Cableado estructurado (norma T568B) y comunicación SPI.
* Programación básica en C/C++ para configuración de E/S digitales.
* Conceptos de protocolos HTTP y estructura básica de código HTML.

---

## ⚙️ 7. Instalación y Configuración

1. **Clonar el repositorio:** Descarga el código fuente del servidor web ejecutando el comando de clonación remoto directamente en tu terminal.
2. **Instalar dependencias:** Añade la biblioteca UIPEthernet desde el gestor de librerías para controlar correctamente la pila TCP/IP del módulo.
3. **Configurar credenciales de red:** Ajusta la variable correspondiente a la IP estática para alinearse de forma precisa con tu subred de pruebas.
4. **Validar pines lógicos:** Asegúrate de que la constante asignada al Chip Select apunte al pin de hardware correcto de tu placa de desarrollo.
5. **Establecer enlace local:** Asigna manualmente una dirección IP estática en la interfaz de tu computadora para ejecutar pruebas directas punto a punto.

---

## 🔌 8. Conexiones de Hardware

| Señal del módulo | Pin de la placa | Función |
| :--- | :--- | :--- |
| **VCC** | 3.3V | Alimentación de energía principal (estrictamente 3.3V). |
| **GND** | GND | Referencia de tierra común del circuito. |
| **CS/NSS** | 5 | Selección de Chip (Chip Select). |
| **SI/MOSI** | 23 | Entrada de datos (Master Out Slave In). |
| **SO/MISO** | 19 | Salida de datos (Master In Slave Out). |
| **SCK/CLK** | 18 | Señal de reloj para sincronización del bus SPI. |

---

## 📊 9. Parámetros Técnicos del ENC28J60

| Parámetro | Valor típico | Unidad de medida |
| :--- | :--- | :--- |
| **Voltaje de operación** | 3.3 a 3.6 | Voltios (V). |
| **Corriente de transmisión** | 160 a 180 | Miliamperios (mA). |
| **Interfaz** | SPI | Frecuencia de reloj de hasta 20MHz. |
| **Velocidad de red** | 10 | Mbps. |

---

## 💻 10. Uso y ejemplos de Código

El código fuente de este proyecto debe insertarse directamente en el entorno de desarrollo seleccionado, asegurando comentar cada bloque lógico para describir su finalidad de forma clara. Esto incluye documentar detalladamente la declaración de variables de red, la inicialización del bus SPI y el procesamiento de peticiones HTTP en texto plano. Siguiendo estrictamente las directivas de documentación, no se incluirán fragmentos sueltos, manteniéndolos integrados de forma estructurada en los archivos principales.

---

## 📈 11. Resultados de prueba

Para documentar los resultados de las pruebas finales, se requiere integrar fotografías de todo el procedimiento individual y del circuito ensamblado físicamente en el protoboard. Además, deberás complementar esta documentación visual con capturas de pantalla del navegador web y proporcionar la evidencia gráfica del resultado final del sistema. Esto comprobará el acceso estable a la interfaz HTML y demostrará la correcta interacción del hardware con las órdenes remotas emitidas localmente.

---

## 🔐 12. Consideraciones Éticas y de Seguridad

* **Privacidad de datos:** Evitar a toda costa transmitir o almacenar información personal innecesaria mediante el servidor web Ethernet implementado.
* **Exposición de la red:** El servidor de esta práctica debe restringirse a una red local controlada, evitando su exposición directa a conexiones externas de Internet.
* **Vulnerabilidades del actuador:** Un servidor embebido sin métodos de autenticación permite que cualquier usuario en la red manipule el hardware; es crucial implementar mitigaciones.
* **Validación de peticiones:** Es indispensable validar las solicitudes HTTP recibidas antes de ejecutar las acciones eléctricas sobre los dispositivos físicos conectados.

---

## 🛠️ 13. Solución de Problemas

| Fallo común | Estrategia de diagnóstico y resolución |
| :--- | :--- |
| **Problemas de conectividad en la capa física.** | Verificar la continuidad de los conectores RJ45 utilizando una herramienta especializada para confirmar el estándar T568B. |
| **El módulo no establece el enlace SPI.** | Auditar la conexión del bus revisando pines sueltos y el comportamiento de los indicadores LED de estado integrados en el hardware. |
| **Interferencia por conflictos de dirección IP.** | Analizar la subred asignada y emplear comandos de terminal como `ping` y `arp` para asegurar que no existan colisiones locales. |

---

## 🤝 14. Contribuciones

Para aportar mejoras a este repositorio colaborativo, el flujo de trabajo inicia obligatoriamente realizando un *fork* directo hacia tu cuenta personal de desarrollo. Seguidamente, debes crear ramas independientes aplicando convenciones de nombres claras y descriptivas para cada característica nueva, mejora visual o corrección de fallos. Una vez finalizados y probados los cambios localmente, procede con la apertura de un *pull request* detallado para permitir la correcta revisión e integración de tu código.

---

## 📚 15. Referencias

* Microchip Technology Inc. (2009). *ENC28J60 data sheet (DS39625)*. Microchip Technology Inc.
* Espressif Systems Co., Ltd. (2020). *ESP32 technical reference manual*. Espressif Systems.
* IEEE Standards Association. (2018). *IEEE Std 802.3-2018: IEEE Standard for Ethernet*. IEEE.
* Tretkowski, N. (2017). *UIPEthernet: ENC28J60 Ethernet Library for Arduino*. GitHub.
