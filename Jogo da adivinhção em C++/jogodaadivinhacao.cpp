#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "(1) Facil (2) Medio (3) Dificil \n\n" << endl;

    int dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

        if(dificuldade == 1) {
            numero_de_tentativas = 15;
            cout << "Voce tem " << numero_de_tentativas << " chances de tenteativas " << endl;
        }
        else if(dificuldade == 2){
            numero_de_tentativas = 10;
            cout << "Voce tem " << numero_de_tentativas << " chances de tenteativas " << endl;
        }
        else {
            numero_de_tentativas = 5 ;
            cout << "Voce tem " << numero_de_tentativas << " chances de tenteativas " << endl;
        } 

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() %101;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;
    
    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++ ){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "\nParabens! Voce acertou o numero secreto! \n" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto! \n" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto! \n" << endl;
        }

    }
    
    if(nao_acertou){
        cout << "Fim de jogo!" << endl;
        cout << "Voce perdeu tente novamente " << endl;
    }
    else{
    cout << "Voce acertou o numero secreto em " << tentativas  << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi de " << pontos << " pontos " << endl << endl;
    }
}