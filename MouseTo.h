// MouseTo - Library for Arduino Leonardo/Micro for moving the mouse pointer to absolute screen coordinates: http://github.com/per1234/MouseTo
#ifndef MouseTo_h
#define MouseTo_h

#include <Arduino.h>
#if ARDUINO > 10605
#include <Mouse.h>
#endif  //ARDUINO > 10605

class MouseToClass {
  public:
    MouseToClass();
    boolean moveTo(int targetX, int targetY);
    void setScreenResolution(const int x, const int y);
    unsigned int getScreenResolutionX();
    unsigned int getScreenResolutionY();
    void setCorrectionFactor(const float correctionFactorInput);
    float getCorrectionFactor();
    void setMaxJump(const int8_t jumpDistanceInput);
    int8_t getMaxJump();
    void home();
  private:
    int positionX;
    int positionY;
    boolean homed;
    int screenResolutionX;
    int screenResolutionY;
    float correctionFactor;
    int8_t jumpDistance;
};
extern MouseToClass MouseTo;  //declare the class so it doesn't have to be done in the sketch
#endif  //MouseTo_h

