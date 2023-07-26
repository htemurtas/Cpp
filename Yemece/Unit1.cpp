//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char oyuncu,a[8][8],A[8][8];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{Width     = 740;  Height     = 605;
 B2->Left  = 250;  B2->Top    = 230;
 B2->Width = 240;  B2->Height = 125;
 B1->Left  = 592;  B1->Top    = 56;
 L1->Left  = 600;  L1->Top    = 250;
 L2->Left  = 600;  L2->Top    = 270;
 L3->Left  = 588;  L3->Top    = 136;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B2Click(TObject *Sender)
{B2->Visible = false;  B1->Click();
 B1->Visible = true;   L1->Visible = true;
 L2->Visible = true;   L3->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B1Click(TObject *Sender)
{short i,j;
 Canvas->Pen->Width   = 5;
 Canvas->Pen->Color   = (TColor)0xee0000;
 Canvas->Brush->Color = (TColor)0x33cccc;
 Canvas->Rectangle(27,27,553,553);
 Canvas->Pen->Width   = 1;
 for(i=0;i<8;i++)for(j=0;j<8;j++)
 {a[i][j]=0;
  Canvas->Rectangle(65*i+30,65*j+30,65*i+95,65*j+95);
 }
 Canvas->Pen->Color   = (TColor)0x000000;
 Canvas->Brush->Color = (TColor)0x000000;
 i=3; j=4; a[i][j]=2; Canvas->Ellipse(65*i+35,65*j+35,65*i+90,65*j+90);
 i=4; j=3; a[i][j]=2; Canvas->Ellipse(65*i+35,65*j+35,65*i+90,65*j+90);
 Canvas->Pen->Color   = (TColor)0xffffff;
 Canvas->Brush->Color = (TColor)0xffffff;
 i=3; j=3; a[i][j]=1; Canvas->Ellipse(65*i+35,65*j+35,65*i+90,65*j+90);
 i=4; j=4; a[i][j]=1; Canvas->Ellipse(65*i+35,65*j+35,65*i+90,65*j+90);
 oyuncu=1;
 L3->Font->Color = (TColor)0xffffff;
 Canvas->Ellipse(625,160,680,215);
 L1->Caption ="Beyaz : 2";
 L2->Caption ="Siyah : 2";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{char nesne,say1,say2,var,toplam;
 short i,j,m,n,ii,jj;
 int renk,renk_ek;

 if(X<30 || Y<30 || X>549 || Y>549)return;
 ii = (X-30)/65;  jj = (Y-30)/65;
 if(a[ii][jj])return;

 if(oyuncu==1) nesne = 2; else nesne = 1;

 for(i=0;i<8;i++)for(j=0;j<8;j++)A[i][j]=0;

 var=0;
 if(ii<6)
  for(i=ii+1;i<8;i++)
   if(a[i][jj]==nesne)var++;
   else
   {if(var && a[i][jj]==oyuncu)
     for(m=ii+1;m<i;m++)A[m][jj]=oyuncu;
    break;
   }
 var=0;
 if(ii>1)
  for(i=ii-1;i>=0;i--)
   if(a[i][jj]==nesne)var++;
   else
   {if(var && a[i][jj]==oyuncu)
     for(m=ii-1;m>i;m--)A[m][jj]=oyuncu;
    break;
   }
 var=0;
 if(jj<6)
  for(j=jj+1;j<8;j++)
   if(a[ii][j]==nesne)var++;
   else
   {if(var && a[ii][j]==oyuncu)
     for(m=jj+1;m<j;m++)A[ii][m]=oyuncu;
    break;
   }
 var=0;
 if(jj>1)
  for(j=jj-1;j>=0;j--)
   if(a[ii][j]==nesne)var++;
   else
   {if(var && a[ii][j]==oyuncu)
     for(m=jj-1;m>j;m--)A[ii][m]=oyuncu;
    break;
   }
 var=0;
 if(ii<6 && jj<6)
  for(i=ii+1,j=jj+1; i<8 || j<8; i++,j++)
   if(a[i][j]==nesne)var++;
   else
   {if(var && a[i][j]==oyuncu)
     for(m=ii+1,n=jj+1; m<i || n<j; m++,n++)A[m][n]=oyuncu;
    break;
   }
 var=0;
 if(ii>1 && jj>1)
  for(i=ii-1,j=jj-1; i>=0 || j>=0; i--,j--)
   if(a[i][j]==nesne)var++;
   else
   {if(var && a[i][j]==oyuncu)
     for(m=ii-1,n=jj-1; m>i || n>j; m--,n--)A[m][n]=oyuncu;
    break;
   }
 var=0;
 if(ii>1 && jj<6)
  for(i=ii-1,j=jj+1; i>=0 || j<8; i--,j++)
   if(a[i][j]==nesne)var++;
   else
   {if(var && a[i][j]==oyuncu)
     for(m=ii-1,n=jj+1; m>i || n<j; m--,n++)A[m][n]=oyuncu;
    break;
   }
 var=0;
 if(ii<6 && jj>1)
  for(i=ii+1,j=jj-1; i<8 || j>=0; i++,j--)
   if(a[i][j]==nesne)var++;
   else
   {if(var && a[i][j]==oyuncu)
     for(m=ii+1,n=jj-1; m<i || n>j; m++,n--)A[m][n]=oyuncu;
    break;
   }

 toplam=0;
 for(i=0;i<8;i++)for(j=0;j<8;j++)if(A[i][j])toplam++;
 if(!toplam)return;

 say1=0;say2=0;
 A[ii][jj]=oyuncu;
 for(i=0;i<8;i++)for(j=0;j<8;j++)
 {if(A[i][j])a[i][j]=A[i][j];
  if(a[i][j]==1)say1++;else if(a[i][j]==2)say2++;
 }
 L1->Caption ="Beyaz : "+IntToStr(say1);
 L2->Caption ="Siyah : "+IntToStr(say2);

 if(oyuncu==1)
 {renk=0x000000;  renk_ek=0x111111;}
 else if(oyuncu==2)
 {renk=0xffffff;  renk_ek=-0x111111;}

 Canvas->Pen->Color   = (TColor)renk;
 Canvas->Brush->Color = (TColor)renk;
 L3->Font->Color  = (TColor)renk;
 Canvas->Ellipse(625,160,680,215);

 for(m=1;m<16;m++)
 {Sleep(100);
  renk+=renk_ek;
  Canvas->Pen->Color   = (TColor)renk;
  Canvas->Brush->Color = (TColor)renk;
  for(i=0;i<8;i++)for(j=0;j<8;j++)
   if(A[i][j])Canvas->Ellipse(65*i+35,65*j+35,65*i+90,65*j+90);
 }

 if(oyuncu==1)oyuncu=2;else oyuncu=1;
}
//---------------------------------------------------------------------------

