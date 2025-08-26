//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Mesa.h"
#include "Player.h"
#include <vector>
#include <iostream.h>
/*
A A.I é apenas um jogo da imitação.

Imita o ser humano, que a treinou.. mas
não treinou em tudo...


*/

std::vector<TfrmJogador*> frmJogadores;

int c = 0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMesaJogo *MesaJogo;


//---------------------------------------------------------------------------
__fastcall TMesaJogo::TMesaJogo(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TMesaJogo::criaJogadorClick(TObject *Sender)
{
   TfrmJogador *frm = new TfrmJogador(this);
   frmJogadores.push_back(frm);
   frm->SetCodigoJogador(++c);
   frm->Show();
   frm->Jogar();

}
//---------------------------------------------------------------------------



void __fastcall TMesaJogo::JogarClick(TObject *Sender)
{

  //Mostra os Resultados
   int vencedor = 0;
   int jogadoratual =  0;
   int ultimajogada = 0;
   int atualjogada = 0;

   this->mResultados->Lines->Clear();
   for (size_t i = 0; i < frmJogadores.size(); i++) {
    if (frmJogadores[i] != NULL) {

            atualjogada = frmJogadores[i]->GetJogada();
            if(atualjogada > ultimajogada || atualjogada == 3 && ultimajogada == 1)
            {
                    ultimajogada = atualjogada;
                    jogadoratual = frmJogadores[i]->GetCodigoJogador();
                    vencedor =     jogadoratual;
            }



       this->mResultados->Lines->Add("Player: "+
                IntToStr(jogadoratual)
                 +"-Escolha:"+ IntToStr(atualjogada) );
    }
  }

    this->mResultados->Lines->Add("Resultado:\nVencedor: "+
                IntToStr(vencedor)
                 +"-"+ IntToStr(ultimajogada) );

}
//---------------------------------------------------------------------------

