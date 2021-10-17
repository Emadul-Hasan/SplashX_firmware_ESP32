//****************************************************
//************************************************** *
//Connections of Sensors to ESP32                  * *
//  	                                             * *
//  	                                             * *
//  		                                           * *
//  	                                             * *
// 	                                               * *
//                                                 * *
//************************************************** *
//****************************************************




//****************** Header Call and Declaration of BLE***********

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;



#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"


//**************Class Declaration for BLE with feedback**************************
class MyServerCallbacks: public BLEServerCallbacks {

    void onConnect(BLEServer* pServer)
    {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer)
    {
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic)
    {
      std::string value = pCharacteristic->getValue();
      char message[19];
      String toFind = "open";
      String toClosed = "closed";
      int flag = 0;
      String rcvmsg = "";

      String delay1 = "1";
      String delay2 = "2";
      String delay3 = "3";
      String delay4 = "4";
      String delay5 = "5";
      String delay6 = "6";
      String delay7 = "7";
      String delay8 = "8";
      String delay9 = "9";
      String delay10 = "10";


      if (value.length() > 0)
      {
        for (int i = 0; i < value.length(); i++)
        {
          message[i] = value[i];
          rcvmsg = rcvmsg + message[i];
        }
        Serial.print("Length: "); Serial.println(rcvmsg.length());

        if (rcvmsg.equals(toFind))
        {
      
        }
        else if (rcvmsg.equals(delay1))
        {
          
         

        }
        else if (rcvmsg.equals(delay2))
        {


        }
        else if (rcvmsg.equals(delay3))
        {
        
  

        }
        else if (rcvmsg.equals(delay4))
        {
          

        }
        else if (rcvmsg.equals(delay5))
        {
         


        }
        else if (rcvmsg.equals(delay6))
        {
         


        }
        else if (rcvmsg.equals(delay7))
        {

        }
        else if (rcvmsg.equals(delay8))
        {
 

        }
        else if (rcvmsg.equals(delay9))
        {
         


        }
        else if (rcvmsg.equals(toClosed))
        {
 

        }
        else if (rcvmsg.equals(delay10))
        {
         
          flag = 2;

        }
        else
        {


        }

        strcpy(message, "");

      }
    }
};

void setup() {

  Serial.begin(115200);


  //************Setup for bluetooth******************

  BLEDevice::init("ESP32 Credosense");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  pCharacteristic->setCallbacks(new MyCallbacks());


  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);
  BLEDevice::startAdvertising();

}

void loop() {

  int timeDelay = 1;
  String text = "";
  int delayAssistant = 5;
  timeDelay = delayAssistant * 1000;

  text = "10000000000+00+00";  // to notify
  sendData(text);



  delay(timeDelay);
}
