#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "SSD1306.h"
#include "indexhtml.h"
#include <SoftwareSerial.h>


// Objects of Classes
SSD1306 display(0x3C,D2,D1);
ESP8266WebServer server(80);
SoftwareSerial rassbery(12,13);



// Variables
const char *ssid="your_ssid";
const char *password="your_password";
int y=20;
String data ="";
String dataString;
unsigned long previousMillis = 0;
const long interval = 5000; 


void setup()
{
  rassbery.begin(115200);
  Serial.begin(115200);
  Serial.println();

  display.init();
  display.clear();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);

  wifi_connect();
  server.begin(80);
  server.on("/",root);
  server.on("/data",datam);
  server.on("/Smessage",send_message_web);
  display.display();

}

void loop() 
{
  display.display();
  server.handleClient();
  read_data();
  send_data();

  // unsigned long currentMillis = millis(); 
  // if (currentMillis - previousMillis >= interval) {
  //   previousMillis = currentMillis; 
  //   print_data();
  // }
}



void read_data(){
  while (rassbery.available() > 0) {
    char receivedChar = rassbery.read();
    if (receivedChar==' '){
      dataString+=' ';
      dataString+=data;
      data="";
    }
    else
      data+=receivedChar;
  }
}

void send_data(){
    while (Serial.available() > 0) {
    char sendChar = Serial.read();
    rassbery.print(sendChar);
    }
}


void wifi_connect(){
  WiFi.disconnect();
  WiFi.begin(ssid,password);

  Serial.print("Connecting to ");
  Serial.print(ssid);
  display.clear();
  display.drawString(5,15,"Connecting :");
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    display.drawString(5,y,".");
    y+=1;
    delay(500);
    display.display();
  }

  Serial.println("");
  Serial.print("IP Adress : ");
  Serial.print(WiFi.localIP());
  display.clear();
  display.drawString(5,15,"IP Address :");
  display.drawString(5,32,WiFi.localIP().toString());
 
}
void print_data(){
  Serial.println();
  Serial.print("Data : ");
  Serial.print(dataString);
}

void root(){
  String connection=mainpage+WiFi.localIP().toString()+"/data"+end_page;
  server.send(200,"text/html",connection);
}
void datam(){
  server.send(200,"text/plain",dataString);
}
void send_message_web(){
  String tmp=server.arg("data");
  if (tmp=="")
  {
    return;
  }
  Serial.print(tmp);
  for(int i=0;i<tmp.length();i++)
  {
    char tmp_char=tmp[i];
    rassbery.print(tmp_char);
    if (i==tmp.length()-1)
      rassbery.print('\n');
  }

  server.send(204,"");
}