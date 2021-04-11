#include "wiringPi.h" 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void gpio_liga(int pino){
    int w = wiringPiSetup();
    if(w < 0){
        printf("erro ao iniciar wiringPi");
        exit(1);
    }
    printf("%d\n",pino);
    pinMode(pino,OUTPUT);
    digitalWrite(pino, HIGH);
}

void gpio_desliga(int pino){
    int w = wiringPiSetup();
    if(w < 0){
        printf("erro ao iniciar wiringPi");
        exit(1);
    }

    pinMode(pino,OUTPUT);
    digitalWrite(pino, LOW);
}

int ler_gpio(int pino){
    int w = wiringPiSetup();
    if(w < 0){
        printf("erro ao iniciar wiringPi");
        exit(1);
    }

    pinMode(pino,INPUT);
    int responsePin = digitalRead(pino);
    return responsePin;
}