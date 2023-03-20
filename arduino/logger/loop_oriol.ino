//
//#include <SD.h>
//
//#include <LiquidCrystal.h>
//#include <Keypad.h>
//#include <RTClib.h>
//
//SCD30 scd1;
//SCD30 scd2;
//SCD30 scd3;
//SCD30 scd4;
//SCD30 scd5;
//SCD30 scd6;
//SCD30 scd7;
//
//int LED = 52;
//int comut = 0;
//int key = 1;
//int contador = 0;
//double va1;
//double va2;
//double va3;
//double va4;
//double va5;
//double va6;
//double acumulador1 = 0;
//double acumulador2 = 0;
//double acumulador3 = 0;
//double acumulador4 = 0;
//double acumulador5 = 0;
//double acumulador6 = 0;
//double acumuladoro1 = 0;
//double acumuladoro2 = 0;
//double acumuladoro3 = 0;
//double acumuladoro4 = 0;
//double acumuladoro5 = 0;
//double acumuladoro6 = 0;
//
//
//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//const byte ROWS = 4; //four rows
//const byte COLS = 4; //four columns
//char hexaKeys[ROWS][COLS] = {
//  {'1', '2', '3', 'A'},
//  {'4', '5', '6', 'B'},
//  {'7', '8', '9', 'C'},
//  {'*', '0', '#', 'D'}
//};
//byte rowPins[ROWS] = {22, 23, 24, 25};
//byte colPins[COLS] = {26, 27, 28, 29};
//Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//
//RTC_DS1307 rtc;
//int segon, minut, hora, dia, mes, any;
//DateTime clock;
//
//File ArchivoCSV;
//
//
//#define TCAADDR 0x70
//void tcaselect(uint8_t i) {
//  if (i > 7) return;
//
//  Wire.beginTransmission(TCAADDR);
//  Wire.write(1 << i);
//  Wire.endTransmission();
//}
//
//void oriol_setup() {
//    Serial.begin(9600);
//  lcd.begin(16, 2);
//  Wire.begin();
//  pinMode(4, OUTPUT);
//  if (!SD.begin(4)) {//El 4 es el pin de Arduino conectado a CS, si no se puede acceder a la tarjeta, marca el siguiente error.
//    Serial.println("Error al acceder a tarjeta SD.");//Mensaje de error.
//    return;
//  }
//  Serial.println("Acceso correcto a tarjeta SD.");
//  tcaselect(0);
//  scd1.begin();
//  tcaselect(1);
//  scd2.begin();
//  tcaselect(2);
//  scd3.begin();
//  tcaselect(3);
//  scd4.begin();
//  tcaselect(4);
//  scd5.begin();
//  tcaselect(5);
//  scd6.begin();
//  //  tcaselect(7);
//  // scd7.begin(sensor7Address);
//  tcaselect(6);
//  rtc.begin();
//  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//}
//
//void loop_oriol() {
//  
//  char customKey = customKeypad.getKey();
//    if (customKey == '1'){
//      key=1;
//  }
//
//  if (customKey == '2'){
//    key=2;
//  }
//    if (customKey == '3'){
//    key=3;
//  }
//
//  if (customKey == '4'){
//    key=4;
//  }
//  if (customKey == '5'){
//  
//  key=5;
//  }
//if (customKey == '6'){
//
//key=6;
//    }
//  if (customKey == '7'){
//
//key=7;
//    }
//if (customKey == '8'){
//  key=8;
//}    
//if (customKey == '9'){
//  key=9;
//  }
//if (customKey == '0'){
//  key=10;
//  }
//if (customKey == 'A'){
//  key=11;
//  }
//if (customKey == 'B'){
//  key=12;
//  }
//if (customKey == 'C'){
//  key=13;
//  }
//if (customKey == 'D'){
//  key=14;
//  }
//if (customKey == '*'){
//  key=15;
//  }
//if (customKey == '#'){
//  key=16;
//  }
//  if (key == 11) {
//    comut=1;
//    Serial.println("Es pot extreure la targeta SD");
//    Serial.println("Introdueix de nou la targeta SD i prem el botó d'encès");
//    lcd.setCursor(0,0);
//    lcd.print("Es pot extreure la targeta SD");
//    lcd.setCursor(0,1);
//    lcd.print("Prem 8 posar de nou");
//if (customKey == 'B'){
//  key=12;
//}  
//  }
//
//if (key == 12){
//     if (!SD.begin(4)) {//El 4 es el pin de Arduino conectado a CS, si no se puede acceder a la tarjeta, marca el siguiente error.
//      Serial.println("Error al acceder a tarjeta SD.");//Mensaje de error.
//      return;
//    }
//  Serial.println("Acceso correcto a tarjeta SD.");
//  comut=0;
//  lcd.clear();
//key=1;  
//}
//va1=analogRead(0);
//double o2_1 = map(va1,200,1024,0,2100)/100;
//acumuladoro1=acumuladoro1+o2_1;
//va2=analogRead(1);
//double o2_2 = map(va2,200,1024,0,2100)/100;
//acumuladoro2=acumuladoro2+o2_2;
//va3=analogRead(2);
//double o2_3 = map(va3,200,1024,0,2100)/100;
//acumuladoro3=acumuladoro3+o2_3;
//va4=analogRead(3);
//double o2_4 = map(va4,200,1024,0,2100)/100;
//acumuladoro4=acumuladoro4+o2_4;
//va5=analogRead(4);
//double o2_5= map(va5,200,1024,0,2100)/100;
//acumuladoro5=acumuladoro5+o2_5;
//va6=analogRead(5);
//double o2_6 = map(va6,200,1024,0,2100)/100;
//acumuladoro6=acumuladoro6+o2_6;
//  // Presa de mesura del primer sensor
//  tcaselect(0);
//  double co2_1 = scd1.getCO2();
//   acumulador1=co2_1+acumulador1;
////Presa de mesura del segon sensor
//  tcaselect(1);
//  double co2_2 = scd2.getCO2();
//   acumulador2=co2_2+acumulador2;
//  
////Presa de mesura del tercer sensor
//  tcaselect(2);
//   double co2_3 = scd3.getCO2();
//    acumulador3=co2_3+acumulador3;
////   //Presa de mesura del cuart sensor
//    tcaselect(3);
//    double co2_4 = scd4.getCO2();
//     acumulador4=co2_4+acumulador4;
////   //Presa de mesura del cinquè sensor
//    tcaselect(4);
//    double co2_5 = scd5.getCO2();
//     acumulador5=co2_5+acumulador5;
////   //Presa de mesura del sisè sensor
//    tcaselect(5);
//    int co2_6 = scd6.getCO2();
//  //Presa de mesura del sèptim sensor
//  // tcaselect(7);
//  // int co2_7 = scd7.getCO2();
//  //Presa de mesura del temps amb el RTC
//  tcaselect(6);
//    clock = rtc.now();
//    any=clock.year();
//    mes=clock.month();
//    dia=clock.day();
//    hora=clock.hour();
//    minut=clock.minute();
//    segon=clock.second(); 
//
//  
//
//    if (key == 1){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 1:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_1);
//  }
//
//  if (key == 2){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 2:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_2);
//  }
//    if (key == 3){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 3:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_3);
//  }
//
//  if (key == 4){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 4:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_4);
//  }
//  if (key == 5){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 5:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_5);
//    
//  }
//    if (key == 6){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 6:");
//       lcd.setCursor(9,1);
//       lcd.print(co2_6);
//  }
//    if (key == 7){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 1:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_1);
//  }
//    if (key == 8){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 2:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_2);
//  }
//    if (key == 9){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 3:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_3);
//  }
//    if (key == 15){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 4:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_4);
//  }
//    if (key == 10){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 5:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_5);
//  }
//    if (key == 16){
//       lcd.clear();
//       lcd.setCursor(0, 0);
//       lcd.print(hora);
//       lcd.print(":");
//       lcd.print(minut);
//       lcd.print(":");
//       lcd.print(segon);
//       lcd.setCursor(0, 1);
//       lcd.print("Sensor 6:");
//       lcd.setCursor(9,1);
//       lcd.print(o2_6);
//  }
//contador=contador+1;
//if (contador == 60){
//       double mitco2_1=acumulador1/contador;
//       double mitco2_2=acumulador2/contador;
//       double mitco2_3=acumulador3/contador;
//       double mitco2_4=acumulador4/contador;
//       double mitco2_5=acumulador5/contador;
//       double mitco2_6=acumulador6/contador;
//      double mito2_1=acumuladoro1/contador;
//       double mito2_2=acumuladoro2/contador;
//       double mito2_3=acumuladoro3/contador;
//       double mito2_4=acumuladoro4/contador;
//       double mito2_5=acumuladoro5/contador;
//       double mito2_6=acumuladoro6/contador;
//          contador=0;
//          acumulador1=0;
//          acumulador2=0;
//          acumulador3=0;
//          acumulador4=0;
//          acumulador5=0;
//          acumulador6=0;
//          acumuladoro1=0;
//          acumuladoro2=0;
//          acumuladoro3=0;
//          acumuladoro4=0;
//          acumuladoro5=0;
//          acumuladoro6=0;
//          if (comut == 0){
//  ArchivoCSV=SD.open("regist.txt", FILE_WRITE);
//          ArchivoCSV.print(any);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(mes);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(dia);
//          ArchivoCSV.print(", ");
//          ArchivoCSV.print(hora);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(minut);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(segon);
//          
//
//          ArchivoCSV.print(", CO2_1 = ");
//          ArchivoCSV.print(mitco2_1);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_2 = ");
//          ArchivoCSV.print(mitco2_2);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_3 = ");
//          ArchivoCSV.print(mitco2_3);
//          ArchivoCSV.print("ppm");
//          ArchivoCSV.print(", CO2_4 = ");
//          ArchivoCSV.print(mitco2_4);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_5 = ");
//          ArchivoCSV.print(mitco2_5);
//          ArchivoCSV.print("ppm");
//          ArchivoCSV.print(", CO2_6 = ");
//          ArchivoCSV.print(mitco2_6);
//          ArchivoCSV.println("ppm");
//          ArchivoCSV.close();    
//          ArchivoCSV=SD.open("o2mit.txt", FILE_WRITE);
//          ArchivoCSV.print(any);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(mes);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(dia);
//          ArchivoCSV.print(", ");
//          ArchivoCSV.print(hora);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(minut);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(segon);
//          
//
//          ArchivoCSV.print(", O2_1 = ");
//          ArchivoCSV.print(mito2_1);
//          ArchivoCSV.print(" %");
//          ArchivoCSV.print(", O2_2 = ");
//          ArchivoCSV.print(mito2_2);
//          ArchivoCSV.print(" %");
//          ArchivoCSV.print(", O2_3 = ");
//          ArchivoCSV.print(mito2_3);
//          ArchivoCSV.print(" %");
//          ArchivoCSV.print(", O2_4 = ");
//          ArchivoCSV.print(mito2_4);
//          ArchivoCSV.print(" %");
//          ArchivoCSV.print(", O2_5 = ");
//          ArchivoCSV.print(mito2_5);
//          ArchivoCSV.print(" %");
//          ArchivoCSV.print(", O2_6 = ");
//          ArchivoCSV.print(mito2_6);
//          ArchivoCSV.println(" %");
//          ArchivoCSV.close();    
//          }
//}
//if (comut == 0){
// ArchivoCSV = SD.open("registro.txt", FILE_WRITE);
//          ArchivoCSV.print(any);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(mes);
//          ArchivoCSV.print("/");
//          ArchivoCSV.print(dia);
//          ArchivoCSV.print(", ");
//          ArchivoCSV.print(hora);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(minut);
//          ArchivoCSV.print(":");
//          ArchivoCSV.print(segon);
//          
//
//          ArchivoCSV.print(", CO2_1 = ");
//          ArchivoCSV.print(co2_1);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_2 = ");
//          ArchivoCSV.print(co2_2);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_3 = ");
//          ArchivoCSV.print(co2_3);
//          ArchivoCSV.print("ppm");
//          ArchivoCSV.print(", CO2_4 = ");
//          ArchivoCSV.print(co2_4);
//          ArchivoCSV.print(" ppm");
//          ArchivoCSV.print(", CO2_5 = ");
//          ArchivoCSV.print(co2_5);
//          ArchivoCSV.print("ppm");
//          ArchivoCSV.print(", CO2_6 = ");
//          ArchivoCSV.print(co2_6);
//          ArchivoCSV.println("ppm");
//          ArchivoCSV.print(", CO2_7 = ");
//          // ArchivoCSV.print(co2_7);
//          // ArchivoCSV.println("ppm");
//          
//          ArchivoCSV.close(); 
//
//}
//
//
//
//
//  // Mostrar valors en el serial, s'ha de acabar de pulir aquesta part...
//  Serial.print(co2_1);
// Serial.print(",");
//Serial.print(co2_2);
// Serial.print(",");
//   Serial.print(co2_3);
//    Serial.print(",");
//   Serial.print(co2_4);
// Serial.print(",");
//  Serial.print(co2_5);
//   Serial.print(",");
//  Serial.println(co2_6);
//  //   Serial.print("Co2 sensor 7: ");
//  //  Serial.println(co2_7);
//   Serial.print("Raw data: ");
//   Serial.print(any);   Serial.print("-");
//   Serial.print(mes);  Serial.print("-");
//   Serial.print(dia);    Serial.print(" ");
//   Serial.print(hora);   Serial.print(":");
//   Serial.print(minut); Serial.print(":");
//   Serial.print(segon); Serial.println("");
//   Serial.println(contador);
//   Serial.println(acumulador1);
//   Serial.println(o2_1);
//  
//
// delay(1000);
//}
