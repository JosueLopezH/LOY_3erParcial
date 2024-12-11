# LOT_3erParcial
Códigos de Arduino 
----------------------------------------------------------------------
![Imagen de WhatsApp 2024-11-28 a las 09 00 39_1f765229](https://github.com/user-attachments/assets/a42c5bd7-a02c-47fa-8274-690d771511c3)

Código 1: Control de un display de 7 segmentos con números aleatorios
Descripción: Este programa controla un display de 7 segmentos conectado a un microcontrolador como Arduino. Genera un número aleatorio entre 1 y 6, que es representado en el display. Se incluye un pulsador para pausar o reanudar la generación aleatoria.

Funcionamiento:
Definiciones iniciales:
El array numero contiene la configuración de los segmentos del display para cada número del 0 al 9.
Un pulsador conectado al pin 2 se usa para pausar o reanudar la generación de números.
Configuración inicial (setup):

Se configuran los pines 3 a 10 como salidas para controlar los segmentos del display.
Se configura el pin del pulsador como entrada.
Lógica principal (loop):

Se lee el estado del pulsador. Si está presionado, alterna entre detener y reanudar la generación de números.
Si está activo, se genera un número aleatorio entre 1 y 6 cada 50 ms.
Si está detenido, se mantiene el último número en el display.
Control del display:

El array numero indica qué segmentos se deben encender para mostrar un número.
Los valores del array se asignan directamente a los pines correspondientes.
Aplicaciones:

Simulación de un dado electrónico.
Enseñanza de conceptos básicos de electrónica digital.
-----------------------------------------------------------------------------
![Imagen de WhatsApp 2024-11-28 a las 09 49 35_c15482d6](https://github.com/user-attachments/assets/e665b7f8-8a26-42ed-81a9-5d9a4d705d0d)

Código 2: Control de LEDs con un joystick analógico
Descripción: Este programa controla cuatro LEDs (arriba, abajo, izquierda y derecha) y un LED adicional para una pulsación, basado en la posición de un joystick analógico.

Funcionamiento:
Definiciones iniciales:

Se asignan pines para los LEDs y el joystick.
Los ejes X y Y del joystick están conectados a entradas analógicas, y el botón del joystick a un pin digital.
Configuración inicial (setup):

Los pines de los LEDs se configuran como salidas.
El botón del joystick se configura como entrada con un pull-up interno.
Lógica principal (loop):

Se leen los valores analógicos de los ejes X y Y, y el estado del botón.
Según el rango de los valores analógicos:
Se enciende el LED correspondiente a la dirección (arriba, abajo, izquierda o derecha).
Si el botón está presionado, se enciende el LED de pulsación.
Monitorización:

Los valores de los ejes X, Y y el estado del botón se imprimen en el monitor serial para depuración.
Aplicaciones:

Interfaz de usuario para videojuegos o robots.
Aprendizaje de sensores analógicos.
---------------------------------------------------------------------------------
![Imagen de WhatsApp 2024-12-09 a las 19 25 55_4cd40720](https://github.com/user-attachments/assets/8c7a7f7d-6b8f-4920-a7d5-7e4695d7653f)

Código 3: Teclado matricial para ingresar contraseñas
Descripción: Este programa utiliza un teclado matricial de 4x4 para ingresar una contraseña. La contraseña ingresada se compara con una clave maestra predefinida, y se enciende un LED verde si es correcta, o un LED rojo si es incorrecta.

Funcionamiento:
Definiciones iniciales:

Se define el mapeo de teclas y los pines del teclado matricial.
Se establece la clave maestra (CLAVE_MAESTRA).
Configuración inicial (setup):

Se inicializan los LEDs rojo y verde como salidas.
Se configura la comunicación serial para depuración.
Lógica principal (loop):

Se captura la tecla presionada y se almacena en un array.
Cuando se ingresan 6 caracteres, se compara la entrada con la clave maestra:
Si es correcta, se enciende el LED verde por 2 segundos.
Si es incorrecta, se enciende el LED rojo por 2 segundos.
Aplicaciones:

Sistemas básicos de acceso con contraseña.
Ejemplo práctico de lectura de teclados matriciales.
---------------------------------------------------------------------------------
![Imagen de WhatsApp 2024-11-29 a las 08 31 55_b768c48a](https://github.com/user-attachments/assets/5779942a-d43f-42c6-aec4-af10b86225f4)

Código 4: Control de un LED RGB con botones
Descripción: Este programa utiliza tres botones para controlar un LED RGB. Cada botón activa un color primario (rojo, verde o azul).

Funcionamiento:
Definiciones iniciales:

Los pines se asignan a los colores del LED y a los botones correspondientes.
Configuración inicial (setup):

Los pines del LED se configuran como salidas, y los botones como entradas.
Lógica principal (loop):

Se leen los estados de los botones.
Según el botón presionado, se enciende el color correspondiente del LED RGB utilizando analogWrite para controlar la intensidad.
Control de colores:

La función encenderColor permite modular los valores de los canales rojo, verde y azul.
Aplicaciones:

Aprendizaje de LEDs RGB.
Control básico de iluminación.
-----------------------------------------------------------------------------------
![Imagen de WhatsApp 2024-12-09 a las 19 33 52_2ecba203](https://github.com/user-attachments/assets/20dcc3fd-eb36-4400-a13e-859dbec1c971)

Código 5: Sistema Zumbador
En esta exposición impartida por mis compañeros, se utilizó un Zumbador para emitir notas que simulan una alarma.

Código

El código implementa la funcionalidad para reproducir dos melodías diferentes mediante un zumbador conectado al pin 10. Un pulsador conectado al pin 2 permite alternar entre las melodías y reiniciar el estado tras completar ambas.

 Definiciones de notas musicales
Las frecuencias de las notas musicales están definidas en el archivo `pitches.h` y se incluyen en el código principal.

 Funcionalidad del código
Configuración inicial: 
   - El pin 2 está configurado como entrada con resistencia pull-up.
   - El pin 10 está configurado como salida.

   Control por pulsador:
   - Se utiliza un pulsador para alternar entre diferentes estados.
   - Un sistema de debounce asegura que las pulsaciones no generen múltiples acciones no deseadas.

   Reproducción de melodías:
   - Al presionar el pulsador por primera vez, se reproduce la primera melodía.
   - Al presionar el pulsador por segunda vez, se reproduce la segunda melodía.
   - Al presionar el pulsador por tercera vez, se reinicia el estado.

   Reinicio de estado:
Cuando ambas melodías terminan, el contador y los índices de las melodías se reinician.
Materiales
Arduino (modelo sugerido: Uno o compatible).
Zumbador.
Pulsador.
Resistencias para el pulsador (en caso de no usar resistencia pull-up interna).
Cables de conexión.
Biblioteca de definiciones de frecuencias: `pitches.h`.

------------------------------------------------------------------------------
![Imagen de WhatsApp 2024-12-06 a las 08 31 29_cdcaa536](https://github.com/user-attachments/assets/33c33527-241d-4342-9627-a74c04a976ca)

Código 6: Control de una puerta con servomotor
Descripción: Este programa controla un servomotor que simula abrir y cerrar una puerta mediante dos funciones principales (AbrirPuerta y CerrarPuerta).

Funcionamiento:
Definiciones iniciales:

Se configura un servomotor en el pin 3.
Se definen LEDs para indicar el estado de la puerta.
Configuración inicial (setup):

El servomotor se conecta y se inicializa.
Lógica principal (loop):

Las funciones AbrirPuerta y CerrarPuerta:
Mueven el servomotor gradualmente en pequeños pasos para abrir o cerrar la puerta.
Controlan LEDs para mostrar el estado de la puerta.
Aplicaciones:

Simulación de sistemas de acceso controlado.
Demostración de control de servomotores.


