#include <Bluepad32.h>
#include <HardwareSerial.h>
#include <SPI.h>

HardwareSerial mySerial(1); // Usando Serial1 (TX=GPIO4, RX=GPIO5)
const int txPin = 27;        // Pino TX
const int rxPin = 25;        // Pino RX


int lateral;
int axial;
int yaw1;


ControllerPtr myControllers[BP32_MAX_CONTROLLERS];

void setup() {

  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, rxPin, txPin);
  while (!Serial) {
    ;
  }
  BP32.setup(&onConnectedController, &onDisconnectedController);
}

void onConnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == nullptr) {
      myControllers[i] = ctl;
      break;
    }
  }
}

void onDisconnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == ctl) {
      myControllers[i] = nullptr;
      break;
    }
  }
}


void processGamepad(ControllerPtr gamepad) {
  // Print only the requested values
  Serial.print("  Buttons: ");
  Serial.print(gamepad->buttons());
  
  Serial.print("  Axis X: ");
  Serial.print(gamepad->axisX());
  
  Serial.print("  Axis Y: ");
  Serial.print(gamepad->axisY());
  
  Serial.print("  Axis RX: ");
  Serial.print(gamepad->axisRX());
  
  Serial.print("  Axis RY: ");
  Serial.print(gamepad->axisRY());
  
  Serial.print("  Brake: ");
  Serial.print(gamepad->brake());
  
  Serial.print("  Throttle: ");
  Serial.print(gamepad->throttle());
  
  Serial.print("  Misc: ");
  Serial.print(gamepad->miscButtons());

  Serial.print("  Pad: ");
  Serial.print(gamepad->dpad());
   

mySerial.print("  Later: ");
mySerial.println(gamepad->axisX());
mySerial.print("  Axial: ");
mySerial.println(gamepad->axisY());
mySerial.print("  Yaw1: ");
mySerial.println(gamepad->axisRX());
mySerial.print("  Gat2: ");
mySerial.println(gamepad->throttle());

  Serial.println("");

if(gamepad->y()){
mySerial.print("  Y: ");
mySerial.println("1");
} else if(gamepad->y()){
mySerial.print("  Y: ");
mySerial.println("0");
}
  if (gamepad->a()) {
  for(int i; i < 500; i++){
  gamepad->setRumble(i /* force */, i /* duration */);
  }
  }

  if (gamepad->b()) {
  for(int i; i < 255; i++){
  delay(10);  
  gamepad->setRumble(i /* force */,200  /* duration */);
  }
  }

}



void loop() {
  BP32.update();

  // Process connected controllers
  for (int i = 0; i < BP32_MAX_CONTROLLERS; i++) {
    ControllerPtr myController = myControllers[i];

    if (myController && myController->isConnected() && myController->isGamepad()) {
      processGamepad(myController);
    }
  }
  delay(150);
}
