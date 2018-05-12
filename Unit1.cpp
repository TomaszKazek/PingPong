#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

float vHorizontal=7,vVertical=0;

void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
//move ball
ball->Top+=vVertical;
ball->Left+=vHorizontal;

//baunce
if(ball->Top+ball->Height>=background->Top+background->Height)
{
vVertical*=-1;
vVertical-=1;
}

//fail
if((ball->Left<=background->Left)||(ball->Left+ball->Width>=background->Left+background->Width))
vHorizontal*=-1;
//ballTimer->Enabled=false;

if((net->Top<=ball->Top+ball->Height)&&(ball->Left<=net->Left+net->Width)&&(ball->Left+ball->Width>=net->Left))
ballTimer->Enabled=false;

//leftPaddle
if((ball->Left<=leftPaddle->Left+leftPaddle->Width)&&(ball->Top+ball->Height>=leftPaddle->Top)&&(ball->Top<=leftPaddle->Top+leftPaddle->Height))
vHorizontal*=-1;

//rightPaddle
if((ball->Left+ball->Width>=rightPaddle->Left)&&(ball->Top+ball->Height>=rightPaddle->Top)&&(ball->Top<=rightPaddle->Top+rightPaddle->Height))
vHorizontal*=-1;

//gravity
vVertical+=1;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x57) leftPaddle->Top-=20;
        if(Key==0x53) leftPaddle->Top+=20;

        if(Key==VK_UP) rightPaddle->Top-=20;
        if(Key==VK_DOWN) rightPaddle->Top+=20;
}
//---------------------------------------------------------------------------

