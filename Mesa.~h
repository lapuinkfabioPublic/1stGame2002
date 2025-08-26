//---------------------------------------------------------------------------
/*
        Quando você construi um código,
        um jogo ou seja lá o que for,
        você constrói a si mesmo.
*/
#ifndef MesaH
#define MesaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMesaJogo : public TForm
{
__published:	// IDE-managed Components
        TButton *criaJogador;
        TButton *Jogar;
        TMemo *mResultados;
        TLabel *Label1;
        void __fastcall criaJogadorClick(TObject *Sender);
        void __fastcall JogarClick(TObject *Sender);
private:	// User declarations
        int codigoJogador;
        int escolha;
public:		// User declarations
        __fastcall TMesaJogo(TComponent* Owner);
        void __fastcall SetEscolhaJogador(int codigo, int objeto) { codigoJogador = codigo; escolha = objeto; }

};
//---------------------------------------------------------------------------
extern PACKAGE TMesaJogo *MesaJogo;
//---------------------------------------------------------------------------
#endif
