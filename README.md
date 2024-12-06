# LOY_3erParcial
Códigos de Arduino 

DOCUMENTACION DE CODIGOS
--------------------------------------------------------------------------
1. Código de teclado matricial con verificación de clave
Descripción
El código utiliza un teclado matricial para ingresar una clave numérica que se compara con una clave maestra predefinida. Un LED verde indica si la clave es correcta y un LED rojo si es incorrecta.

Componentes
Teclado matricial 4x4.
LED verde y LED rojo.
Funcionamiento
Configura un teclado matricial con pines definidos.
Lee las teclas ingresadas y las almacena en un array CLAVE.
Compara la clave ingresada con la clave maestra:
Si coincide, enciende el LED verde por 2 segundos.
Si no coincide, enciende el LED rojo por 2 segundos.
Aplicaciones
Sistemas básicos de seguridad.
Verificación de contraseñas.
-----------------------------------------------------------------------------
2. Control de LEDs mediante un joystick
Descripción
El código controla cinco LEDs mediante un joystick. Los LEDs indican las direcciones (arriba, abajo, izquierda, derecha) y la pulsación del botón del joystick.

Componentes
Joystick con eje X, eje Y, y botón pulsador.
Cinco LEDs.
Funcionamiento
Lee las posiciones del joystick (ejes X e Y) y el estado del botón.
Enciende un LED según la dirección:
Arriba: Y > 700.
Abajo: Y < 300.
Izquierda: X < 300.
Derecha: X > 700.
Enciende un LED adicional si el botón está presionado.
Aplicaciones
Interfaces de usuario con joystick.
Control de dispositivos o vehículos.
----------------------------------------------------------------------------
3. Generador de números aleatorios con visualización en LEDs
Descripción
Genera números aleatorios del 1 al 6 (como un dado electrónico) y los muestra en LEDs usando un patrón de segmentos similar a un display de 7 segmentos. El sistema se detiene o reanuda con un pulsador.

Componentes
8 LEDs.
Un pulsador.
Funcionamiento
Genera números aleatorios del 1 al 6.
Enciende LEDs según el patrón del número generado (matriz numero).
El pulsador alterna entre iniciar y detener el cambio de números.
Aplicaciones
Simulación de dados electrónicos.
Juegos de azar o educativos.
----------------------------------------------------------------------------
4. Control de un LED RGB mediante botones
Descripción
Controla un LED RGB mediante tres botones, encendiendo uno de los colores (rojo, verde o azul) dependiendo del botón presionado.

Componentes
LED RGB con cátodo común.
Tres botones.
Funcionamiento
Cada botón controla un color del LED:
Botón 1: Rojo.
Botón 2: Verde.
Botón 3: Azul.
Si no hay botones presionados, el LED permanece apagado.
Aplicaciones
Indicadores luminosos.
Interfaces de usuario básicas con control de colores.
--------------------------------------------------------------------------
5. Control de tapa con sensor ultrasónico, LEDs y servo
Descripción general
Este programa utiliza un sensor ultrasónico, LEDs y un servomotor para detectar objetos a corta distancia (≤5 cm). Si un objeto se acerca al sensor, el servomotor abre una tapa simulada, y los LEDs cambian de color para indicar el estado del sistema.
Componentes necesarios
Sensor ultrasónico HC-SR04:
TrigPin: Emite el pulso ultrasónico.
EchoPin: Recibe el eco del pulso reflejado por el objeto.
LEDs:
LED rojo (ledRed): Indica el estado inactivo o tapa cerrada.
LED verde (ledGreen): Indica el estado activo o tapa abierta.
Servomotor:
Conectado al pin 3 para abrir y cerrar la tapa.
Microcontrolador (Arduino).
Fuente de alimentación adecuada.
Inicialización (setup):

Configura los pines de entrada/salida.
Inicializa el servomotor en posición cerrada (0°).
Enciende el LED rojo para indicar que el sistema está listo.
Ciclo principal (loop):

Medición de distancia:
Envía un pulso ultrasónico desde el pin trigPin.
Calcula el tiempo de retorno del eco desde el pin echoPin para determinar la distancia al objeto.
Lógica de control:
Si un objeto está a ≤5 cm:
Cambia al LED verde.
Abre la tapa (gira el servomotor a 70°).
Espera 3 segundos.
Cierra la tapa (gira el servomotor a 0°).
Restaura el estado al LED rojo.
Si no hay objeto cercano, permanece inactivo.
Reporte serial:

Imprime la distancia medida en centímetros y mensajes como "Abriendo" o "Cerrando" para depuración.
---------------------------------------------------------------------------
6. Reproductor de melodías con control por pulsador(Zumbador)
Descripción general
Este programa permite reproducir dos melodías predefinidas mediante un pulsador. Cada pulsación cambia el estado del sistema:

Estado inicial: Sistema inactivo.
Primer estado: Reproduce la Melodía 2.
Segundo estado: Reproduce la Melodía 1.
Tercer estado: Reinicia y vuelve al estado inicial.
Componentes necesarios
Microcontrolador (Arduino).
Zumbador activo o pasivo:
Conectado al pin digital 10 para emitir las notas.
Pulsador:
Conectado al pin digital 2, configurado con resistencia pull-up interna.
Fuente de alimentación adecuada.
Funcionamiento del programa
Definición de notas musicales (pitches.h):

Contiene las frecuencias de las notas musicales usadas para generar sonidos en el zumbador.
Configuración inicial (setup):

Configura el pulsador como entrada con resistencia pull-up.
Configura el zumbador como salida.
Ciclo principal (loop):

Debounce del pulsador:
Detecta cambios de estado del pulsador usando un retardo mínimo para evitar lecturas erróneas.
Estados del contador:
Estado 1 (contador = 1):
Reproduce la Melodía 2, definida en los arreglos melodia2 y duracion_nota2.
Estado 2 (contador = 2):
Reproduce la Melodía 1, definida en los arreglos melodia1 y duracion_nota1.
Estado 3 (contador = 3):
Reinicia el contador y detiene cualquier sonido en reproducción (noTone).
Control de reproducción:

Cada nota tiene una frecuencia y duración específica.
Se usa la función tone(pin, frecuencia, duracion) para generar los tonos en el zumbador.
El intervalo entre notas se ajusta dinámicamente en base a la duración de la nota previa.

