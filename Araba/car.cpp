#include "car.h"

void CCar::Move(double last_move)
{if(GetAsyncKeyState(VK_LEFT)) Direction -= 0.02 * Speed * last_move;
 if(GetAsyncKeyState(VK_RIGHT))Direction += 0.02 * Speed * last_move;
 if(GetAsyncKeyState(VK_UP) && Speed < 120) Speed += 250 * last_move;
 if(GetAsyncKeyState(VK_DOWN))
 {Speed -= 500 * last_move;
  if(Speed < 0) Speed = 0;
 }
 XPos += cos(Direction ) * Speed * last_move;
 YPos += sin(Direction ) * Speed * last_move;
}

void CCar::DrawTo(HDC hdc) const
{MoveToEx(hdc, XPos + 7*cos(Direction - 0.66), YPos + 7*sin(Direction - 0.66), NULL);
   LineTo(hdc, XPos + 7*cos(Direction - 2.50), YPos + 7*sin(Direction - 2.50));
   LineTo(hdc, XPos + 7*cos(Direction + 2.50), YPos + 7*sin(Direction + 2.50));
   LineTo(hdc, XPos + 7*cos(Direction + 0.66), YPos + 7*sin(Direction + 0.66));
   LineTo(hdc, XPos + 7*cos(Direction - 0.66), YPos + 7*sin(Direction - 0.66));
}
