#include <Wire.h>
#include <BleMouse.h>

BleMouse bleMouse("ESP32 Air Mouse");
const int MPU_ADDR = 0x68;

int16_t accX, accY, accZ;
float xAngle, yAngle;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(1000);

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  bleMouse.begin();
}

void loop() {
  if (!bleMouse.isConnected()) {
    delay(1000);
    return;
  }

  // --- Read accelerometer data ---
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  accX = Wire.read() << 8 | Wire.read();
  accY = Wire.read() << 8 | Wire.read();
  accZ = Wire.read() << 8 | Wire.read();

  // Convert to small motion values
  xAngle = accX / 16384.0 * 90;
  yAngle = accY / 16384.0 * 90;

  int moveX = (int)(xAngle / 3);
  int moveY = (int)(yAngle / 3);

  moveX = constrain(moveX, -10, 10);
  moveY = constrain(moveY, -10, 10);

  // Move the cursor
  bleMouse.move(moveX, -moveY);

  delay(20);
}
