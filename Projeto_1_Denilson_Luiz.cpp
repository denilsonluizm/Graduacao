
// LOGICA DE PROGRAMAÇÃO -- PROJETO 1 -- Denilson Luiz

#include <iostream>
using namespace std;

    // funcao que troca o nome de 2 produtos e seus respetivos valores por quilo
void change(string &prodA, string &prodB, double &vpqA, double &vpqB){
    string auxs;
    double auxd;
        auxs = prodA;
            auxd = vpqA;
        prodA = prodB;
            vpqA = vpqB;
        prodB = auxs;
            vpqB = auxd;
}

int main(){

int escolha_problema;

// variaveis do problema 1
string prod1, prod2, prod3, aux;
double vl1, vl2, vl3, vpq1, vpq2, vpq3, auxx;
int massa1, massa2, massa3, i;
bool saida=true;

// variaveis do problema 2
int j, k, l, cont=0, cont2=0, num_jogos;
char E[7], D[7], auxE, auxD;

// MENU
cout << "\nQual problema deseja?" << endl;
cout << "Problema 1 digite 1, Problema 2 digite 2: " << endl;
cin >> escolha_problema;

    // PROBLEMA 1
if(escolha_problema==1){

while(saida){

    cout << "\nPara sair do programa digite S em nome de qualquer produto." << endl;

    cout << "\nInforme nome do produto 1, valor unitário e massa: " << endl;
    cin >> prod1 >> vl1 >> massa1;
    vpq1 = vl1/massa1;

    cout << "\nInforme nome do produto 2, valor unitário e massa: " << endl;
    cin >> prod2 >> vl2 >> massa2;
    vpq2 = vl2/massa2;

    cout << "\nInforme nome do produto 3, valor unitário e massa: " << endl;
    cin >> prod3 >> vl3 >> massa3;
    vpq3 = vl3/massa3;

    if(prod1=="S" || prod2=="S" || prod3=="S") { // condicional para saida do programa
        
        saida = false;
        cout << "\nSaida do programa!" << endl;

    }
    else { // validacao entradas e ordenacao

            if( prod1==prod2 || prod1==prod3 || prod3==prod2 || vpq1==vpq2 || vpq1==vpq3 || vpq3==vpq2) {

                // condicional que encerra caso entradas invalidas
                cout << "Entrada Invalida!" << endl;

            }
            else { // ordenacao

                    // sequencia de condicionais que ordena os produtos
                    // do maior para o menor valor por quilo

                    if( vpq2 > vpq1 ) {
                        change(prod1,prod2,vpq1,vpq2);
                    }

                    if( vpq3 > vpq1 ) {
                        change(prod1,prod3,vpq1,vpq3);
                    }

                    if( vpq3 > vpq2 ) {
                        change(prod2,prod3,vpq2,vpq3);
                    }

                    cout << "\n" << prod1 << "\n" << prod2 << "\n"  << prod3 << endl;

            }// fim else ordenacao

    }// fim else validacao entradas e ordenacao

}// fim while

}// fim IF problema 1

    // PROBLEMA 2
else if(escolha_problema==2) {

cout << "\nQuantos jogos deseja jogar?" << endl;
cin >> num_jogos;

for(l=1; l<=num_jogos; l++) { // loop para num de jogos

    cout << "\nInforme 7 pecas: ";

    for(i=0; i<=6; i++){ // recebendo as pecas
        cin >> E[i] >> D[i];
    }

    for(k=1; k<=7; k++) { // loop para testar peça por peça, se uma peça se encaixa em alguma
    
        for(i=1; i<7; i++) { // loop que passa pelas outras peças

            if(E[0]==E[i]) {
                cont++;
            }
            else if(E[0]==D[i]) {
                cont++;
            }                           // condicionais para estar se há pelo menos 1 encaixe
            else if(D[0]==E[i]) {
                cont++;
            }
            else if(D[0]==D[i]) {
                cont++;
            }
            
            if(cont>0) cont2++;        // se há pelo menos e encaixe cont2++
            cont = 0;                   // cont se anula para a proxima peça
            
        } // fim loop passa por outras peças

        // rotaciona as peças, a peça atualmente testada passa a ser a ultima e a fila anda
        auxE = E[0];
        auxD = D[0];
            for (j=0; j<6; j++){
                E[j] = E[j+1];
                D[j] = D[j+1];
            }
        E[6] = auxE;
        D[6] = auxD; 

    } // fim loop testa peça por peça

    // se as 7 peças se encaixam pelo menos de um forma
    // há pelo menos 6 encaixes
    if(cont2>=6) cout << "WON" << endl;
    else cout << "LOST" << endl;

    cont2 = 0; // zera cont2 para o proximo jogo

} // fim num de jogos

}
else cout << "\nEscolha inválida" << endl;

return 0;
}