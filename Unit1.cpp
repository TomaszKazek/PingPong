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
ShowMessage("cos");
}
//---------------------------------------------------------------------------

float vHorizontal=10,vVertical=0, faster=1.1;
int bounceCounter=-1, leftPoints=0, rightPoints=0, x=-15;
AnsiString side="left", lastTouch="left";
bool leftPaddleActive=true, rightPaddleActive=true;

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
bounceCounter+=1;
bounceTab->Caption=IntToStr(bounceCounter);
}

//fail
if(
(lastTouch=="left")
&&(
(ball->Left+ball->Width>=background->Left+background->Width&&bounceCounter==0)
||
((net->Top<=ball->Top+ball->Height)&&(ball->Left<=net->Left+net->Width)&&(ball->Left+ball->Width>=net->Left))
||
(side=="left"&&bounceCounter==1)
)
||
(lastTouch=="right"&&side=="left"&&bounceCounter>1)
||
(lastTouch=="right"&&ball->Left<=background->Left&&bounceCounter==1)
)
{
ballTimer->Enabled=false;
bounceTab->Caption=lastTouch+" "+side+" "+IntToStr(bounceCounter);
rightPoints+=1;
rightTab->Caption=IntToStr(rightPoints);
ball->Top=250;
ball->Left=background->Width-rightPaddle->Width;
vVertical=0;
vHorizontal=-10;
lastTouch="right";
}

if(
(lastTouch=="right")
&&(
(ball->Left<=background->Left&&bounceCounter==0)
||
((net->Top<=ball->Top+ball->Height)&&(ball->Left<=net->Left+net->Width)&&(ball->Left+ball->Width>=net->Left))
||
(side=="right"&&bounceCounter==1)
)
||
(lastTouch=="left"&&side=="right"&&bounceCounter>1)
||
(lastTouch=="left"&&ball->Left+ball->Width>=background->Left+background->Width&&bounceCounter==1)
)
{
ballTimer->Enabled=false;
bounceTab->Caption=lastTouch+" "+side+" "+IntToStr(bounceCounter);
leftPoints+=1;
leftTab->Caption=IntToStr(leftPoints);
ball->Top=250;
ball->Left=30;
vVertical=0;
vHorizontal=10;
lastTouch="left";
}




//leftPaddle
if((ball->Left<=leftPaddle->Left+leftPaddle->Width)&&(ball->Top+ball->Height>=leftPaddle->Top)&&(ball->Top<=leftPaddle->Top+leftPaddle->Height))
{
//vHorizontal=abs(vHorizontal);
//vVertical=abs(vVertical)*-1;
if (LeftUp3->Visible==true) {vHorizontal=21; vVertical=-21;}
if (LeftUp2->Visible==true) {vHorizontal=19; vVertical=-19;}
if (LeftUp1->Visible==true) {vHorizontal=17; vVertical=-17;}
if (LeftUp1->Visible==false && LeftDown1->Visible==false) {vHorizontal=15; vVertical=-15;}
if (LeftDown1->Visible==true) {vHorizontal=14; vVertical=-14;}
if (LeftDown2->Visible==true) {vHorizontal=13; vVertical=-13;}
if (LeftDown3->Visible==true) {vHorizontal=12; vVertical=-12;}
leftPaddleActive=false;
lastTouch="left";
bounceCounter=0;
}

//rightPaddle
if((ball->Left+ball->Width>=rightPaddle->Left)&&(ball->Top+ball->Height>=rightPaddle->Top)&&(ball->Top<=rightPaddle->Top+rightPaddle->Height))
{
//vHorizontal=abs(vHorizontal)*-1;
//vVertical=abs(vVertical)*-1;
if (RightUp3->Visible==true) {vHorizontal=-21; vVertical=-21;}
if (RightUp2->Visible==true) {vHorizontal=-19; vVertical=-19;}
if (RightUp1->Visible==true) {vHorizontal=-17; vVertical=-17;}
if (RightUp1->Visible==false && RightDown1->Visible==false) {vHorizontal=-15; vVertical=-15;}
if (RightDown1->Visible==true) {vHorizontal=-14; vVertical=-14;}
if (RightDown2->Visible==true) {vHorizontal=-13; vVertical=-13;}
if (RightDown3->Visible==true) {vHorizontal=-12; vVertical=-12;}
rightPaddleActive=false;
lastTouch="right";
bounceCounter=0;
}

