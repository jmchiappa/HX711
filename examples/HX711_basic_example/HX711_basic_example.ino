#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 cell;

boolean complete = false;

void displayValue(float weight) {
  Serial.println(weight);
  complete = true;
}

void setup() {

  Serial.begin(57600);

  cell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  cell.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details  
  cell.tare();

  complete = true; // start a new cycle
}

void loop() {

  if (complete) {
    complete=false;
    Serial.print("nouvelle valeur : ");
    cell.get_units(displayValue,50);
  }
}
