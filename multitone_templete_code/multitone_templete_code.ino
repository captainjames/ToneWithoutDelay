/* This sample playing a short clip of Haddaway-What is love.
 * Two piezo buzzers is required for this tune.
 * [PIN8]----[+]BUZZER01[-]---\
 *                             |-----[GND]
 * [PIN7]----[+]BUZZER02[-]---/
 * 
 * Code done by James Wang(Lekkon7193) and thanks for everyone's help.
 * Inspired by "Blink without Delay".
 * Use Micros() instead of tone and delay to drive square wave oscillation.
 * Tested by Arduino Uno.(Runs on SPEEEduino Board).
 * Pin7 and Pin8 are outputting two diffrent melodies
 * The LED indicates when the board is playing melodies.
 * PS: IF YOU WANT TO CONTOL SOUND INTENSITY, USE analogWrite() instead of digitalWrite().
 */

#include "note_period.h"
#include "melody8.h"
#include "melody7.h"
#include "note_length.h"
#include "note_length7.h"
const int buzzer_1_Pin =  7; //BUZZER 1 PIN
const int buzzer_2_Pin =  8; //BUZZER 2 PIN
const int ledPin =  13;
int buzzer_1_State = LOW;
int buzzer_2_State = LOW;    
unsigned long previoustime1 = 0; 
unsigned long previoustime2 = 0;
unsigned long previoustime3 = 0;
unsigned long previoustime4 = 0;
unsigned int counter1 = 0 ;
unsigned int counter2 = 0 ;
const int totalnotes_01 = 0; 
/* INDICATE THE NUMBER OF NOTES YOU WANT TO PLAYED ON BUZZER 1. 
 * EXCEED THIS NUMBER MEANLOOP BACK TO START AGAIN.
 * DO NOT PUT NUMBER MORE THAN WHAT YOU HAVE FOR THE NUMBER OF NOTE.
 * BY DOING THAT THE COUNTER CAN GET INTO TROUBLE.
 */
const int totalnotes_02 = 0; 
/* INDICATE THE NUMBER OF NOTES YOU WANT TO PLAYED ON BUZZER 2. 
 * EXCEED THIS NUMBER MEANLOOP BACK TO START AGAIN.
 * DO NOT PUT NUMBER MORE THAN WHAT YOU HAVE FOR THE NUMBER OF NOTE.
 * BY DOING THAT THE COUNTER CAN GET INTO TROUBLE.
 */
void setup() {
  pinMode(buzzer_1_Pin, OUTPUT);
  pinMode(buzzer_2_Pin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
}
void loop() {
  unsigned long currenttime = micros();
  unsigned long currentwait = millis();
  int notepin8= melody8[counter1];
  int notepin7= melody7[counter2];
  int notelen8= note8length[counter1];
  int notelen7= notelength7[counter2];
  long interval_01 = notepin8; //DETERMIN NOTE 1       
  long interval_02 = notepin7;  //DETERMIN NOTE 2  
  if ((currenttime - previoustime1 >= interval_01) and interval_01 != 0) {
    previoustime1 = currenttime;
    if (buzzer_1_State == LOW) {
      buzzer_1_State = HIGH;
    } else {
      buzzer_1_State = LOW;
    }
    digitalWrite(buzzer_1_Pin, buzzer_1_State);
    }
  if ((currenttime - previoustime2 >= interval_02) and interval_02 != 0) {
    previoustime2 = currenttime;
    if (buzzer_2_State == LOW) {
      buzzer_2_State = HIGH;
    } else {
      buzzer_2_State = LOW;
    }
    digitalWrite(buzzer_2_Pin, buzzer_2_State);
    }
  if (currentwait - previoustime3 >= notelen8){
    previoustime3 = currentwait;
    Serial.println("NOTE.POS.BUZZER01:");
    Serial.println(counter1);
    digitalWrite(buzzer_1_Pin,LOW);
    if (counter1 <= totalnotes_01){
    counter1 = counter1+1;digitalWrite(buzzer_1_Pin,LOW);
    digitalWrite(ledPin, HIGH);
    }
    else{counter1 = 0;digitalWrite(buzzer_1_Pin,LOW);digitalWrite(ledPin, LOW);}
    }
/*  ASSUME THAT THE MELODY FOR PIN8 IS YOUR MAIN MELODY,
*   WHEN PIN8 STARTRED TO PLAY, THE ONBOARD LED LIT UP (PIN 13 IS HIGH).
*   AFTER PIN8 PLAYED THE LAST NOTE, THE LED IS OFF (PIN 13 IS LOW).
*/ 
   if (currentwait - previoustime4 >= notelen7){
    previoustime4 = currentwait;
    Serial.println("NOTE.POS.BUZZER02:");
    Serial.println(counter2);
    digitalWrite(buzzer_2_Pin,LOW);
    if (counter2 < totalnotes_02){
    counter2 = counter2+1;
    digitalWrite(buzzer_2_Pin,LOW);
    }else{counter2 = 0;digitalWrite(buzzer_2_Pin,LOW);}
    }
  
}
