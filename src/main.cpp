#include "ICM42688.h"

// an ICM42688 object with the ICM42688 sensor on I2C bus 0 with address 0x68
ICM42688 IMU(Wire, 0x69);

void setup() {
  // serial to display data
  Serial.begin(115200);
  delay(1000);
  while (!Serial) {
  }

  // start communication with IMU
  int status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1){}
  }

  // setting the accelerometer full scale range to +/-8G
  IMU.setAccelFS(ICM42688::gpm8);
  // setting the gyroscope full scale range to +/-500 deg/s
  IMU.setGyroFS(ICM42688::dps500);

  // set output data rate to 12.5 Hz
  IMU.setAccelODR(ICM42688::odr12_5);
  IMU.setGyroODR(ICM42688::odr12_5);

  Serial.println("ax,ay,az,gx,gy,gz,temp_C");
}

void loop() {
  // read the sensor
  IMU.getAGT();

  // display the data
  Serial.print(">accX:");
  Serial.print(IMU.accX(), 6);
  Serial.print("\n");
  Serial.print(">accY:");
  Serial.print(IMU.accY(), 6);
  Serial.print("\n");
  Serial.print(">accZ:");
  Serial.print(IMU.accZ(), 6);
  Serial.print("\n");
  Serial.print(">gyroX:");
  Serial.print(IMU.gyrX(), 6);
  Serial.print("\n");
  Serial.print(">gyroY:");
  Serial.print(IMU.gyrY(), 6);
  Serial.print("\n");
  Serial.print(">gyroZ:");
  Serial.print(IMU.gyrZ(), 6);
  Serial.print("\n");
  delay(20);
}
