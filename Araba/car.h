#ifndef CAR_H
#define CAR_H

#include <windows.h>
#include <math.h>

class CCar
{private:
    double XPos, YPos, Direction, Speed;
 public:
    CCar(){XPos = 400; YPos = 200; Direction = 0.8; Speed = 0;}
    ~CCar(){}
    double GetXPos() const {return XPos;}
    double GetYPos() const {return YPos;}
    void Move(double last_move);
    void DrawTo(HDC hdc) const;
};

#endif