#include <windows.h>
#include <stdio.h>

HWND   win;
HDC    hdc,ArkaPlan,TamPlan;
HBRUSH boya;
HPEN   kalem;

short x,y,ClientW,ClientH;
char s[128] = {0},a[8][8],A[8][8],oy[61],el[61][8][8];
char i,j,ii,jj,m,n,say1,say2,el_say,oyuncu,nesne,var;

void Koy_Oyun()
{BitBlt(TamPlan,0,0,ClientW,ClientH,ArkaPlan,0,0,SRCCOPY);
 say1 = 0; say2 = 0;
 kalem = CreatePen(PS_SOLID,1,0xffffff); SelectObject(TamPlan,kalem);
 boya  = CreateSolidBrush(0xffffff);     SelectObject(TamPlan,boya);
 for(i=0;i<8;i++)for(j=0;j<8;j++)if(a[i][j]==1)
 {Ellipse(TamPlan,60*i+25,60*j+25,60*i+75,60*j+75);
  say1++;
 }
 if(oyuncu == 1)
 {Ellipse(TamPlan,575,120,645,190);
  SetBkColor(TamPlan,0xffffff);  SetTextColor(TamPlan,0x000000);
 }
 kalem = CreatePen(PS_SOLID,1,0x000000); SelectObject(TamPlan,kalem);
 boya  = CreateSolidBrush(0x000000);     SelectObject(TamPlan,boya);
 for(i=0;i<8;i++)for(j=0;j<8;j++)if(a[i][j]==2)
 {Ellipse(TamPlan,60*i+25,60*j+25,60*i+75,60*j+75);
  say2++;
 }
 if(oyuncu == 2)
 {Ellipse(TamPlan,575,120,645,190);
  SetBkColor(TamPlan,0x000000);  SetTextColor(TamPlan,0xffffff);
 }
 sprintf(s,"OYUNCU");
 TextOut(TamPlan,581,148,s,strlen(s));
 SetBkColor(TamPlan,0xffff00);
 SetTextColor(TamPlan,0xff00ff);
 sprintf(s,"PUANLAR  --->  %02d : %02d",say1,say2);
 TextOut(TamPlan,540,90,s,strlen(s));
 say1 = 0; say2 = 0;
 for(i=0;i<el_say;i++)if(oy[i]==1)say1++;else say2++;
 sprintf(s,"%02d . El  ( %02d : %02d )",el_say,say1,say2);
 TextOut(TamPlan,556,235,s,strlen(s));
 BitBlt(hdc,0,0,ClientW,ClientH,TamPlan,0,0,SRCCOPY);
 for(i=0;i<8;i++)for(j=0;j<8;j++)el[el_say][i][j]=a[i][j];
 oy[el_say]=oyuncu;
}

void Yeni_Oyun()
{for(i=0;i<8;i++)for(j=0;j<8;j++)a[i][j]=0;
 a[3][4]=1;  a[4][3]=1;  a[3][3]=2;  a[4][4]=2;
 oyuncu = 1; el_say=0;
 Koy_Oyun();
}

void Kontrol_Durum()
{if(ii<6)
 {var=0;
  for(i=ii+1;i<8;i++)
   if(a[i][jj]==nesne)var++;else
   {if(var && a[i][jj]==oyuncu)for(m=ii+1;m<i;m++)A[m][jj]=oyuncu;
    break;
   }
 }
 if(ii>1)
 {var=0;
  for(i=ii-1;i>=0;i--)
   if(a[i][jj]==nesne)var++;else
   {if(var && a[i][jj]==oyuncu)for(m=ii-1;m>i;m--)A[m][jj]=oyuncu;
    break;
   }
 }
 if(jj<6)
 {var=0;
  for(j=jj+1;j<8;j++)
   if(a[ii][j]==nesne)var++;else
   {if(var && a[ii][j]==oyuncu)for(m=jj+1;m<j;m++)A[ii][m]=oyuncu;
    break;
   }
 }
 if(jj>1)
 {var=0;
  for(j=jj-1;j>=0;j--)
   if(a[ii][j]==nesne)var++;else
   {if(var && a[ii][j]==oyuncu)for(m=jj-1;m>j;m--)A[ii][m]=oyuncu;
    break;
   }
 }
 if(ii<6 && jj<6)
 {var=0;
  for(i=ii+1,j=jj+1; i<8 && j<8; i++,j++)
   if(a[i][j]==nesne)var++;else
   {if(var && a[i][j]==oyuncu)for(m=ii+1,n=jj+1; m<i; m++,n++)A[m][n]=oyuncu;
    break;
   }
 }
 if(ii>1 && jj>1)
 {var=0;
  for(i=ii-1,j=jj-1; i>=0 && j>=0; i--,j--)
   if(a[i][j]==nesne)var++;else
   {if(var && a[i][j]==oyuncu)for(m=ii-1,n=jj-1; m>i; m--,n--)A[m][n]=oyuncu;
    break;
   }
 }
 if(ii>1 && jj<6)
 {var=0;
  for(i=ii-1,j=jj+1; i>=0 && j<8; i--,j++)
   if(a[i][j]==nesne)var++;else
   {if(var && a[i][j]==oyuncu)for(m=ii-1,n=jj+1; m>i; m--,n++)A[m][n]=oyuncu;
    break;
   }
 }
 if(ii<6 && jj>1)
 {var=0;
  for(i=ii+1,j=jj-1; i<8 && j>=0; i++,j--)
   if(a[i][j]==nesne)var++;else
   {if(var && a[i][j]==oyuncu)for(m=ii+1,n=jj-1; m<i; m++,n--)A[m][n]=oyuncu;
    break;
   }
 }
}

