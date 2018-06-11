#include "Ultrasonic.h"
#define echoPin 10 //Pino 10 recebe o pulso do echo
#define trigPin 9 //Pino 9 envia o pulso para gerar o echo
int inPin = 2;
int Motor_E1 = 8;
int Motor_E2 = 7;
int Motor_EV = 6;
int Motor_DV = 5;
int Motor_D2 = 4;
int Motor_D1 = 3;
int x=1;
//inicialização do ultrassonico
Ultrasonic ultrasonic(9,10);
void setup(){
    //pinos do ultrassonico
    pinMode(inPin, INPUT);
    pinMode(echoPin, INPUT); // define o pino 10 como entrada (recebe)
    pinMode(trigPin, OUTPUT);
    //pinos da ponte H
    pinMode(Motor_E1, OUTPUT);
    pinMode(Motor_E2, OUTPUT);
    pinMode(Motor_EV, OUTPUT);
    pinMode(Motor_DV, OUTPUT);
    pinMode(Motor_D2, OUTPUT);
    pinMode(Motor_D1, OUTPUT);
    //espera inicial para colocar o carrinho na pista
    delay(10000);
}
void loop(){
  //função de achar a linha
  /*ela vai setar os motores para fazer o carro rotacionar no proprio eixo*/
  if(digitalRead(inPin)!= LOW){
    //Esse laço vai prender o carro na configuração de rotacionar até ele achar a linha
    while(digitalRead(inPin)!=LOW){
      digitalWrite(Motor_D1,LOW);
      digitalWrite(Motor_D2,HIGH);
      digitalWrite(Motor_E1,LOW);
      digitalWrite(Motor_E2,LOW);
      analogWrite(Motor_EV,50);
      analogWrite(Motor_DV,50);
    }
    //Assim que o carrinho achar o preto, o laço acima para e o carrinho é setado com as configurações de freio dos motores
    digitalWrite(Motor_D1,HIGH);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,HIGH);
    digitalWrite(Motor_E2,HIGH);
    delay(500);
 
  }
  while(x){
      //teste da distancia do objeto
      if(distancia()<=20){
        desvia();
      }
      /*os laços while a seguir faram o carro andar um milisegundo com uma roda para frente com a outra em ponto morto
      e outro milisegundo com uma roda mais veloz para frente e a outra com uma velocidade mais baixa, para traz para evitar que
      o "S" que o carro faz seja muito brusco, alternadamente, isso faz o carinho alternar entre a borda esquerda 
      e direita da fita preta */
      while(digitalRead(inPin)==LOW){
        digitalWrite(Motor_D1,LOW);
        digitalWrite(Motor_D2,HIGH);
        digitalWrite(Motor_E1,HIGH);
        digitalWrite(Motor_E2,LOW);
        analogWrite(Motor_DV,122);
        analogWrite(Motor_EV,85);
        delay(1);
        digitalWrite(Motor_E1,LOW);
        digitalWrite(Motor_E2,LOW);
        digitalWrite(Motor_D1,LOW);
        digitalWrite(Motor_D2,HIGH);
        analogWrite(Motor_DV,122);
        delay(1);
      }
        while(digitalRead(inPin)==HIGH){
          digitalWrite(Motor_D1,HIGH);
          digitalWrite(Motor_D2,LOW);
          digitalWrite(Motor_E1,LOW);
          digitalWrite(Motor_E2,HIGH);
          analogWrite(Motor_DV,107);
          analogWrite(Motor_EV,100);
          delay(1);
          digitalWrite(Motor_D1,LOW);
          digitalWrite(Motor_D2,LOW);
          digitalWrite(Motor_E1,LOW);
          digitalWrite(Motor_E2,HIGH);
          analogWrite(Motor_EV,100);
          delay(1);
         }
     
         
         while(digitalRead(inPin)==LOW){
          digitalWrite(Motor_D1,HIGH);
          digitalWrite(Motor_D2,LOW);
          digitalWrite(Motor_E1,LOW);
          digitalWrite(Motor_E2,HIGH);
          analogWrite(Motor_EV,100);
          analogWrite(Motor_DV,107);
          delay(1);
          digitalWrite(Motor_D1,LOW);
          digitalWrite(Motor_D2,LOW);
          digitalWrite(Motor_E1,LOW);
          digitalWrite(Motor_E2,HIGH);
          analogWrite(Motor_EV,100);
          delay(1);
         }
       
         while(digitalRead(inPin)==HIGH){
          digitalWrite(Motor_D1,LOW);
          digitalWrite(Motor_D2,HIGH);
          digitalWrite(Motor_E1,HIGH);
          digitalWrite(Motor_E2,LOW);
          analogWrite(Motor_DV,122);
          analogWrite(Motor_EV,85);
          delay(1);
          digitalWrite(Motor_E1,LOW);
          digitalWrite(Motor_E2,LOW);
          digitalWrite(Motor_D1,LOW);
          digitalWrite(Motor_D2,HIGH);
          analogWrite(Motor_DV,122);
          delay(1);
         }
    }
  }
 
