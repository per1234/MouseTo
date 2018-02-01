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
    void setTarget(const int targetXinput, const int targetYinput, const boolean homeFirst = true);
    int getTargetX();
    int getTargetY();
    boolean moveTo(const int targetXinput, const int targetYinput);
    boolean move();
    void setScreenResolution(const int x, const int y);
    unsigned int getScreenResolutionX();
    unsigned int getScreenResolutionY();
    void setCorrectionFactor(const float correctionFactorInput);
    float getCorrectionFactor();
    void setMaxJump(const int8_t jumpDistanceInput);
    int8_t getMaxJump();
    void home();
  private:
    int targetX;
    int targetY;
    int positionX;
    int positionY;
    boolean homed;
    int screenResolutionX;
    int screenResolutionY;
    float correctionFactor;
    int8_t jumpDistance;
    boolean moveAxisX;
};
extern MouseToClass MouseTo;  //declare the class so it doesn't have to be done in the sketch
#endif  //MouseTo_h
