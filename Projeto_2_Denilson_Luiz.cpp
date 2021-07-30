
// LOGICA DE PROGRAMACAO -- PROJETO 2 -- Denilson Luiz

#include <iostream>
#include <math.h>
using namespace std;

char* m1[100];

//------------------- FUNCOES ---------------------//

// funcao para preencher matriz
void PreencheMatriz(char* M[], int m, int n)
{
    cout << "\nInforme Matriz: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> *(M[i]+j);
        }
    }
}

// funcao que verifica se eh lagoa
// 1 - nao eh lagoa
// 2 - eh lagoa
int Verifica(char* M[], int m, int n, int a, int b){
    int cont=0;

    if(a==0 || b==0 || a==(m-1) || b==(n-1)) return 1; // se esta na borda
    else if(*(M[a]+b)=='T') return 1; // se eh terra
    else if(*(M[a]+b)=='A'){ // verificacoes caso seja agua
        *(M[a]+b) = 'T';
        // loops que circundam M[a][b]
        for(int i=(a-1); i<(a+2); i++){
            for(int j=(b-1); j<(b+2); j++){
                if(*(M[i]+j)=='A') Verifica(m1, m, n, i, j);
            }
        }
        
    }
    else return 2;
}

// funcao que conta quantos digitos tem um valor inteiro
int qnt_digitos(int n){
    int cont=0;
    if(n==0) return 1;
    else while(n != 0){
        cont++;
        n = n/10;
    }
    return cont;
}
//------------------- FIM FUNCOES ---------------------//

//------------------- PRINCIPAL -----------------------//
int main()
{

    int problema;
    bool saida=true;

    while(saida){

        cout << "\n---------------- MENU ----------------" << endl;
        cout << "0 - Sair." << endl;
        cout << "1 - Problema 1." << endl;
        cout << "2 - Problema 2." << endl;
        cin >> problema;

        switch (problema)
        {
            case 0:{
                cout << "Saindo do programa!" << endl;
                saida = false;
                break;}
            
            case 1: {// ----- PROBLEMA 1 -----
                int m, n, a, b, qnt_testes;
                cout << "\nInforme num de linhas e coluna das matrizes: " << endl;
                cin >> m >> n;

                char M1[m][n];

                // atribuindo enderecos da primeira coluna da matriz ao vetor de ponteiros
                for(int i=0; i<m; i++) m1[i] = &M1[i][0];

                PreencheMatriz(m1, m, n);

                cout << "Quantos testes quer fazer? ";
                cin >> qnt_testes;

                // loop para testes
                for(int i=0; i<qnt_testes; i++){
                    cout << "Indique as coordenadas a x b (considerando indice 0): ";
                    cin >> a >> b;

                    if(Verifica(m1, m, n, a, b)==1) cout << "Nao eh lagoa!" << endl;
                    else cout << "Eh lagoa!" << endl;
                }
                break;}

            case 2: {// ----- PROBLEMA 2 -----
                long N, qnt_n, potencia, qnt_pot, valor;

                while(N!=0){

                    cout << "\nValor: ";
                    cin >> N;

                    qnt_n = qnt_digitos(N);

                    // bloco que verifica o expoente
                    for(int i=1; i<32; i++){ // for varia todas potencias de 2 possiveis

                        potencia = pow(2,i);
                        qnt_pot = qnt_digitos(potencia); // quantidade de digitos tem a potencia

                        // compara apenas para potencias com num de digitos maior que 2 x qnt_n
                        if(qnt_pot>2*(qnt_n)){
                            valor = potencia/pow(10,(qnt_pot-qnt_n));
                            if (valor == N) {
                                cout << "Expoente: " << i << endl;
                                i=33;
                            }
                        }
                    }
                } // fim while
                break;}

        } // fim switch

    } // fim while

    return 0;
}