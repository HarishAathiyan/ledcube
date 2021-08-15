

#include "sourceledCUBE.h"
int it=1;
void setup() {
init_ledCube();
}

void loop() {
  it=it+10;
  if(it>300){
    it=1;
    }
effect3(it);
effect2(it);
effect1(it);
checkAllLed(it);
}