void Oyna_Oyun()
{if(x>19 && x<500 && y>19 && y<500)
 {ii = (x-20)/60;     jj = (y-20)/60;
  if(a[ii][jj])return;
  if(oyuncu==1)nesne = 2;else nesne = 1;
  for(i=0;i<8;i++)for(j=0;j<8;j++)A[i][j]=0;
  Kontrol_Durum();
  var=0;
  for(i=0;i<8;i++)for(j=0;j<8;j++)if(A[i][j])var++;
  if(var)
  {a[ii][jj] = oyuncu;
   el_say++;
   if(oyuncu==1)oyuncu=2;else oyuncu=1;
   for(i=0;i<8;i++)for(j=0;j<8;j++)if(A[i][j])a[i][j]=A[i][j];
   Koy_Oyun();
   if(oyuncu==1)
   {kalem = CreatePen(PS_SOLID,1,0xffffff);  boya  = CreateSolidBrush(0xffffff);
   }else
   {kalem = CreatePen(PS_SOLID,1,0x000000);  boya  = CreateSolidBrush(0x000000);
   }
   SelectObject(hdc,kalem);   SelectObject(hdc,boya);
   for(i=0;i<8;i++)for(j=0;j<8;j++)
    if(A[i][j])Ellipse(hdc,60*i+25,60*j+25,60*i+75,60*j+75);
   if(oyuncu==1)
   {kalem = CreatePen(PS_SOLID,1,0x000000);  boya  = CreateSolidBrush(0x000000);
   }else
   {kalem = CreatePen(PS_SOLID,1,0xffffff);  boya  = CreateSolidBrush(0xffffff);
   }
   SelectObject(hdc,kalem);   SelectObject(hdc,boya);
   for(m=1;m<26;m++)
   {Sleep(40);
    for(i=0;i<8;i++)for(j=0;j<8;j++)
     if(A[i][j])Ellipse(hdc,60*i+50-m,60*j+50-m,60*i+50+m,60*j+50+m);
   }
  }
 }
 else if(x>539 && x<681 && y>29 && y<71)Yeni_Oyun();
 else if(x>539 && x<681 && y>259 && y<301 && el_say)
 {el_say--;
  for(i=0;i<8;i++)for(j=0;j<8;j++)a[i][j]=el[el_say][i][j];
  oyuncu = oy[el_say];
  Koy_Oyun();
 }
 else if(x>539 && x<681 && y>329 && y<371)
 {if(oyuncu==1)oyuncu=2;else oyuncu=1;
  Koy_Oyun();
 }
 else if(x>539 && x<681 && y>399 && y<441)
 {if(oyuncu==1)nesne = 2;else nesne = 1;
  SetBkColor(hdc,0x00ff00);  SetTextColor(hdc,0x0000ff);
  for(ii=0;ii<8;ii++)for(jj=0;jj<8;jj++)if(a[ii][jj]==0)
  {for(i=0;i<8;i++)for(j=0;j<8;j++)A[i][j]=0;
   Kontrol_Durum();
   var=0;
   for(i=0;i<8;i++)for(j=0;j<8;j++)if(A[i][j])var++;
   if(var)
   {sprintf(s,"%02d",var);
    TextOut(hdc,60*ii+45,60*jj+45,s,strlen(s));
   }
  }
 }
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{switch(message)
 {case WM_CLOSE       : DestroyWindow(hwnd); return 0;
  case WM_DESTROY     : PostQuitMessage(0);  return 0;
  case WM_LBUTTONDOWN : x = LOWORD(lParam);  y = HIWORD(lParam);
                        Oyna_Oyun();         return 0;
  default : return DefWindowProc(hwnd,message,wParam,lParam);
 }
}

void Baslat_Uyg(HINSTANCE hInst, int iShow)
{const char *ClassName  = "Hasan Temurtaþ";
 WNDCLASS Pencere;
 Pencere.style  = CS_HREDRAW | CS_VREDRAW;
 Pencere.lpfnWndProc = WndProc;
 Pencere.cbClsExtra  = 0;
 Pencere.cbWndExtra  = 0;
 Pencere.hInstance   = hInst;
 Pencere.hIcon   = LoadIcon(NULL,IDI_APPLICATION);
 Pencere.hCursor = LoadCursor(NULL,IDC_ARROW);
 Pencere.hbrBackground = GetStockObject(WHITE_BRUSH);
 Pencere.lpszMenuName  = NULL;
 Pencere.lpszClassName = ClassName;
 RegisterClass(&Pencere);
 win = CreateWindow(ClassName,"T E M U R T A Þ",WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE,
                  150,100,720,545,NULL,NULL,hInst,NULL);
 ShowWindow(win, iShow);
 UpdateWindow(win);

 hdc = GetDC(win);

 RECT   rect;
 GetClientRect(win, &rect);
 ClientW = rect.right;
 ClientH = rect.bottom;

 HBITMAP hBitMap;
 ArkaPlan = CreateCompatibleDC(NULL);
 hBitMap  = CreateCompatibleBitmap(hdc, ClientW, ClientH);
 SelectObject(ArkaPlan,hBitMap);
 TamPlan  = CreateCompatibleDC(NULL);
 hBitMap  = CreateCompatibleBitmap(hdc, ClientW, ClientH);
 SelectObject(TamPlan, hBitMap);

 FillRect(ArkaPlan,&rect,CreateSolidBrush(0xffff00));

 rect.left = 17; rect.right  = 503;
 rect.top  = 17; rect.bottom = 503;
 FillRect(ArkaPlan,&rect,CreateSolidBrush(0xff0000));

 boya  = CreateSolidBrush(0x00ff00);     SelectObject(ArkaPlan,boya);
 kalem = CreatePen(PS_SOLID,1,0xff0000); SelectObject(ArkaPlan,kalem);
 for(j=0;j<8;j++)for(i=0;i<8;i++)
  Rectangle(ArkaPlan,60*i+20,60*j+20,60*i+80,60*j+80);

 boya  = CreateSolidBrush(0xaaffff);     SelectObject(ArkaPlan,boya);
 kalem = CreatePen(PS_SOLID,3,0x0000ff); SelectObject(ArkaPlan,kalem);

 SetBkColor(ArkaPlan,0xaaffff);
 SetTextColor(ArkaPlan,0xff0000);

 Rectangle(ArkaPlan,540,30,680,70);
 sprintf(s,"Y E N Ý    O Y U N");
 TextOut(ArkaPlan,554,43,s,strlen(s));

 Rectangle(ArkaPlan,540,260,680,300);
 sprintf(s,"<----   Önceki   El");
 TextOut(ArkaPlan,550,273,s,strlen(s));

 Rectangle(ArkaPlan,540,330,680,370);
 sprintf(s,"El Deðiþtir");
 TextOut(ArkaPlan,575,343,s,strlen(s));

 Rectangle(ArkaPlan,540,400,680,440);
 sprintf(s,"Kontrol");
 TextOut(ArkaPlan,588,413,s,strlen(s));

 BitBlt(hdc,0,0,ClientW,ClientH,ArkaPlan,0,0,SRCCOPY);
}

WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int iShow)
{MSG  msg;
 Baslat_Uyg(hInst,iShow);
 Yeni_Oyun();
 while(GetMessage(&msg,NULL,0,0) > 0)
 {TranslateMessage(&msg);
  DispatchMessage(&msg);
 }
 return msg.wParam ;
}
