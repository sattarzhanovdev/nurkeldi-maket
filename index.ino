#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

SoftwareSerial bluetooth(9, 10);

Adafruit_NeoPixel a_block = Adafruit_NeoPixel(200, 6, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel b_block = Adafruit_NeoPixel(200, 7, NEO_RGB + NEO_KHZ800);

long res;
long lastFloor;
long lastBlock;

void setup(){ 
  Serial.begin(9600);
  a_block.begin();
  b_block.begin();
  bluetooth.begin(9600);
}

void loop(){
  res = (bluetooth.read());
//   for(int i = 0; i < 5; i++){
//    a_block.setBrightness(255);
//    a_block.setPixelColor(i, b_block.Color(255, 255, 255));
//    a_block.show();
//  } 
//  for(int i = 0; i < 5; i++){
//    b_block.setBrightness(255);
//    b_block.setPixelColor(i, b_block.Color(255, 255, 255));
//    b_block.show();
//  }
  switch (res){
    case 'D':
      a_block.clear();
      b_block.clear();
      for (int i = 0; i < 93; i++) {
        if (i % 3) {
          b_block.setBrightness(255);
          b_block.setPixelColor(i - 1, b_block.Color(255, 255, 150));
          b_block.show();
        } else {
          continue;
        }
      }
      for (int i = 0; i < 137; i++) {
        if (i % 3 == 0) {
          a_block.setBrightness(255);
          a_block.setPixelColor(i - 1, a_block.Color(255, 255, 150));
          a_block.show();
        } else {
          continue;
        }
      }
      break;
    // Включаем все дома
    case 'v':
      a_block.clear();
      b_block.clear();
      for(int i = 0; i < 93; i++){
        b_block.setBrightness(255);
        b_block.setPixelColor(i, b_block.Color(255, 255, 255));
        b_block.show();
      }

      for(int i = 0; i < 137; i++){
        a_block.setBrightness(255);
        a_block.setPixelColor(i, a_block.Color(255, 255, 255));
        a_block.show();
      }

    break;

    // Выключаем все дома
    case 'o':
      turn_off();
    break;

    // Блок Б

    case '<':
      a_block.clear();
      b_block.clear();
      for(int i = 0; i < 137; i++){
        a_block.setBrightness(0);
        a_block.setPixelColor(i, a_block.Color(255, 255, 255));
        a_block.show();
      }

      for(int i = 0; i < 94; i++){
        b_block.setBrightness(255);
        b_block.setPixelColor(i, b_block.Color(255, 255, 255));
        b_block.show();
      }
      lastBlock = '<';
    break;

    // Блок А

    case '>':
      a_block.clear();
      b_block.clear();
      for(int i = 0; i < 94; i++){
        b_block.setBrightness(0);
        b_block.setPixelColor(i, b_block.Color(255, 255, 255));
        b_block.show();
      }
      for(int i = 0; i < 137; i++){
        a_block.setBrightness(255);
        a_block.setPixelColor(i, a_block.Color(255, 255, 255));
        a_block.show();
      }
      lastBlock = '>';
    break;

    // Первый этаж

    case 'a':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 5; i < 13; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 5; i < 16; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'a';
    break;

    // Второй этаж
    case 'b':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 13; i < 21; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 16; i < 27; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'b';
    break;

    // Третий этаж

    case 'c':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 21; i < 29; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 27; i < 38; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'c';
    break;

    // Четвертый этаж
    case 'd':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 29; i < 37; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 38; i < 49; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'd';

    break;

    // Пятый этаж
    case 'e':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 37; i < 45; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 49; i < 60; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'e';

    break;

    // Шестой этаж
    case 'f':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 45; i < 53; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 60; i < 71; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'f';
    break;

    // Седьмой этаж
    case 'g':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 53; i < 61; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 71; i < 82; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'g';

    break;

    // Восьмой этаж
    case 'h':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 61; i < 69; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 82; i < 93; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'h';

    break;

    // Девятый этаж
    case 'i':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 69; i < 77; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 93; i < 104; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'i';

    break;

    // Десятый этаж
    case 'j':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 77; i < 85; i++){
          b_block.setBrightness(255);
          b_block.setPixelColor(i, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 104; i < 115; i++){
          a_block.setBrightness(255);
          a_block.setPixelColor(i, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }

      lastFloor = 'j';
    break;

    // Одиннадцатый этаж
    case 'k':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        for(int i = 85; i < 95; i++){
         b_block.setBrightness(255);
         b_block.setPixelColor(i, b_block.Color(255, 255, 255));
         b_block.show();
        }
      }else if(lastBlock == '>'){
        for(int i = 115; i < 126; i++){
         a_block.setBrightness(255);
         a_block.setPixelColor(i, a_block.Color(255, 255, 255));
         a_block.show();
        }
      }

      lastFloor = 'k';
    break;

    // Двеннадцатый этаж    
    case 'l':
      a_block.clear();
      b_block.clear();
      for(int i = 85; i < 95; i++){
       a_block.setBrightness(255);
       a_block.setPixelColor(i, a_block.Color(255, 255, 255));
       a_block.show();
      }

      lastFloor = 'l';
    break;

    // Двеннадцатый этаж    
    case 'm':
      a_block.clear();
      b_block.clear();
      for(int i = 126; i < 137; i++){
       a_block.setBrightness(255);
       a_block.setPixelColor(i, a_block.Color(255, 255, 255));
       a_block.show();
      }

      lastFloor = 'm';
    break;

    // Квартиры        
    case '1':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          for(int i = 6; i < 7; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 13; i < 15; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'c'){
          for(int i = 21; i < 23; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 29; i < 31; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 37; i < 39; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 45; i < 47; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 53; i < 55; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 61; i < 63; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 69; i < 71; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 77; i < 79; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 86; i < 88; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          a_block.setBrightness(255);
          a_block.setPixelColor(5, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'b'){
          a_block.setBrightness(255);
          a_block.setPixelColor(16, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'c'){
          a_block.setBrightness(255);
          a_block.setPixelColor(27, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'd'){
          a_block.setBrightness(255);
          a_block.setPixelColor(38, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'e'){
          a_block.setBrightness(255);
          a_block.setPixelColor(49, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'f'){
          a_block.setBrightness(255);
          a_block.setPixelColor(60, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'g'){
          a_block.setBrightness(255);
          a_block.setPixelColor(71, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'h'){
          a_block.setBrightness(255);
          a_block.setPixelColor(82, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'i'){
          a_block.setBrightness(255);
          a_block.setPixelColor(93, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'j'){
          a_block.setBrightness(255);
          a_block.setPixelColor(104, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'k'){
          a_block.setBrightness(255);
          a_block.setPixelColor(115, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'l'){
          a_block.setBrightness(255);
          a_block.setPixelColor(126, a_block.Color(255, 255, 255));
          a_block.show();
        }else if(lastFloor == 'm'){
          a_block.setBrightness(255);
          a_block.setPixelColor(130, a_block.Color(255, 255, 255));
          a_block.show();
        }
      }
    break;    

    case '2':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          b_block.setBrightness(255);
          b_block.setPixelColor(7, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'b'){
          b_block.setBrightness(255);
          b_block.setPixelColor(15, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'c'){
          b_block.setBrightness(255);
          b_block.setPixelColor(23, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'd'){
          b_block.setBrightness(255);
          b_block.setPixelColor(31, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'e'){
          b_block.setBrightness(255);
          b_block.setPixelColor(39, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'f'){
          b_block.setBrightness(255);
          b_block.setPixelColor(47, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'g'){
          b_block.setBrightness(255);
          b_block.setPixelColor(55, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'h'){
          b_block.setBrightness(255);
          b_block.setPixelColor(63, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'i'){
          b_block.setBrightness(255);
          b_block.setPixelColor(71, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'j'){
          b_block.setBrightness(255);
          b_block.setPixelColor(79, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'k'){
          b_block.setBrightness(255);
          b_block.setPixelColor(85, b_block.Color(255, 255, 255));
          b_block.show();
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          for(int i = 6; i < 8; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 17; i < 19; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'c'){
         for(int i = 28; i < 30; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 39; i < 41; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 50; i < 52; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 61; i < 63; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 72; i < 74; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 83; i < 85; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 94; i < 96; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 105; i < 107; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 116; i < 118; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'm'){
          for(int i = 131; i < 133; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }
      }
    break;    

    case '3':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          b_block.setBrightness(255);
          b_block.setPixelColor(8, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'b'){
          b_block.setBrightness(255);
          b_block.setPixelColor(16, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'c'){
          b_block.setBrightness(255);
          b_block.setPixelColor(24, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'd'){
          b_block.setBrightness(255);
          b_block.setPixelColor(32, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'e'){
          b_block.setBrightness(255);
          b_block.setPixelColor(40, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'f'){
          b_block.setBrightness(255);
          b_block.setPixelColor(48, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'g'){
          b_block.setBrightness(255);
          b_block.setPixelColor(56, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'h'){
          b_block.setBrightness(255);
          b_block.setPixelColor(64, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'i'){
          b_block.setBrightness(255);
          b_block.setPixelColor(72, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'j'){
          b_block.setBrightness(255);
          b_block.setPixelColor(80, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'k'){
            a_block.clear();
            b_block.clear();
            for(int i = 92; i < 93; i++){
             b_block.setBrightness(255);
             b_block.setPixelColor(i, b_block.Color(255, 255, 255));
             b_block.show();
            }
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          for(int i = 8; i < 10; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 19; i < 21; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'c'){
         for(int i = 30; i < 32; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 41; i < 43; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 52; i < 54; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 63; i < 65; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 74; i < 76; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 85; i < 87; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 96; i < 98; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 107; i < 109; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 118; i < 120; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'm'){
          for(int i = 133; i < 135; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }
      }
    break;    

    case '4':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          b_block.setBrightness(255);
          b_block.setPixelColor(9, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'b'){
          b_block.setBrightness(255);
          b_block.setPixelColor(17, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'c'){
          b_block.setBrightness(255);
          b_block.setPixelColor(25, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'd'){
          b_block.setBrightness(255);
          b_block.setPixelColor(33, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'e'){
          b_block.setBrightness(255);
          b_block.setPixelColor(41, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'f'){
          b_block.setBrightness(255);
          b_block.setPixelColor(49, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'g'){
          b_block.setBrightness(255);
          b_block.setPixelColor(57, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'h'){
          b_block.setBrightness(255);
          b_block.setPixelColor(65, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'i'){
          b_block.setBrightness(255);
          b_block.setPixelColor(73, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'j'){
          b_block.setBrightness(255);
          b_block.setPixelColor(81, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'k'){
          a_block.clear();
          b_block.clear();
          for(int i = 91; i < 92; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          for(int i = 10; i < 12; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 22; i < 23; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'c'){
         for(int i = 32; i < 34; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 43; i < 45; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 54; i < 56; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 65; i < 67; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 76; i < 78; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 87; i < 89; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 98; i < 100; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 109; i < 111; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 120; i < 122; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'm'){
          for(int i = 135; i < 137; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }
      }
    break;    

    case '5':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          b_block.setBrightness(255);
          b_block.setPixelColor(10, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'b'){
          b_block.setBrightness(255);
          b_block.setPixelColor(18, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'c'){
          b_block.setBrightness(255);
          b_block.setPixelColor(26, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'd'){
          b_block.setBrightness(255);
          b_block.setPixelColor(34, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'e'){
          b_block.setBrightness(255);
          b_block.setPixelColor(42, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'f'){
          b_block.setBrightness(255);
          b_block.setPixelColor(50, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'g'){
          b_block.setBrightness(255);
          b_block.setPixelColor(58, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'h'){
          b_block.setBrightness(255);
          b_block.setPixelColor(66, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'i'){
          b_block.setBrightness(255);
          b_block.setPixelColor(74, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'j'){
          b_block.setBrightness(255);
          b_block.setPixelColor(82, b_block.Color(255, 255, 255));
          b_block.show();
        }else if(lastFloor == 'k'){
          a_block.clear();
          b_block.clear();
          for(int i = 90; i < 91; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          for(int i = 12; i < 14; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 23; i < 25; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'c'){
         for(int i = 34; i < 36; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 46; i < 47; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 57; i < 58; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 68; i < 69; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 79; i < 80; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 90; i < 91; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 101; i < 102; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 112; i < 113; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 123; i < 124; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'm'){
          for(int i = 126; i < 128; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }
      }
    break;    

    case '6':
      a_block.clear();
      b_block.clear();
      if(lastBlock == '<'){
        if(lastFloor == 'a'){
          a_block.clear();
          b_block.clear();
          for(int i = 11; i < 13; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'b'){
          a_block.clear();
          b_block.clear();
          for(int i = 19; i < 21; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'c'){
          a_block.clear();
          b_block.clear();
          for(int i = 27; i < 29; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'd'){
          a_block.clear();
          b_block.clear();
          for(int i = 35; i < 37; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'e'){
          a_block.clear();
          b_block.clear();
          for(int i = 43; i < 45; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'f'){
          a_block.clear();
          b_block.clear();
          for(int i = 51; i < 53; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'g'){
          a_block.clear();
          b_block.clear();
          for(int i = 59; i < 61; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'h'){
          a_block.clear();
          b_block.clear();
          for(int i = 67; i < 69; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'i'){
          a_block.clear();
          b_block.clear();
          for(int i = 75; i < 77; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'j'){
          a_block.clear();
          b_block.clear();
          for(int i = 83; i < 85; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }else if(lastFloor == 'k'){
          a_block.clear();
          b_block.clear();
          for(int i = 88; i < 90; i++){
            b_block.setBrightness(255);
            b_block.setPixelColor(i, b_block.Color(255, 255, 255));
            b_block.show();
          }
        }
      }else if(lastBlock == '>'){
        if(lastFloor == 'a'){
          for(int i = 14; i < 15; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'b'){
          for(int i = 25; i < 26; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'c'){
         for(int i = 36; i < 37; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'd'){
          for(int i = 47; i < 48; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'e'){
          for(int i = 58; i < 59; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'f'){
          for(int i = 69; i < 70; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'g'){
          for(int i = 80; i < 81; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'h'){
          for(int i = 91; i < 92; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'i'){
          for(int i = 102; i < 103; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'j'){
          for(int i = 113; i < 114; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'k'){
          for(int i = 124; i < 125; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }else if(lastFloor == 'm'){
          for(int i = 128; i < 129; i++){
            a_block.setBrightness(255);
            a_block.setPixelColor(i, a_block.Color(255, 255, 255));
            a_block.show();
          }
        }
      }
    break;
  }
}


void turn_off(){
  a_block.clear();
  b_block.clear();
  for(int i = 0; i < 93; i++){
    b_block.setBrightness(0);
    b_block.setPixelColor(i, b_block.Color(255, 255, 255));
    b_block.show();
  }

  for(int i = 0; i < 137; i++){
    a_block.setBrightness(0);
    a_block.setPixelColor(i, a_block.Color(255, 255, 255));
    a_block.show();
  }
}
