// Pines de LEDs
const int ledArriba = 8;
const int ledAbajo = 10;
const int ledIzquierda = 11;
const int ledDerecha = 9;
const int ledPulsacion = 12;

const int VRx = A0; // Eje X
const int VRy = A1; // Eje Y
const int SW = 6;   // Botón del joystick

void setup() {
  pinMode(ledArriba, OUTPUT);
  pinMode(ledAbajo, OUTPUT);
  pinMode(ledIzquierda, OUTPUT);
  pinMode(ledDerecha, OUTPUT);
  pinMode(ledPulsacion, OUTPUT);

  // Configurar pin del botón como entrada con pull-up interno
  pinMode(SW, INPUT_PULLUP);

  // Iniciar comunicación serial para depuración
  Serial.begin(9600);
}

void loop() {
  // Leer valores analógicos del joystick
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  int buttonState = digitalRead(SW); // Leer estado del botón

  // Apagar todos los LEDs
  digitalWrite(ledArriba, LOW);
  digitalWrite(ledAbajo, LOW);
  digitalWrite(ledIzquierda, LOW);
  digitalWrite(ledDerecha, LOW);
  digitalWrite(ledPulsacion, LOW);

  // Encender el LED correspondiente según la dirección
  if (yValue > 700) { // Arriba
    digitalWrite(ledArriba, HIGH);
  } else if (yValue < 300) { // Abajo
    digitalWrite(ledAbajo, HIGH);
  }

  if (xValue > 700) { // Derecha
    digitalWrite(ledDerecha, HIGH);
  } else if (xValue < 300) { // Izquierda
    digitalWrite(ledIzquierda, HIGH);
  }

  // Encender el LED de pulsación si el botón está presionado
  if (buttonState == LOW) { // Botón presionado
    digitalWrite(ledPulsacion, HIGH);
  }

  // Mostrar valores en el monitor serial
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Botón: ");
  Serial.println(buttonState == LOW ? "Presionado" : "No presionado");

  delay(50); // Pequeño retardo para estabilidad
}
