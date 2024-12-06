#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS =4;
char keys [FILAS] [COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas [FILAS] = {9,8,7,6};
byte pinesColumnas [COLUMNAS] ={5,4,3,2};

Keypad teclado = Keypad (makeKeymap(keys),pinesFilas, pinesColumnas,FILAS,COLUMNAS);

char TECLA;
char CLAVE [7];
char CLAVE_MAESTRA [7] = "123456"; 
byte INDICE = 0;   

int LED_VERDE = 11;
int LED_ROJO = 12;

void setup () {
  Serial.begin(9600);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}

void loop () {
  TECLA = teclado.getKey();
  if (TECLA) {    
    CLAVE [INDICE] = TECLA ;
    INDICE++;
    Serial.print (TECLA);
  }
  if (INDICE==6){
    if (!strcmp (CLAVE, CLAVE_MAESTRA))
    //Serial.println (" Correcta"), delay (2000), INDICE =0;
    Serial.println (" Correcta"), digitalWrite (LED_VERDE, HIGH),delay (2000), INDICE =0, digitalWrite (LED_VERDE,LOW);
    else
    //Serial.println  (" Incorrecta"), delay (2000), INDICE = 0;
    Serial.println  (" Incorrecta"), digitalWrite (LED_ROJO,HIGH),delay (2000), INDICE = 0, digitalWrite (LED_ROJO,LOW);
  }
}
