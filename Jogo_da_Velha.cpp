#include <iostream>
#include <cstdlib>
using namespace std;

void exibeJogo(char matriz[3][3]);
void recebeJogador(char &jogador);
void preecheJogo(int &linha, int &coluna, char JOGO[3][3], char jogador);
void teste(char JOGO[3][3], int &cont);

int main(){

    char JOGO[3][3], jogador;
    int i, j, linha, coluna, cont=1;

    // preenche matriz com tracos
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            JOGO[i][j] = '-';
        }
    }    

    cout << endl;

    while(cont<=9){

        recebeJogador(jogador);

        preecheJogo(linha, coluna, JOGO, jogador);

        cout << endl;

        exibeJogo(JOGO);

        teste(JOGO, cont);

        cout << endl;

        cont++;
    }

return 0;    
}

    //  FUNCOES  //

// funcao que exibe o jogo
void exibeJogo(char matriz[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// funcao para receber o jogador
void recebeJogador(char &jogador){
    cout << "qual jogador (X ou O): " << endl;
    cin >> jogador;
    while(jogador!='X' && jogador!='O'){
        cout << "jogador invalido, informe jogador" << endl;
        cin >> jogador;
        }
}

// funcao para preencher o jogo
void preecheJogo(int &linha, int &coluna, char JOGO[3][3], char jogador){
    cout << "Informe linha e coluna da jogada: " << endl;
    cin >> linha >> coluna;
    JOGO[linha-1][coluna-1] = jogador;
}

// funcao que verifica se alguem ganhou
void teste(char JOGO[3][3], int &cont){
    int i, j, teste=0;
        // TESTE LINHAS
    for(i=0; i<3; i++){
        // verifica se X em alguma linha
        for(j=0; j<3; j++){
            if(JOGO[i][j]=='X') teste++;
        }
        if(teste==3){
            cout << "\nX ganhou!" << endl;
            i = 4;
            cont = 10;            
        }
        teste = 0;
        //verifica se O ganhou em alguma linha
        for(j=0; j<3; j++){
            if(JOGO[i][j]=='O') teste++;
        }
        if(teste==3){
            cout << "\nO ganhou!" << endl;
            i = 4;
            cont = 10;            
        }
        teste = 0;
    }  // fim for teste linhas
        // TESTE COLUNAS
    for(j=0; j<3; j++){
        // verifica se X em alguma coluna
        for(i=0; i<3; i++){
            if(JOGO[i][j]=='X') teste++;
        }
        if(teste==3){
            cout << "\nX ganhou!" << endl;
            j = 4;
            cont = 10;            
        }
        teste = 0;
        //verifica se O ganhou em alguma coluna
        for(i=0; i<3; i++){
            if(JOGO[i][j]=='O') teste++;
        }
        if(teste==3){
            cout << "\nO ganhou!" << endl;
            j = 4;
            cont = 10;            
        }
        teste = 0;
    }  // fim for teste colunas
    teste = 0;

    // TESTE DIAGONAIS
    // verifica se X ganhou em alguma diagonal
    for(i=0; i<3; i++){  
        if(JOGO[i][i]=='X') teste++;
    }
    if(teste==3){
        cout << "\nX ganhou!" << endl;
        cont = 10;         
    }
    teste = 0;
    for(i=0; i<3; i++){
        if(JOGO[i][2-i]=='X') teste++;
    }
    if(teste==3){
        cout << "\nX ganhou!" << endl;
        cont = 10;         
    }
    teste = 0;
    // verifica se O ganhou em alguma diagonal
    for(i=0; i<3; i++){
        if(JOGO[i][i]=='O') teste++;
    }
    if(teste==3){
        cout << "\nO ganhou!" << endl;
        cont = 10;         
    }
    teste = 0;
    for(i=0; i<3; i++){
        if(JOGO[i][2-i]=='O') teste++;
    }
    if(teste==3){
        cout << "\nO ganhou!" << endl;
        cont = 10;         
    }
    teste = 0; // fim teste diagonais
}