//gravity
vVertical+=1;

//side

if (ball->Left+0.5*ball->Width>background->Left+0.5*background->Width)
{
if (side=="left")
{
rightPaddleActive=true;
bounceCounter=0;
}
side="right";
}
if (ball->Left+0.5*ball->Width<background->Left+0.5*background->Width)
{
if (side=="right")
{
leftPaddleActive=true;
bounceCounter=0;
}
side="left";
}
whatSide->Caption=side+" "+lastTouch;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x57) leftUP->Enabled=true;
        if(Key==0x53) leftDOWN->Enabled=true;

        if(Key==VK_UP) rightUP->Enabled=true;
        if(Key==VK_DOWN) rightDOWN->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x57) leftUP->Enabled=false;
        if(Key==0x53) leftDOWN->Enabled=false;

        if(Key==VK_UP) rightUP->Enabled=false;
        if(Key==VK_DOWN) rightDOWN->Enabled=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::leftDOWNTimer(TObject *Sender)
{
        if (leftPaddle->Top+leftPaddle->Height<background->Top+background->Height-10)
        leftPaddle->Top+=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftUPTimer(TObject *Sender)
{
        if (leftPaddle->Top>10)
        leftPaddle->Top-=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightDOWNTimer(TObject *Sender)
{
        if (rightPaddle->Top+rightPaddle->Height<background->Top+background->Height-10)
        rightPaddle->Top+=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightUPTimer(TObject *Sender)
{
        if (rightPaddle->Top>10)
        rightPaddle->Top-=10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
         if(Key=='q')
        {
                if (LeftUp2->Visible==true) LeftUp3->Visible=true;
                if (LeftUp1->Visible==true) LeftUp2->Visible=true;
                if (LeftDown1->Visible==false&&LeftUp1->Visible==false) LeftUp1->Visible=true;
                if (LeftDown1->Visible==true&&LeftDown2->Visible==false) LeftDown1->Visible=false;
                if (LeftDown2->Visible==true&&LeftDown3->Visible==false) LeftDown2->Visible=false;
                if (LeftDown3->Visible==true) LeftDown3->Visible=false;
        }

        if(Key=='a')
        {
                if (LeftDown2->Visible==true) LeftDown3->Visible=true;
                if (LeftDown1->Visible==true) LeftDown2->Visible=true;
                if (LeftUp1->Visible==false&&LeftDown1->Visible==false) LeftDown1->Visible=true;
                if (LeftUp1->Visible==true&&LeftUp2->Visible==false) LeftUp1->Visible=false;
                if (LeftUp2->Visible==true&&LeftUp3->Visible==false) LeftUp2->Visible=false;
                if (LeftUp3->Visible==true) LeftUp3->Visible=false;
        }

        if(Key=='o')
        {
                if (RightUp2->Visible==true) RightUp3->Visible=true;
                if (RightUp1->Visible==true) RightUp2->Visible=true;
                if (RightDown1->Visible==false&&RightUp1->Visible==false) RightUp1->Visible=true;
                if (RightDown1->Visible==true&&RightDown2->Visible==false) RightDown1->Visible=false;
                if (RightDown2->Visible==true&&RightDown3->Visible==false) RightDown2->Visible=false;
                if (RightDown3->Visible==true) RightDown3->Visible=false;
        }

        if(Key=='l')
        {
                if (RightDown2->Visible==true) RightDown3->Visible=true;
                if (RightDown1->Visible==true) RightDown2->Visible=true;
                if (RightUp1->Visible==false&&RightDown1->Visible==false) RightDown1->Visible=true;
                if (RightUp1->Visible==true&&RightUp2->Visible==false) RightUp1->Visible=false;
                if (RightUp2->Visible==true&&RightUp3->Visible==false) RightUp2->Visible=false;
                if (RightUp3->Visible==true) RightUp3->Visible=false;
        }

        if(Key==32)
        {
         ballTimer->Enabled=true;
         bounceCounter=-1;
        }
}
//---------------------------------------------------------------------------

