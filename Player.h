//---------------------------------------------------------------------------

#ifndef PlayerH
#define PlayerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmJogador : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblJogador;
        TRadioButton *rbPedra;
        TRadioButton *rbPapel;
        TRadioButton *rbTesoura;
        TButton *btJogar;
        TEdit *edResultado;
        void __fastcall btJogarClick(TObject *Sender);



        void __fastcall Jogar();
private:	// User declarations
        int  codigoJogador;
        int  codigoJogada;
        void __fastcall SetCodigoJogada(int codigo) { codigoJogada = codigo; }


public:		// User declarations
        __fastcall TfrmJogador(TComponent* Owner);
        // Getter/Setter se necessário
        int __fastcall GetCodigoJogador() { return codigoJogador; }
        void __fastcall SetCodigoJogador(int codigo) { codigoJogador = codigo; }

        int __fastcall GetJogada() { return codigoJogada; }

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmJogador *frmJogador;
//---------------------------------------------------------------------------
#endif
