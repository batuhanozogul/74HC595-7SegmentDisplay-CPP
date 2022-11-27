// C++ code
//

int latchPin = PB0;
int clockPin = PB1;
int dataPin = PB2;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void Write(String Text, int INVERT) {
  digitalWrite(latchPin, LOW);
  byte Bytes[sizeof(Text)];
  int p = 0;
  for (char Char : Text) {
    byte _ = getCharacterByte(Char);
    if (p>0&&Char=='.') {
      bitSet(Bytes[p-1], 0);
    } else {
      Bytes[p] = getCharacterByte(Char);
      p++;
    }
  }
  for (int i=0;i<p;i++) {
  	shiftOut(dataPin, clockPin, LSBFIRST, Bytes[i]);
  }
  digitalWrite(latchPin, HIGH);
}

byte getCharacterByte(char Letter) {
  struct pair {
    char key;
    byte data;
  };
  struct pair dict[33];
  dict[0].key = 'A';
  dict[0].data = 0b11101100;
  dict[1].key = 'B';
  dict[1].data = 0b00111110;
  dict[2].key = 'C';
  dict[2].data = 0b10011100;
  dict[3].key = 'D';
  dict[3].data = 0b01111010;
  dict[4].key = 'E';
  dict[4].data = 0b10011110;
  dict[5].key = 'F';
  dict[5].data = 0b10001110;
  dict[6].key = 'G';
  dict[6].data = 0b10111100;
  dict[7].key = 'H';
  dict[7].data = 0b00101110;
  dict[8].key = 'I';
  dict[8].data = 0b00001100;
  dict[9].key = 'J';
  dict[9].data = 0b11111000;
  dict[10].key = 'K';
  dict[10].data = 0b01101110;
  dict[11].key = 'L';
  dict[11].data = 0b00011100;
  dict[12].key = 'M';
  dict[12].data = 0b11101100;
  dict[13].key = 'N';
  dict[13].data = 0b11101100;
  dict[14].key = 'O';
  dict[14].data = 0b00111010;
  dict[15].key = 'P';
  dict[15].data = 0b11001110;
  dict[16].key = 'R';
  dict[16].data = 0b11101110;
  dict[17].key = 'S';
  dict[17].data = 0b10110110;
  dict[18].key = 'T';
  dict[18].data = 0b10001100;
  dict[19].key = 'U';
  dict[19].data = 0b01111100;
  dict[20].key = 'Y';
  dict[20].data = 0b01001110;
  dict[21].key = 'Z';
  dict[21].data = 0b10010010;
  dict[22].key = '1';
  dict[22].data = 0b01100000;
  dict[23].key = '2';
  dict[23].data = 0b11011010;
  dict[24].key = '3';
  dict[24].data = 0b11110010;
  dict[25].key = '4';
  dict[25].data = 0b01100110;
  dict[26].key = '5';
  dict[26].data = 0b10110110;
  dict[27].key = '6';
  dict[27].data = 0b10111110;
  dict[28].key = '7';
  dict[28].data = 0b11100000;
  dict[29].key = '8';
  dict[29].data = 0b11111110;
  dict[30].key = '9';
  dict[30].data = 0b11110110;
  dict[31].key = '0';
  dict[31].data = 0b11111100;
  dict[32].key = '.';
  dict[32].data = 0b00000001;
  
  
  
  for(int i=0;i<=32;i++) {
    if(dict[i].key == Letter) {
     return dict[i].data;
    };
  };
  return 0b00000000;
}

 
void Test() 
{
  String text = "AB";
  Write(text);
}
