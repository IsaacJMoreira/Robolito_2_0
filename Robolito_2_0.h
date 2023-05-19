/*************************************************************
  
   ####    ###   ####    ###   #       ###   #####   ###   #
   #   #  #   #  #   #  #   #  #        #      #    #   #  #
   #####  #   #  #   #  #   #  #        #      #    #   #  #  
   ##     #   #  ####   #   #  #        #      #    #   #  #
   # #    #   #  #   #  #   #  #        #      #    #   #  #
   #  #   #   #  #   #  #   #  #        #      #    #   #        
   #   #   ###   ####    ###   #####   ###     #     ###   #    

***************************************************************
POR ISAAC JERÔNIMO MOREIRA

VER. 1.1
19 de Janeiro de 2023

*/


#ifndef Rblt
#define Rblt

#if (ARDUINO > 100)
  #include "Arduino.h"
#else
  #include "Wprogram.h"
#endif

#include <FastLED.h>

 
//Todos os defies necessários

//Defines dos pinos

//Pino do LED
#define LEDs 25 //Pino onde todos os outros NeoPixels se conectam

//Pinos para o motor esquerdo
#define MotorEsquerdoP0        12 //PIN 12
#define MotorEsquerdoP1        13 //PIN 13

//pinos para do motor direito
#define MotorDireitoP0         14 //PIN 8
#define MotorDireitoP1         15 //PIN 9


//Pinos para o controle do sensor de ultrasom
#define SensorUltrasom    27
#define LedUltrasom       26 

//Pinos para os sensores Infravermelhos

#define SensorIREsquerdo          39
#define SensorIRDireito           36

//Defines para melhor entendimento e escrita do código

//Controle do motor
#define Para_Frente true 
#define Para_Tras   false

//Controle de sensores IR
#define BRANCO LOW
#define PRETO  HIGH

//


//Criação da Classe Robolito
class Robolito{

  public:

 //Variáveis globais
 

 //Essa classe não precisa de contrutor
  void Iniciar();//inicia todos os pinos usados para controlar o robolito;

  void Led(int NeoPixel, CRGB myRGBcolor);//Liga a luzinha amarela 
  void LedOlhos(int NeoPixel, CRGB myRGBColor);
  
  void LigaMotorEsquerdo(bool direcao, int velocidade);//Liga o motor esquerdo, na direção determinada pelo 
                                                      //usuário e na velocidade determinada pelo usuário
  void DesligaMotorEsquerdo();//Desliga o motor esquerdo. 
  
  void LigaMotorDireito(bool direcao, int velocidade); //Liga o motor direito, na direção determinada pelo 
                                                       //usuário e na velocidade determinada pelo usuário
  void DesligaMotorDireito();//Desliga o motor direito.

  void Espera(float tempo);//Espera quantos segundo o usuário mandar

  long MedeDistancia();//Mede a distância entre o sensor do Robolito e retorna o valor em centímetros

  int OlhoDireitoEnxerga();
  int OlhoEsquerdoEnxerga();
   
  private:

  //Variáveis privadas

  //Variáveis para guardar o estado de funcionamento das rodas, assim como a direção de rotação.

  
  //Metodos Privados

 
};


#endif
