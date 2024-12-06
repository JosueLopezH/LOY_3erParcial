#include <Servo.h>

// Configuración de pines
const int trigPin = 9;
const int echoPin = 10;
const int ledRed = 5;
const int ledGreen = 6;
Servo servo;

// Variables
long duration;
int distance;

void setup() {
  // Inicializar pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  servo.attach(3); // Conectar el servomotor al pin digital 3
  servo.write(0);  // Inicialmente la tapa está cerrada

  // Encender LED rojo al inicio
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);

  Serial.begin(9600);
}

void loop() {
  // Enviar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el pulso de retorno
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convertir a cm
  // Mostrar el valor en el monitor serial
  Serial.print("distancia: ");
  Serial.println(distance);
  // Comportamiento
  if (distance <= 5) { // Si está a menos de 15 cm
    // Apagar LED rojo y encender LED verde
    Serial.println("Abriendo");
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    
    // Abrir la tapa
    servo.write(70);
    delay(3000); // Esperar 3 segundos
    
    // Cerrar la tapa
    servo.write(0);
    
    // Cambiar LEDs de nuevo
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    Serial.println("Cerrando");
  }
  delay(200);
}
