//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Player.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmJogador *frmJogador;
int codigoJogador;
//---------------------------------------------------------------------------
__fastcall TfrmJogador::TfrmJogador(TComponent* Owner)
        : TForm(Owner)
{

}
void __fastcall TfrmJogador::Jogar()
{       register unsigned int jogada = 0;
        this->Caption = this->GetCodigoJogador();
        this->lblJogador->Caption = "Jogador" + IntToStr(this->GetCodigoJogador());
        jogada = rbPedra->Checked ? rbPedra->Tag : jogada;
        jogada = rbPapel->Checked ? rbPapel->Tag : jogada;
        jogada = rbTesoura->Checked ? rbTesoura->Tag : jogada;
        edResultado->Text = jogada;
        this->SetCodigoJogada(jogada);


}
//---------------------------------------------------------------------------
void __fastcall TfrmJogador::btJogarClick(TObject *Sender)
{
        Jogar();

}
//---------------------------------------------------------------------------



