#include <Robolito.h>

Robolito Bolt; //Cria o objeto Bolt do tipo Robolito

void setup(){
  Bolt.Iniciar();//Inicia o Robô

  Bolt.Led(1, CRGB::Red);
}
void loop(){
   Bolt.Led(2, CRGB::Pink);//Liga o led 2 com a cor ROSA
   Bolt.Espera(1);//Espera 1 segundo com o LED 2 na cor ROSA
   Bolt.Led(2, CRGB::Blue);//Espera 1 segundo com o LED 2 na cor AZUL
   Bolt.Espera(1);//Espera 1 segundo com o LED 2 na cor AZUL
}