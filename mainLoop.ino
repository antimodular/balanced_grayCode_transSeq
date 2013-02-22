unsigned long mainCounter = 0;
//unsigned long mainCnt = 2097082;
unsigned long shiftMask = 1;

void setup(){

  Serial.begin(9600);
  Serial.println("grayCode_transition_sequence");

  done = false;


  mainCounter = 0;
  transSeqCounter = 0;
  transItem = 0;

}

void loop(){

  if(done == false){
    char currentTransValue = getValue(transSeqCounter,transItem);
    Serial.print("currentTransValue ");
   Serial.println(currentTransValue,DEC);

    mainCounter ^= (shiftMask << currentTransValue);
    transItem++;
//    if(transItem == 1024){
//      transItem = 0;
//      transSeqCounter++;
//      if(transSeqCounter > 2047) done = true;
//    }

    Serial.println(mainCounter);
    Serial.println(mainCounter,BIN);
  } 
  else {
    Serial.println("done"); 
  }
}









