/*
 * Blink(LED)
 */

/*
#define BDPIN_LED_USER_1        22
#define BDPIN_LED_USER_2        23
#define BDPIN_LED_USER_3        24
#define BDPIN_LED_USER_4        25
//#define BDPIN_LED_STATUS        36

 */
int led_pin = 13;
int led_pin_user[5] = { BDPIN_LED_USER_1, BDPIN_LED_USER_2, BDPIN_LED_USER_3, BDPIN_LED_USER_4, BDPIN_LED_STATUS };
char key = 0;
void setup() {
  // put your setup code here, to run once:
//  pinMode(led_pin, OUTPUT);
  pinMode(led_pin_user[0], OUTPUT);
  pinMode(led_pin_user[1], OUTPUT);
  pinMode(led_pin_user[2], OUTPUT);
  pinMode(led_pin_user[3], OUTPUT);
  //pinMode(led_pin_user[4], OUTPUT);

  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
char key;
   while((key=test_main_menu()) != 0)
   {
      switch(key)
      { 
         case '1':
            Serial.print("No.0\r\n");
            digitalWrite(led_pin_user[0], LOW);
            delay(100);
            digitalWrite(led_pin_user[0], HIGH);
            break;
         case '2':
            Serial.print("No.1\r\n");
            digitalWrite(led_pin_user[1], LOW);
            delay(100);
            digitalWrite(led_pin_user[1], HIGH);
            break;
         case '3':
            Serial.print("No.2\r\n");
            digitalWrite(led_pin_user[2], LOW);
            delay(100);
            digitalWrite(led_pin_user[2], HIGH);
            break;
         case '4':
            Serial.print("No.3\r\n");
            digitalWrite(led_pin_user[3], LOW);
            delay(100);
            digitalWrite(led_pin_user[3], HIGH);
            break;
         case '5':  //ALL OFF
            Serial.print("No.5\r\n");
            for( i=0; i<4; i++ )
              {
                digitalWrite(led_pin_user[i], HIGH);
//                delay(100);
              }
            break;        
           
         case '6': //ALL ON
            Serial.print("No.6\r\n");
            for( i=0; i<4; i++ )
              {
                digitalWrite(led_pin_user[i], LOW);
//                delay(100);
              }
            break;

          case '7':
            Serial.print("No.7\r\n");
            for( i=0; i<4; i++ )
              {
                digitalWrite(led_pin_user[i], HIGH);
//                delay(100);
              }
            for( i=0; i<4; i++ )
              {
                digitalWrite(led_pin_user[i], LOW);
                 delay(100);
              }
            break;        
           
         case '8':
            Serial.print("No.8\r\n");
            for( i=0; i<4; i++ )
              {
                digitalWrite(led_pin_user[i], HIGH);
//                delay(100);
              }
            for( i=3; i>=0; i-- )
              {
                digitalWrite(led_pin_user[i], LOW);
                 delay(100);
              }
            break;
         default:
            Serial.print("default\r\n");
            break;       }
   }
}

char test_main_menu(void)
{
   char key;   Serial.print("\n\r\n");
   Serial.print("-------------------------------------------------\r\n");
   Serial.print("EDUCATION SHIELD TEST MAIN MENU\r\n");
   Serial.print("-------------------------------------------------\r\n");
//   Serial.print(" 0.  0 Digital OUT \r\n");
   Serial.print(" 1.  1 Digital OUT \r\n");
   Serial.print(" 2.  2 Digital OUT \r\n");
   Serial.print(" 3.  3 Digital OUT \r\n");
   Serial.print(" 4.  4 Digital OUT \r\n");
   Serial.print(" 5.  5 ALL OFF \r\n");
   Serial.print(" 6.  6 ALL ON \r\n");
   Serial.print(" 7.  7 Sequencial 1->4 OUT \r\n");
   Serial.print(" 8.  8 Sequencial 4->1 OUT \r\n");
   
//   Serial.print("-------------------------------------------------\r\n");
//   Serial.print(" q. SKELETON IOCTL QUIT\r\n");
//   Serial.print("-------------------------------------------------\r\n");
   Serial.print("\n\r\n");
   Serial.print("SELECT THE COMMAND NUMBER : ");   
   while(1)
   {
       if(Serial.available())
       {
          char buffer[20]; 
          key = (char)Serial.read();
          sprintf(buffer , "You selected %c", key);

          Serial.println(buffer); 
           break;
       }
   }   return key;
}
