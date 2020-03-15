/*
* THIS CODE IS TESTED ON ARDUINO NANO
* Arduino file for torch that uses 3 leds :- white, red & green
* and 3 buttons :- B1, B2 & B3
* for using them in 3 modes for white and 2 modes each for red and green leds
* WHITE:
* 1st mode = OFF state
* 2nd mode = 50% intensity
* 3rd mode = 100% intensity
* RED & GREEN:
* 1st mode = OFF state
* 2nd mode = Blink state
* Each Button is specified for each of the leds, if any other button is pressed
* respective led white start from 1st mode.
* Button 1 (B1) : WHITE led
* Button 2 (B2) : RED led
* Button 3 (B3) : GREEN led
* Written by : Kartik Vatsa
*/
#include "led3_button3.h"

int redLastState = LOW;
int prevMillis = 0;
uint32_t countW = 1, countG = 1, countR = 1;
long interval = 500;
long debounceDelay = 50;
long lastdebounceTime = 0;

void blink(int led, int but1, int ledstop1, int but2, int ledstop2, int but3) {
    digitalWrite(ledstop1, LOW);
    digitalWrite(ledstop2, LOW);
    while(1) {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(WHITE, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(B1, INPUT_PULLUP);
    pinMode(B2, INPUT_PULLUP);
    pinMode(B3, INPUT_PULLUP);
}

void loop() {
	int timestamp1 = millis(), timestamp2 = millis(), timestamp3 = millis();
    int readW = digitalRead(B1);
    int readR = digitalRead(B2);
    int readG = digitalRead(B3);
    if(readW == LOW && readR == HIGH && readG == HIGH) {
        WHITE_LABEL:
        analogWrite(WHITE, 100);
        delay(200);
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        while(1) {
            if(digitalRead(B1) == LOW) {
                analogWrite(WHITE, 255);
                delay(200);
                while(1) {
                    if(digitalRead(B1) == LOW) {
                        digitalWrite(WHITE, LOW);
                        delay(400);
                        goto BREAK;
                    }
                    if(digitalRead(B2) == LOW) {
                        goto RED_LABEL;
                    }
                    if(digitalRead(B3) == LOW) {
                        goto GREEN_LABEL;
                    }
                }
            }
            if(digitalRead(B2) == LOW) {
                goto RED_LABEL;
            }
            if(digitalRead(B3) == LOW) {
                goto GREEN_LABEL;
            }
        }
    }
    if(readW == HIGH && readR == LOW && readG == HIGH) {
        countR++;
    }
    if(readW == HIGH && readR == HIGH && readG == LOW) {
        countG++;
    }
    
    if(countR%2 == 0) {
        RED_LABEL:
        delay(300);
        digitalWrite(WHITE, LOW);
        digitalWrite(GREEN, LOW);
        while(1) {
            digitalWrite(RED, HIGH);
            for(int i = 0; i<1000; i++) {
                CHECKRED;
                delay(1);
            }
            digitalWrite(RED, LOW);
            for(int i = 0; i<1000; i++) {
                CHECKRED;
                delay(1);
            }
        }
    }
    if(countG%2 == 0) {
        GREEN_LABEL:
        delay(300);
        digitalWrite(WHITE, LOW);
        digitalWrite(RED, LOW);
        while(1) {
            digitalWrite(GREEN, HIGH);
            for(int i = 0; i<1000; i++) {
                CHECKGREEN;
                delay(1);
            }
            digitalWrite(GREEN, LOW);
            for(int i = 0; i<1000; i++) {
                CHECKGREEN;
                delay(1);
            }
        }
    }
    BREAK: {}
}
