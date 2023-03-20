
#include <Ethernet.h>
#include <ArduinoHttpClient.h>


//byte MAC[] = { 0x90, 0xA2, 0xDA, 0x00, 0x68, 0xCD };
byte MAC[] = { 0xBE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };


EthernetClient ether;
HttpClient client = HttpClient(ether, API_HOST, API_PORT);

boolean started = false;

String httpBuffer = "";

boolean isConn;


/**
 * 
 */
void startEthernet() {
  debugSerial("---- start internet ---");
  started = true;
  isConn = false;
  Ethernet.begin(MAC);
  
  Serial.print("Arduino's IP Address: ");
  Serial.println(Ethernet.localIP());
  
  Serial.print("DNS Server's IP Address: ");
  Serial.println(Ethernet.dnsServerIP());
  
  Serial.print("Gateway's IP Address: ");
  Serial.println(Ethernet.gatewayIP());
  
  Serial.print("Network's Subnet Mask: ");
  Serial.println(Ethernet.subnetMask());  
}

void debugSerial(String s) {
  Serial.print("# ");
  Serial.println(s);
}

void debugSerial(String s, String s2) {
  Serial.print("# ");
  Serial.print(s);
  Serial.println(s2);
}

void debugSerial(String s, int s2) {
  Serial.print("# ");
  Serial.print(s);
  Serial.println(s2);
}

bool sendHttpRequest(String data) {

    client.beginRequest();

    String path = "/index.php/sample/write?data=" + data;
    client.get(path);
//    client.sendHeader("Content-Type", "application/json");
//    client.sendHeader("Content-Length", postData.length());
//    client.beginBody();
//    client.print(postData);
    client.endRequest();

    int statusCode = client.responseStatusCode();
    client.stop();

    Serial.println("status code: ");   //Prints the HTTP status response - 200 if OK
    Serial.println(statusCode);   //Prints the HTTP status response - 200 if OK
    Serial.println("Data to the Server");
    Serial.println("Wait one seconds");

    return statusCode == 200;
}

///**
//   writeRest
//*/
//void sendHttpRequest(String data) {
//
//  boolean wasConnected = false;
//
//  if (!started) {
//    startEthernet();
//  }
//
//  if (client.connected()) {
//    debugSerial("\t<already connected>");
//    wasConnected = true;
//  } else {
//    startEthernet();
//  }
//
//  String payload = "GET /index.php/sample/write?data=" + data;
//  int l1 = payload.length();
//  int l2 = client.print(payload);
//
//  Serial.println(payload);
//  debugSerial("\tto send", l1);
//  debugSerial("\tsent", l2);
//
//  if (l1 != l2) {
//    if (wasConnected) {
//      debugSerial("S", "-- stop client? --");
//      client.stop();
//    }
//
//    debugSerial ("S", "-- connect? --");
//    if (client.connect(API_HOST, 80)) {
//      isConn = true;
//      int l = client.println(payload);
//      debugSerial("\t**S", l);
//    }
//    else {
//      debugSerial("\t**S", "connection failed");
//    }
//  }
//}

/**

*/
void readNetwork () {

//  // check if connected
//  if (!client.connected()) {
//    if (isConn) {
//      isConn = false;
//      debugSerial("-------------------- NOT CONNECTED -----------------");
//      client.stop();
//    }
//    return;
//  }
//
//  // read serial
//  while (client.available()) {
//    int inByte = client.read();
//
//    // check if newLine
//    if (inByte == '\n') {
//      debugSerial (" HTT RESPONSE: ", httpBuffer);
//      if (httpBuffer.startsWith("OK")) {
//        //client.stop();
//        //Serial.println("disconnected!");
//      }
//      httpBuffer = "";
//    }
//    else {
//      // add to incomming buffer
//      httpBuffer += (char) inByte;
//    }
//  }
}
