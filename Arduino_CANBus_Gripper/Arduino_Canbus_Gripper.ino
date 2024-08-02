#include "AA_MCP2515.h"
#include <Servo.h>
#include "AccelStepper.h"

Servo myservo;
#define dirPin 4
#define stepPin 3
#define motorInterfaceType 1
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
int Btn1;
int Btn2;
// TODO: modify CAN_BITRATE, CAN_PIN_CS(Chip Select) pin, and CAN_PIN_INT(Interrupt) pin as required.
const CANBitrate::Config CAN_BITRATE = CANBitrate::Config_8MHz_500kbps;
const uint8_t CAN_PIN_CS = 2;
const int8_t CAN_PIN_INT = 7;
uint8_t Data[8];
CANConfig config(CAN_BITRATE, CAN_PIN_CS, CAN_PIN_INT);
CANController CAN(config);
int angle = 180;
void setup() {
  Serial.begin(115200);

  while(CAN.begin(CANController::Mode::Normal) != CANController::OK) {
    Serial.println("CAN begin FAIL - delaying for 1 second");
    delay(1000);
  angle = (128*2400)/360;
  stepper.moveTo(angle);
  stepper.runToPosition();
  delay(100);
  }
  Serial.println("CAN begin OK");
  myservo.attach(9);
  stepper.setMaxSpeed(200);
  stepper.setAcceleration(30);
}

void loop() {
  CANFrame frame;
  if (CAN.read(frame) == CANController::IOResult::OK) {
     frame.getData(Data,8);}
     frame.print("Recieved Data : ");
     
  Servo_Control(Data);
  Stepper_Control(Data);

  delay(100);
}

void Servo_Control(uint8_t Data[]){
/*
  Data[1]= counter%2; //Servo Hold / Release 1/0
  Gripper servo Freedom is 50->100
*/
  if(Data[1]==1){
    myservo.write(50);
    delay(100);
  }
  else if (Data[1]==0){
    myservo.write(230);
      delay(100);
    }
}
/*
Data[0]= counter;//Stepper Angle
*/
void Stepper_Control(uint8_t Data[]){
  // Set the target position:
  angle = (Data[0]*600)/360;
  stepper.moveTo(angle);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();
  delay(100);
}










