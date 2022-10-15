#pragma once
#include "helper.h"
void RobotLine::radionica() {
  static int broj = 0;
  char simbol[10 + sizeof(char)];
  if (setup()) {
    armOpen();
  }
  // ZADATAK: napravite if naredbu da se robot zaustavi nakon što se vrati na početak
  if (broj >= 9) {
    stop(), end();
  }
  if(front()< 120 and broj ==0){
    go(90,-90);
    delayMs(500);
    broj++;
  }
  if(front()< 120 and broj ==1){
    stop();
    delayMs(500);
    go(20,20);
    delayMs(500);
    go(-20,-20);
    delayMs(1500);
    go(90,-90);
    delayMs(500);
    broj++;
  }
  if(broj==1 and lineAny()){
    stop();end();
  }
   
  
  if (front() < 120) {
    go(-90, 90);
    delayMs(500);
    broj++;
  }
  if (rightFront() < leftFront()) {
    if (rightFront() > 120)
      go(80, 20);
    else
      go(20, 80);
  }
  else {
    if (leftFront() > 120)
      go(20, 80);
    else
      go(80, 20);
  }

  sprintf(simbol, "%d", broj);
  display(simbol);
}
