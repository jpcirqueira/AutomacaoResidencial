#include "wiringPi.h" 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void gpio_liga(int pino){
    pinMode(pino,OUTPUT);
    digitalWrite(pino, HIGH);
}

void gpio_desliga(int pino){
    pinMode(pino,OUTPUT);
    digitalWrite(pino, LOW);
}

int ler_gpio(int pino){
    pinMode(pino,INPUT);
    int responsePin = digitalRead(pino);
    return responsePin;
}