#include <windows.h>
#include "human.h"
#include "car.h"

const int Max_Human = 500;

CHuman	*humans;
CCar	*car;
HDC	hdc_1, hdc_2;
HBITMAP	hBitMap_1, hBitMap_2;
HBRUSH	Brush;
HPEN	Pen;
int     ClientW, ClientH;// FareX, FareY;

LRESULT CALLBACK MsgHandler(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{switch(Msg)
 {case WM_CLOSE:    DestroyWindow(hWnd);  return 0;
  case WM_DESTROY:  PostQuitMessage(1);   return 0;
  /*
  case WM_KILLFOCUS:   return 0;
  case WM_SETFOCUS:    return 0;
  case WM_LBUTTONDOWN: return 0;
  case WM_RBUTTONDOWN: return 0;
  case WM_MOUSEMOVE:   return 0;
         FareX = LOWORD(lParam); FareY = HIWORD(lParam); return 0;
   case WM_SIZE:
	 ClientW = LOWORD(lParam);
	 ClientH = HIWORD(lParam);
	 DeleteObject(hBitMap_1);
	 hBitMap_1 = CreateCompatibleBitmap(GetDC(hWnd), ClientW, ClientH);
	 SelectObject(hdc_1, hBitMap_1);
         return 0;
  */
  default: return DefWindowProc(hWnd, Msg, wParam, lParam);
 }
}

HWND InitApp(HINSTANCE hInstance)
{const char *Uyg_ismi = "Hasan Temurtaþ";
 HWND hWnd;
 RECT rect;

 WNDCLASSEX Pencere;
 Pencere.cbClsExtra = 0;
 Pencere.cbSize = sizeof(WNDCLASSEX);
 Pencere.cbWndExtra = 0;
 Pencere.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
 Pencere.hCursor = LoadCursor(NULL, IDC_ARROW);
 Pencere.hIcon = NULL;
 Pencere.hIconSm = NULL;
 Pencere.hInstance = hInstance;
 Pencere.lpfnWndProc = MsgHandler;
 Pencere.lpszClassName = Uyg_ismi;
 Pencere.lpszMenuName = NULL;
 Pencere.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
 RegisterClassEx(&Pencere);

 hWnd = CreateWindowEx(NULL, Uyg_ismi, Uyg_ismi,
               WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE,
	       115, 80, 800, 600, NULL, NULL, hInstance, NULL);

 GetClientRect(hWnd, &rect);
 ClientW = rect.right;
 ClientH = rect.bottom;

 srand(GetTickCount());

 for(int i = 0; i < Max_Human; i++)
    humans = new CHuman(rand()%ClientW, rand()%ClientH, humans);

 car = new CCar();

 Pen = CreatePen(1, 1, RGB(200, 0, 0));
 Brush = CreateSolidBrush(RGB(200, 0, 0));

 hdc_1 = CreateCompatibleDC(0);
 hBitMap_1 = CreateCompatibleBitmap(GetDC(hWnd), ClientW, ClientH);
 SelectObject(hdc_1, hBitMap_1);
 SelectObject(hdc_1, Pen);
 SelectObject(hdc_1, Brush);

 hdc_2 = CreateCompatibleDC(0);
 hBitMap_2 = LoadImage(NULL, "gfx\\ground.bmp", IMAGE_BITMAP,
		     0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
 SelectObject(hdc_2, hBitMap_2);

 return hWnd;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{HWND	hWnd = InitApp(hInst);
 MSG   	Msg;
 DWORD	zaman;
 double gec;
 CHuman	*current;

 ShowWindow(hWnd, nCmdShow);
 UpdateWindow(hWnd);

 zaman = GetTickCount();

 while(true)
 {if(PeekMessage(&Msg, 0, 0, 0, PM_REMOVE))
  {if(Msg.message == WM_QUIT) return Msg.wParam;
   TranslateMessage(&Msg);
   DispatchMessage(&Msg);
  }

  gec = (GetTickCount() - zaman)/1000.0;
  if(gec > 0.02)
  {BitBlt(hdc_1, 0, 0, ClientW, ClientH, hdc_2, 0, 0, SRCCOPY);
   car->Move(gec);
   car->DrawTo(hdc_1);
   for(current = humans; current; current = current->sonraki)
   {current->Think(car->GetXPos(), car->GetYPos(), gec);
    current->DrawTo(hdc_1);
   }
   BitBlt(GetDC(hWnd), 0, 0, ClientW, ClientH, hdc_1, 0, 0, SRCCOPY);
   zaman = GetTickCount();
  }

 }
}
