const int pinRojo = 9;  // Pin del LED rojo
const int pinVerde = 10; // Pin del LED verde
const int pinAzul = 11;  // Pin del LED azul

const int botonRojo = 2;  // Pin del botón rojo
const int botonVerde = 3; // Pin del botón verde
const int botonAzul = 4;  // Pin del botón azul

void setup() {
  // Configurar los pines del LED como salida
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  // Configurar los pines de los botones como entrada
  pinMode(botonRojo, INPUT);
  pinMode(botonVerde, INPUT);
  pinMode(botonAzul, INPUT);
}

void loop() {
  // Leer el estado de los botones
  int estadoRojo = digitalRead(botonRojo);
  int estadoVerde = digitalRead(botonVerde);
  int estadoAzul = digitalRead(botonAzul);

  // Controlar el LED según el botón pulsado
  if (estadoRojo == HIGH) {
    encenderColor(255, 0, 0); // Rojo
  } else if (estadoVerde == HIGH) {
    encenderColor(0, 255, 0); // Verde
  } else if (estadoAzul == HIGH) {
    encenderColor(0, 0, 255); // Azul
  } else {
    encenderColor(0, 0, 0); // Apagar el LED
  }
}

// Función para encender el LED con un color específico
void encenderColor(int rojo, int verde, int azul) {
  analogWrite(pinRojo, rojo);
  analogWrite(pinVerde, verde);
  analogWrite(pinAzul, azul);
}
