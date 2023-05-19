#include "Robolito.h"
#include <FastLED.h>

Robolito Alice;
CRGB CorDoLed(0, 0, 0);

void setup() {
  Alice.Iniciar();     
}

void loop() {
if(!Alice.OlhoDireitoEnxerga() && !Alice.OlhoEsquerdoEnxerga()){
  if(Alice.MedeDistancia() > 10){
      for(int i = 0; i <= 6 ; i++ ){
        Alice.LedOlhos(i, CRGB::White);
      }
    Alice.Led(1, CRGB::Black);
    Alice.Led(2, CRGB::Black);
    Alice.Led(3, CRGB::Green);
    Alice.Led(4, CRGB::Green);
    Alice.LigaMotorDireito(Para_Frente, 255);
    Alice.LigaMotorEsquerdo(Para_Frente, 255);
  }else{
    for(int i = 0; i <= 6 ; i++ ){
        Alice.LedOlhos(i, CRGB::White);
      }
    Alice.LedOlhos(2, CRGB::Red);
    Alice.LedOlhos(6, CRGB::Red);
    Alice.Led(1, CRGB::Red);
    Alice.Led(2, CRGB::Red);
    Alice.Led(3, CRGB::Black);
    Alice.Led(4, CRGB::Black);
    Alice.DesligaMotorDireito();
    Alice.DesligaMotorEsquerdo();
    Alice.Espera(0.1);
    Alice.LigaMotorEsquerdo(Para_Tras, 100);
    Alice.LigaMotorDireito(Para_Tras, 100);
    Alice.Espera(0.3);
    Alice.LigaMotorDireito(Para_Frente, 255);
    Alice.Espera(0.1);
  }
}else{
    Alice.DesligaMotorDireito();
    Alice.DesligaMotorEsquerdo();

    for(int i = 0; i <= 6 ; i++ ){
        Alice.LedOlhos(i, CRGB::Black);
      }

    Alice.Led(1, CRGB::Red);
    Alice.Led(2, CRGB::Red);
    Alice.Led(3, CRGB::Red);
    Alice.Led(4, CRGB::Red);
}

}
