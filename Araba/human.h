#ifndef HUMAN_H
#define HUMAN_H

#include <windows.h>
#include <math.h>
#include <stdlib.h>

enum{WALKING = 1, CAUTIOUS = 2, RUNNING = 3, DEAD = 4, CONTROLLED = 5};

class CHuman
{ private:
    double XPos, YPos, Direction, Speed, TimeLeft;
    int Status, BloodRadius;
    COLORREF Color;
    void BeCautious(){Status = CAUTIOUS; Speed = 0;}
    void Walk(){Status = WALKING; Speed = 10;}
    void Run(){Status = RUNNING; Speed = 30;}
    void Die(){Status = DEAD; Speed = 0; TimeLeft = 0.3;}
 public:
    CHuman(double xx, double yy, CHuman *next):
          XPos(xx), YPos(yy), Speed(0), Direction(0), TimeLeft(0), Status(0),
          BloodRadius(1), Color(RGB( 255, 255, 255)), sonraki(next)
    {Walk();}
    ~CHuman(){delete sonraki;}
    void DrawTo(HDC hdc) const;
    void Think(double xx, double yy, double last_think);
    void MoveTo(int xx, int yy, double v);
    CHuman *sonraki;
};

#endif
