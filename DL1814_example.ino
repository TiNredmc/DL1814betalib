#include <DL1814.h>

/* BL pin is blank control.by put to low to disable display temporary.untill put back to high.you can control by arduino 
 * CE is chip enable.by put to low will enable ic CMOS inside DL1814.put to high to disable chip untill put back to low.you can also control by arduino. 
 * These are the pin names as in the DL1814 datasheet.
 * Define them as you have connected them on your circuit.
 */
int WR = 2;
int Addr0 = 12;
int Addr1 = 13;
int Addr2 = 11;
int D0 = 3; // Pin 3 is PWM, change if you need PWM for other purposes. DL1814 does not need PWM.
int D1 = 4;
int D2 = 5; // Pin 5 is PWM, change if you need PWM for other purposes. DL1814 does not need PWM.
int D3 = 6; // Pin 6 is PWM, change if you need PWM for other purposes. DL1814 does not need PWM.
int D4 = 7;
int D5 = 8;
int D6 = 9; // Pin 9 is PWM, change if you need PWM for other purposes. DL1814 does not need PWM.

// Init Library with proper pin definitions
DL1814 dl1814(WR, Addr0, Addr1, Addr2, D0, D1, D2, D3, D4, D5, D6);

void setup() {
  // After powerup some DL1814 modules show random characters
  dl1814.clear();
}

void loop() {
  // Display a scrolling text
  String str = "HELLO WORLD! IM DL1814";
  dl1814.writeStringScrolling(str, 133);

  // Display a fixed string
  str = "HI";
  dl1814.writeStringFix(str);
  delay(2000);

  // clear previous text
  dl1814.clear();
  delay(1000);

  // address columns directly
  dl1814.writeByte('A',0);
  delay(500);
  dl1814.writeByte('B',1);
  delay(500);
  dl1814.writeByte('C',2);
  delay(500);
  dl1814.writeByte('D',3);
  delay(500);
  dl1814.writeByte('E',4);
  delay(500);
  dl1814.writeByte('F',5);
  delay(500);
  dl1814.writeByte('G',6);
  delay(500);
  dl1814.writeByte('H',7);
  delay(2000);

}

