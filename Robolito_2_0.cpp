                                                                                                   
#include "Robolito.h"//O Header inclui as bibliotecas Servo.h e Ultrasound.h

CRGB leds[4];//cria o objeto para controle dos LEDs RGB no assoalho do robô
CRGB ledCabeca[6];//cria o objeto para controle dos LEDs da cabeça do robô

void Robolito::Iniciar(){

  //Define todos os pinos usados no Robolito
  Serial.begin(115200);//Usado em todo o código para passar informações direto para o computador
  FastLED.addLeds<WS2812, LEDs, GRB>(leds, 4);//Configura o objeto para que consiga
  FastLED.setBrightness(255);//Inicia setando o brilho máximo para 255. 
  FastLED.addLeds<WS2812, LedUltrasom, GRB>(ledCabeca, 6);//Configura o objeto para que consiga
  FastLED.setBrightness(255);//Inicia setando o brilho máximo para 255. 
  
  for (int i = 12; i <= 15; i++) { 
    ledcSetup(i, 255, 8);//Transforma estes pinos em saídas analógicas com resolução 8 bits e frequencia 255          
    ledcAttachPin(i, i);           
  }                      
  delay(10);
  Serial.println("*****************************************************************");
  Serial.println("*                                                               *");
  Serial.println("*   RRRR    OOO   BBBB    OOO   L       III   TTTTT   OOO   !!  *");
  Serial.println("*   R   R  O   O  B   B  O   O  L        I      T    O   O  !!  *");
  Serial.println("*   RRRRR  O   O  B   B  O   O  L        I      T    O   O  !!  *");
  Serial.println("*   RR     O   O  BBBB   O   O  L        I      T    O   O  !!  *");
  Serial.println("*   R R    O   O  B   B  O   O  L        I      T    O   O  !!  *");
  Serial.println("*   R  R   O   O  B   B  O   O  L        I      T    O   O      *");
  Serial.println("*   R   R   OOO   BBBB    OOO   LLLLL   III     T     OOO   !!  *");
  Serial.println("*                                                               *");
  Serial.println("*****************************************************************");
  Serial.println("Por: ISAAC MOREIRA");
  Serial.println("VER. 2.0 - MAIO DE 2023");
  Serial.println();

  //configura todos os pinos
   
  pinMode(SensorIREsquerdo, INPUT);
  pinMode(SensorIRDireito, INPUT);
   
  
 /*DEBUG*/

  //Dá uma leve mexida nas rodinhas pra testar os motores
  Robolito::LigaMotorEsquerdo(Para_Frente, 100);
  Robolito::LigaMotorDireito(Para_Tras, 100);
  Robolito::Espera(0.1);
  Robolito::LigaMotorEsquerdo(Para_Tras, 100);
  Robolito::LigaMotorDireito(Para_Frente, 100);
  Robolito::Espera(0.1);
  Robolito::DesligaMotorEsquerdo();
  Robolito::DesligaMotorDireito();

  Robolito::MedeDistancia();
  Robolito::OlhoEsquerdoEnxerga();
  Robolito::OlhoDireitoEnxerga();

  Robolito::Espera(0.5);
  Serial.println("****************************************");
  Serial.println("*   Robolito iniciado com sucesso!!!   *");
  Serial.println("****************************************");
  //Inicia as interrupções
}

//Tradução entre a função delay e a sua versão em português
void Robolito::Espera(float tempo){
  Serial.print("Eu vou esperar ");
  Serial.print(tempo);
  Serial.println(" segundos sem fazer mais nada.");
  delay(1000 * tempo);//converte se segundos para milesegundos
  Serial.print("Pronto!");
  Serial.println("");
}

//Funções para controlar o led da placa, ligado ao pino 13, como em todo arduino.
void Robolito::Led(int NeoPixel, CRGB myRGBColor){
  leds[NeoPixel-1] = myRGBColor;
  Serial.print("Alterei a cor do RGB");
  Serial.print(NeoPixel -1);
  Serial.println(".");
  FastLED.show();
}

void Robolito::LedOlhos(int NeoPixel, CRGB myRGBColor){
  ledCabeca[NeoPixel-1] = myRGBColor;
  Serial.print("Alterei a cor do RGB");
  Serial.print(NeoPixel -1);
  Serial.println(" dos olhos.");
  FastLED.show();
}

//funções para mover os motores 

void Robolito::LigaMotorEsquerdo(bool direcao, int velocidade){   //especificamente para o motor esquerdo
  Serial.print("Eu liguei meu motor ESQUERDO ");


  if(direcao){//se está indo para frente (ver os defines)
    ledcWrite(MotorEsquerdoP0, 0);
    ledcWrite(MotorEsquerdoP1, velocidade);  
    Serial.print("para FRENTE com "); 
  }else{
      ledcWrite(MotorEsquerdoP0, velocidade);
      ledcWrite(MotorEsquerdoP1, 0);
      Serial.print("para TRAS com velocidade:"); 
    }

    Serial.print(velocidade);
    Serial.println(".");  
}  


  void Robolito::DesligaMotorEsquerdo(){ 
    ledcWrite(MotorEsquerdoP0, 0);
    ledcWrite(MotorEsquerdoP1, 0);
    Serial.println("Eu desliguei o motor ESQUERDO.");
  }



void Robolito::LigaMotorDireito(bool direcao, int velocidade){   //especificamente para o motor direito
  Serial.print("Eu liguei meu motor Direito ");


  if(direcao){//se está indo para frente (ver os defines)
    ledcWrite(MotorDireitoP0, 0);
    ledcWrite(MotorDireitoP1, velocidade);  
    Serial.print("para FRENTE com "); 
  }else{
      ledcWrite(MotorDireitoP0, velocidade);
      ledcWrite(MotorDireitoP1, 0);
      Serial.print("para TRAS com velocidade: "); 
    }

    Serial.print(velocidade);
    Serial.println(".");  
}  


  void Robolito::DesligaMotorDireito(){ 
    ledcWrite(MotorDireitoP0, 0);
    ledcWrite(MotorDireitoP1, 0);
    Serial.println("Eu desliguei o motor ESQUERDO.");
  }

//Função para medir a distância do sensor Ultrasom
long Robolito::MedeDistancia(){
  pinMode(SensorUltrasom, OUTPUT);
  digitalWrite(SensorUltrasom, HIGH);
  delayMicroseconds(20);
  digitalWrite(SensorUltrasom, LOW);
  pinMode(SensorUltrasom, INPUT);
  int Time_Echo_us = pulseIn(SensorUltrasom, HIGH);
  long distancia = Time_Echo_us / 58;

  
  Serial.print("Eu vi que tem alguma coisa a ");
  Serial.print(distancia);
  Serial.println("cm da minha cabeca.");

  return distancia;
}

int Robolito::OlhoEsquerdoEnxerga(){
 int enxerguei = digitalRead(SensorIREsquerdo); 

 if(enxerguei)Serial.println("Eu vi algo PRETO no meu olho ESQUERDO.");
 else Serial.println("Eu vi algo BRANCO no meu olho ESQUERDO.");

 return enxerguei;
}

int Robolito::OlhoDireitoEnxerga(){
  int enxerguei = digitalRead(SensorIRDireito); 

  if(enxerguei)Serial.println("Eu vi algo PRETO no meu olho DIREITO.");
  else Serial.println("Eu vi algo BRANCO no meu olho DIREITO.");

  return enxerguei;
}
