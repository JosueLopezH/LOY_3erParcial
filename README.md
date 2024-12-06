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
