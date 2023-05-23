#include <Robolito_2_0.h>

Robolito Bolt; //Cria o objeto Bolt do tipo Robolito

void setup(){
  Bolt.Iniciar();//Inicia o Robô

  Bolt.Led(1, CRGB::Red);
}
void loop(){
   Bolt.Led(2, CRGB::DeepPink);//Liga o led 2 com a cor ROSA PROFUNDO
   Bolt.Espera(1);//Espera 1 segundo com o LED 2 na cor ROSA PROFUNDO 
   Bolt.Led(2, 0x00FFFF);//Espera 1 segundo com o LED 2 na cor AZUL CIANO
   Bolt.Espera(1);//Espera 1 segundo com o LED 2 na cor AZUL CIANO
}