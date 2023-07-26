#include "human.h"

void CHuman::DrawTo(HDC hdc) const
{if(Status != DEAD) SetPixel(hdc, XPos, YPos, Color);
 else
  Ellipse(hdc, XPos - BloodRadius, YPos - BloodRadius,
	       XPos + BloodRadius, YPos + BloodRadius);
}

void CHuman::Think(double xx, double yy, double last_think)
{double Angle, Distance = sqrt(pow(xx - XPos, 2) + pow(yy - YPos, 2));

 switch(Status)
 {case CONTROLLED:
	 TimeLeft -= last_think;
	 if(TimeLeft < 0.0){Walk(); break;}
	 XPos += cos(Direction) * Speed * last_think;
	 YPos += sin(Direction) * Speed * last_think;
	 if(Distance < 5.0) Die();
	 break;
  case WALKING:
         if(Distance < 200.0){BeCautious(); break;}
	 TimeLeft -= last_think;
	 if(TimeLeft < 0.0)
	 {TimeLeft = (rand()%2000)/1000.0 + 1.0;
	  Direction = (rand()%628)/100.0;
	 }
	 XPos += cos(Direction) * Speed * last_think;
	 YPos += sin(Direction) * Speed * last_think;
	 if(Distance < 5.0) Die();
         break;
  case CAUTIOUS:
	 if(Distance > 200.0) Walk();else if(Distance < 130.0) Run();
	 break;
  case RUNNING:
	 if(Distance > 140.0){BeCautious(); break;}
	 Angle = atan2(YPos - yy, XPos - xx);
	 XPos += cos(Angle) * Speed * last_think;
	 YPos += sin(Angle) * Speed * last_think;
         if(Distance < 5.0) Die();
	 break;
  case DEAD:
         if(BloodRadius < 3)
         {TimeLeft -= last_think;
          if(TimeLeft < 0){TimeLeft = 0.3; BloodRadius++;}
         }
 }
}

void CHuman::MoveTo(int xx, int yy, double v)
{if(Status != DEAD)
 {Speed = v;
  Status = CONTROLLED;
  Direction = atan2(yy - YPos, xx - XPos);
  TimeLeft = sqrt(pow(XPos - xx, 2) + pow(YPos - yy, 2))/Speed;
 }
}
