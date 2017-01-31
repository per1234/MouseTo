// MouseTo - Library for Arduino Leonardo/Micro for moving the mouse pointer to absolute screen coordinates: http://github.com/per1234/MouseTo
#include "MouseTo.h"


MouseToClass::MouseToClass() {
  //set default values
  screenResolutionX = 3840;  //4K UHD
  screenResolutionY = 2160;  //4K UHD
  correctionFactor = 1;
  jumpDistance = 10;  //this seems like a good balance between speed and accuracy
}


void MouseToClass::setTarget(const int targetXinput, const int targetYinput, const boolean homeFirst) {
  //convert screen coordinates to Arduino coordinates
  targetX = targetXinput * correctionFactor;
  targetY = targetYinput * correctionFactor;
  homed = !homeFirst;
}


int MouseToClass::getTargetX() {
  return targetX;
}


int MouseToClass::getTargetY() {
  return targetY;
}


//used for compatibility with the previous API
boolean MouseToClass::moveTo(const int targetXinput, const int targetYinput) {
  setTarget(targetXinput, targetYinput);
  return move();
}


boolean MouseToClass::move() {
  //the mouse is homed to 0,0 on each mouse movement to make sure the absolute screen coordinates will be reached even if the physical mouse has been moved since the last moveTo
  int moveToTargetX;
  int moveToTargetY;
  if (homed == false) {
    //make sure it reaches 0,0 even in the worst case scenario of the cursor being at the bottom right corner
    moveToTargetX = -screenResolutionX - 50;
    moveToTargetY = -screenResolutionY - 50;
  }
  else {
    moveToTargetX = targetX;
    moveToTargetY = targetY;
  }

  if (positionX != moveToTargetX || positionY != moveToTargetY) {
    if (positionX != moveToTargetX && (positionY == moveToTargetY || (positionY != moveToTargetY && moveAxisX == true))) {
      const int moveX = moveToTargetX > positionX ? min(jumpDistance, moveToTargetX - positionX) : max(-jumpDistance, moveToTargetX - positionX);
      Mouse.move(moveX, 0, 0);
      positionX += moveX;
      moveAxisX = false;
    }
    else {
      const int moveY = moveToTargetY > positionY ? min(jumpDistance, moveToTargetY - positionY) : max(-jumpDistance, moveToTargetY - positionY);
      Mouse.move(0, moveY, 0);
      positionY += moveY;
      moveAxisX = true;
    }
  }
  else { //home or target position reached
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

void MouseToClass::home() {
  homed = false;
}

MouseToClass MouseTo;  //This sets up a single global instance of the library so the class doesn't need to be declared in the user sketch and multiple instances are not necessary in this case.

