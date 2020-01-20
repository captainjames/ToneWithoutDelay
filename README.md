# ToneWithoutDelay
An Arduino code using manually-set music notes‘ period to produce diffrent frequency oscillations on multiple pins (channels) . Without using the built-in delay() and tone() function.

Code done by Lekkon7193 (ASU7193).
Special thanks for ASU3649's support for monitering and cross-checking for errors during the development stage.

Two（or more) series of musics notes and their respective durations are stored saperately in the ".h" files as integer lists.
Loops are set saperately for each serie of notes 
so that you can set how many notes to be played before they start again from the first note.

How Does it works:

To play a note, the respective pins switch from LOW to HIGH to LOW (or HIGH-LOW-HIGH) for the note's period time.
A oscillating signal is produced.

Traditionally we use tone() and delay() function so that the onboard processor can use PWM to handle the swiching process hence we can get a square-wave tone output.
However this only allow one tone to be played at one time. This makes the arduino unable to output multiple melodies.

Hence to play diffrent melodies on one sigle board, we need to disregard the tone() and delay() function.

In this program, a microsecond timer is used to count the period of the note.
We can program the board to make one cycle of switch for the period of time, so the squarewave can oscillate at the correct frequency.
Another millisecond timer is to decided how many time is needed for the duration of this note. A loop is set for the board to swich  the pin between HIGH and LOW repetively in the duration.

Hence, we can set the value of period and duration of each note and make them into series to create melodies. As the tone() and delay() function are not used, multiple notes can be playd from diffrent pins at the same time.

So that You can connect multiple piezo-buzzers or speakers for multiple channels of tone output pins.

This is the first version of the program.
Tested With SPEEEduino v1.1(issued by Singapore Polytechnic). 
This code support Arduino Uno and other arduino boards with a DRAM >= 2048 Bytes.

James Wang 
19/01/2020