void desvia(){  
 
 //freia
   digitalWrite(Motor_D1,HIGH);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,HIGH);
    digitalWrite(Motor_E2,HIGH);
    delay(500);
    //gira
    digitalWrite(Motor_D1,LOW);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,LOW);
    digitalWrite(Motor_E2,LOW);
    analogWrite(Motor_DV,122);
    delay(300);
    //freia
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(500);
   
    //vai reto
   digitalWrite(Motor_D1,LOW);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,LOW);
   digitalWrite(Motor_E2,HIGH);
   analogWrite(Motor_EV,100);
   analogWrite(Motor_DV,122);
   delay(500);
   //freia
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(500);
 
    //gira
   digitalWrite(Motor_D1,LOW);
   digitalWrite(Motor_D2,LOW);
   digitalWrite(Motor_E1,LOW);
   digitalWrite(Motor_E2,HIGH);
   analogWrite(Motor_EV,100);
   delay(600);
   //freia
   digitalWrite(Motor_D1,HIGH);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,HIGH);
    digitalWrite(Motor_E2,HIGH);
    delay(500);
   //segue reto
   digitalWrite(Motor_D1,LOW);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,LOW);
   digitalWrite(Motor_E2,HIGH);
   analogWrite(Motor_EV,100);
   analogWrite(Motor_DV,122);
   delay(400);
   //freio
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(500);
   //gira
   digitalWrite(Motor_D1,LOW);
   digitalWrite(Motor_D2,LOW);
   digitalWrite(Motor_E1,LOW);
   digitalWrite(Motor_E2,HIGH);
   analogWrite(Motor_EV,100);
   delay(500);
 
   //freia
   digitalWrite(Motor_D1,HIGH);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,HIGH);
    digitalWrite(Motor_E2,HIGH);
    delay(500);
  //esse laço prende o carro nas configuração de ir em linha reta até ele achar a linha preta
  while(digitalRead(inPin)==HIGH){
   //segue reto
   digitalWrite(Motor_D1,LOW);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,LOW);
   digitalWrite(Motor_E2,HIGH);
   analogWrite(Motor_EV,100);
   analogWrite(Motor_DV,122);
   delay(15);
   //freio para impedir que o carro ganhe muita velocidade
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(10);
  }
     //freia
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(500);
   // seta carro para da uma pequena ré para ajustar a horientação do carro após ele achar a linha
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,LOW);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,LOW);
   analogWrite(Motor_DV,122);
   delay(150);
    //freia
   digitalWrite(Motor_D1,HIGH);
   digitalWrite(Motor_D2,HIGH);
   digitalWrite(Motor_E1,HIGH);
   digitalWrite(Motor_E2,HIGH);
   delay(500);
   
   //gira
    digitalWrite(Motor_D1,LOW);
    digitalWrite(Motor_D2,HIGH);
    digitalWrite(Motor_E1,LOW);
    digitalWrite(Motor_E2,LOW);
    analogWrite(Motor_DV,122);
    delay(750);
}
int distancia(){
  //função que mede a distancia ate o objeto
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  int aux=(ultrasonic.Ranging(CM));
  return aux;
}
