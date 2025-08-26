Article: Deconstructing a Rock-Paper-Scissors Game Architecture in C++ Builder
Introduction
This article analyzes a codebase written in C++ Builder that implements a multi-player Rock-Paper-Scissors game. The code provides a classic example of a client-server desktop application architecture, albeit a simple one, where a central form (MesaJogo - Game Table) manages multiple player forms (TfrmJogador - Player Form). We will explore its structure, functionality, and the logic that drives the game's outcome.

Overview of the Architecture
The system is composed of two main units:

Player.h / Player.cpp: Defines the TfrmJogador class, which represents the interface and state of a single player.

Mesa.h / Mesa.cpp: Defines the TMesaJogo class, which acts as the game server, creating players, collecting their choices, and determining the winner.

The global vector std::vector<TfrmJogador*> frmJogadores is crucial as it maintains a list of all active player forms, allowing the game table to iterate through them.

Deep Dive into the Player Form (TfrmJogador)
The player form is responsible for capturing the user's choice.

Key Member Function: Jogar() (Play)

cpp
void __fastcall TfrmJogador::Jogar()
{
    register unsigned int jogada = 0; // The player's move
    this->Caption = this->GetCodigoJogador();
    this->lblJogador->Caption = "Jogador" + IntToStr(this->GetCodigoJogador());
    
    // Determine the move based on the selected RadioButton
    jogada = rbPedra->Checked ? rbPedra->Tag : jogada;
    jogada = rbPapel->Checked ? rbPapel->Tag : jogada;
    jogada = rbTesoura->Checked ? rbTesoura->Tag : jogada;
    
    edResultado->Text = jogada; // Display the move in an Edit field
    this->SetCodigoJogada(jogada); // Store the move internally
}
Analysis:

UI Interaction: The method reads the Checked property of RadioButtons (presumably named rbPedra (Rock), rbPapel (Paper), rbTesoura (Scissors)).

Data Representation: It uses the Tag property of these components to represent the move numerically. The actual values (e.g., 1 for Rock, 2 for Paper, 3 for Scissors) are inferred from the game logic elsewhere.

State Management: The chosen move is stored internally via SetCodigoJogada() and also displayed in a UI component (edResultado) for the user to see.

Deep Dive into the Game Table (TMesaJogo)
This form is the core of the application, coordinating the game.

1. Creating Players (criaJogadorClick)

cpp
void __fastcall TMesaJogo::criaJogadorClick(TObject *Sender)
{
   TfrmJogador *frm = new TfrmJogador(this); // Dynamically create a new player form
   frmJogadores.push_back(frm);              // Add it to the global vector
   frm->SetCodigoJogador(++c);               // Assign a unique ID
   frm->Show();                              // Display the form
   frm->Jogar();                             // Trigger the play method
}
Analysis: This event handler allows the game to support multiple dynamic players. Each new player is assigned a unique, incrementing ID.

2. Executing the Game and Determining the Winner (JogarClick)

This is the most complex and interesting part of the code.

cpp
void __fastcall TMesaJogo::JogarClick(TObject *Sender)
{
   int vencedor = 0;        // ID of the winning player
   int jogadoratual = 0;    // Temporary holder for the current leader's ID
   int ultimajogada = 0;    // The strongest move found so far
   int atualjogada = 0;     // The move of the current player being checked

   this->mResultados->Lines->Clear(); // Clear the results memo

   // Iterate through all players in the vector
   for (size_t i = 0; i < frmJogadores.size(); i++) {
    if (frmJogadores[i] != NULL) {
            atualjogada = frmJogadores[i]->GetJogada(); // Get player's move

            // THE CORE LOGIC: Determine if this player is the new leader
            if(atualjogada > ultimajogada || (atualjogada == 3 && ultimajogada == 1))
            {
                    ultimajogada = atualjogada;
                    jogadoratual = frmJogadores[i]->GetCodigoJogador();
                    vencedor = jogadoratual;
            }

       // Log this player's action to the UI
       this->mResultados->Lines->Add("Player: " + IntToStr(jogadoratual)
                 + "-Escolha:"+ IntToStr(atualjogada) );
    }
  }

    // Display the final result
    this->mResultados->Lines->Add("Resultado:\nVencedor: "+
                IntToStr(vencedor)
                 + "-"+ IntToStr(ultimajogada) );
}
Analysis of the Game Logic:
The logic if(atualjogada > ultimajogada || (atualjogada == 3 && ultimajogada == 1)) is a clever numerical trick that works under specific assumptions:

Assumed Values: Rock=1, Paper=2, Scissors=3.

Standard Rules: Paper (2) beats Rock (1). Scissors (3) beats Paper (2). This is handled by the first condition (atualjogada > ultimajogada).

The Exception - Rock vs. Scissors: The classic exception is that Rock (1) beats Scissors (3). Since 1 is not greater than 3, a special condition is needed: (atualjogada == 3 && ultimajogada == 1). This condition checks if the current strongest move is Rock (1) and a new player has Scissors (3). In this case, Rock should remain the winner, so this condition is actually flawed.

The Flaw: The code inside the if block makes the new player the winner. So if ultimajogada is 1 (Rock) and a new player has 3 (Scissors), the condition is true, and it will set vencedor to the Scissors player and ultimajogada to 3. This is incorrect, as Rock should defeat Scissors.

A correct implementation would need to handle this edge case separately, likely by not updating the leader if the current leader is Rock and the new move is Scissors.

Conclusion
This C++ Builder code demonstrates a practical and functional implementation of a multi-window desktop game. Its architecture cleanly separates player management from game logic.

Strengths: Clear separation of concerns, use of dynamic form creation, and a generally correct algorithm for most game scenarios.

Weakness: The core game logic contains a critical flaw in the Rock-Scissors interaction, which would lead to incorrect winners being declared in that specific case.

This code serves as an excellent educational example. It shows how to manage multiple forms in C++ Builder and implement game state, while also providing a clear lesson on the importance of thoroughly testing all edge cases in a seemingly simple algorithm. Fixing the conditional logic in JogarClick would transform this from a good learning example into a fully functional and correct application.
