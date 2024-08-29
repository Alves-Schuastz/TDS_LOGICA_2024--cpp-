#include <iostream>

using namespace std;

struct personagem{
    int hp;
    int atk;
    int def;
    char nom[40];
    double gold;  
};


int main(){
    personagem pers;
    string nome;

    cout << "\nbem vindo a alfa 0.1 do RPG 2\n";
    cout <<"esta e apenas uma versao teste do jogo\n";
    cout <<"\nclique para continuar\n";
    getchar();
    getchar();

    cout << "qual e o nome do seu personagem?\n";
    cin >> nome;
    cout <<"\n" << nome;

    pers.hp=100;
    pers.atk=15;
    pers.def=10;
    pers.gold=0;

    cout << "\nVida: " << pers.hp << endl;
    cout << "Ataque: " << pers.atk << endl;
    cout << "Defesa: " << pers.def << endl;
    cout << "Gold: " << pers.gold << endl;

    
}