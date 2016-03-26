// MouseTo - Library for Arduino Leonardo/Micro for moving the mouse pointer to absolute screen coordinates: http://github.com/per1234/MouseTo
#include "MouseTo.h"


MouseToClass::MouseToClass() {
  //set default values
  screenResolutionX = 3840;  //4K UHD
  screenResolutionY = 2160;  //4K UHD
  correctionFactor = 1;
  jumpDistance = 10;  //this seems like a good balance between speed and accuracy
}


boolean MouseToClass::moveTo(int targetX, int targetY) {
  //the mouse is homed to 0,0 on each mouse movement to make sure the absolute screen coordinates will be reached even if the physical mouse has been moved since the last moveTo
  if (homed == false) {
    //make sure it reaches 0,0 even in the worst case scenario of the cursor being at the bottom right corner
    targetX = -screenResolutionX - 50;
    targetY = -screenResolutionY - 50;
  }

  //convert screen coordinates to Arduino corrdinates
  targetX = targetX * correctionFactor;
  targetY = targetY * correctionFactor;

  const int moveX = targetX >= positionX ? min(jumpDistance, targetX - positionX) : max(-jumpDistance, targetX - positionX);
  const int moveY = targetY >= positionY ? min(jumpDistance, targetY - positionY) : max(-jumpDistance, targetY - positionY);
  Mouse.move(moveX, 0, 0);
  Mouse.move(0, moveY, 0);
  positionX += moveX;
  positionY += moveY;
  if (positionX == targetX && positionY == targetY) {
    if (homed == false) {  //mouse is homed
      homed = true;
      positionX = 0;
      positionY = 0;
      return false;
    }
    homed = false;  //reset for the next go
    return true;
  }
  return false;
}


void MouseToClass::setScreenResolution(const int x, const int y) {
  screenResolutionX = x;
  screenResolutionY = y;
}


unsigned int MouseToClass::getScreenResolutionX() {
  return screenResolutionX;
}


unsigned int MouseToClass::getScreenResolutionY() {
  return screenResolutionY;
}


void MouseToClass::setCorrectionFactor(const float correctionFactorInput) {
  correctionFactor = correctionFactorInput;
}


float MouseToClass::getCorrectionFactor() {
  return correctionFactor;
}


void MouseToClass::setMaxJump(const int8_t jumpDistanceInput) {
  jumpDistance = jumpDistanceInput;
}


int8_t MouseToClass::getMaxJump() {
  return jumpDistance;
}


MouseToClass MouseTo;  //This sets up a single global instance of the library so the class doesn't need to be declared in the user sketch and multiple instances are not necessary in this case.

