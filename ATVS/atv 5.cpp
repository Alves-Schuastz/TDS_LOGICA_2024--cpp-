#include <iostream>

using namespace std;

int simples(float n1, float n2,float n3, float n4){
    float result;
    float div;

    result=n1+n2+n3+n4;
    div=result/4;
    cout << "\nmedia final " << div;
    
    return 0;
}

int ponderada(float n1, float n2,float n3, float n4){

    float result;
    float multi;
    
    float val1;
    float val2;
    float val3;
    float val4;
    
    cout << "insira o valor da primeira nota\n";
    cin >> val1;
    cout << "insira o valor da segunda nota\n";
    cin >> val2;
    cout << "insira o valor da terceira nota\n";
    cin >> val3;
    cout << "insira o valor da quarta nota\n";
    cin >> val1;


}

void main(){
    int escolha;
    float n1, n2, n3, n4;

    cout << "primeira media\n";
    cout << "insira a primeira nota\n";
    cin >> n1;

    cout << "insira a segunda nota\n";
    cin >> n2;

    cout << "insira a terceira nota\n";
    cin >> n3;
    
    cout << "insira a quarta nota\n";
    cin >> n4;

    cout << "escolha o tipo de media\n";
    cout << "\n1- media simples\n";
    cout << "2- media poderada\n";
    cout << "3- media harmonica\n";
    cin >> escolha;

    if(escolha==1){
    escolha = simples(n1,n2,n3,n4);
    }

    if(escolha==2){
        escolha = ponderada(n1,n2,n3,n4);
    }
}
