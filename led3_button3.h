#pragma once
#ifndef __LED3_BUTTON3_
#define  __LED3_BUTTON3_
extern "C" {
    #include <stdint.h>
    #include <Arduino.h>
#endif
}
#define B1 3
#define B2 4
#define B3 5
#define WHITE 9
#define RED A0
#define GREEN A1

#define CHECKBLINK(LED1, BUT1, LED2, BUT2) ({if(digitalRead(BUT1) == LOW) { digitalWrite(LED, LOW); break; } \
                                        else if(digitalRead(BUT2) == LOW) { } \
                                        })

#define CHECKRED ({if(digitalRead(B2) == LOW) { \
                            digitalWrite(RED, LOW); \
                            delay(1000); \
                            countR++; \
                            goto BREAK; \
                    } \
                    if(digitalRead(B1) == LOW) { \
                        digitalWrite(WHITE, LOW); \
                        digitalWrite(RED, LOW); \
                        digitalWrite(GREEN, LOW); \
                        delay(1000); \
                        goto WHITE_LABEL; \
                    } \
                    if(digitalRead(B3) == LOW) { \
                        digitalWrite(WHITE, LOW); \
                        digitalWrite(RED, LOW); \
                        digitalWrite(GREEN, LOW); \
                        delay(1000); \
                        goto GREEN_LABEL; \                        
                    } \
                    })

#define CHECKGREEN ({if(digitalRead(B3) == LOW) { \
                            digitalWrite(GREEN, LOW); \
                            delay(1000); \
                            countG++; \
                            goto BREAK; \
                            } \
                    if(digitalRead(B1) == LOW) { \
                        digitalWrite(WHITE, LOW); \
                        digitalWrite(RED, LOW); \
                        digitalWrite(GREEN, LOW); \
                        delay(1000); \
                        goto WHITE_LABEL; \
                    } \
                    if(digitalRead(B2) == LOW) { \
                        digitalWrite(WHITE, LOW); \
                        digitalWrite(RED, LOW); \
                        digitalWrite(GREEN, LOW); \
                        delay(1000); \
                        goto RED_LABEL; \                        
                    } \
                    })
