//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *ballTimer;
        TShape *background;
        TImage *ball;
        TImage *leftPaddle;
        TImage *rightPaddle;
        TImage *net;
        TTimer *leftUP;
        TTimer *leftDOWN;
        TTimer *rightUP;
        TTimer *rightDOWN;
        TImage *LeftUp1;
        TImage *LeftUp2;
        TImage *LeftUp3;
        TImage *LeftDown1;
        TImage *LeftDown2;
        TImage *LeftDown3;
        TImage *RightDown1;
        TImage *RightDown2;
        TImage *RightDown3;
        TImage *RightUp1;
        TImage *RightUp2;
        TImage *RightUp3;
        TLabel *leftTab;
        TLabel *rightTab;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall leftDOWNTimer(TObject *Sender);
        void __fastcall leftUPTimer(TObject *Sender);
        void __fastcall rightDOWNTimer(TObject *Sender);
        void __fastcall rightUPTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
