#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#define tmesqueleto 5;

using namespace std;

// Dados de personagem e inimigos
struct personagem {
    int hp;
    int atk;
    int def;
    string nom;
    double gold;  
};
void dados(struct personagem inimigos[100]){
    personagem esqueleto[5];

    esqueleto[0].hp = 30;
    esqueleto[0].atk = 10;
    esqueleto[0].def = 2;
    esqueleto[0].gold = 0;
    esqueleto[0].nom = "esqueleto";

    esqueleto[1].hp = 30;
    esqueleto[1].atk = 10;
    esqueleto[1].def = 2;
    esqueleto[1].gold = 0;
    esqueleto[1].nom = "esqueleto";

    esqueleto[2].hp = 30;
    esqueleto[2].atk = 10;
    esqueleto[2].def = 2;
    esqueleto[2].gold = 0;
    esqueleto[2].nom = "esqueleto";
    
    esqueleto[3].hp = 30;
    esqueleto[3].atk = 10;
    esqueleto[3].def = 2;
    esqueleto[3].gold = 0;
    esqueleto[3].nom = "esqueleto";
    
    esqueleto[4].hp = 30;
    esqueleto[4].atk = 10;
    esqueleto[4].def = 2;
    esqueleto[4].gold = 0;
    esqueleto[4].nom = "esqueleto";
    
    esqueleto[4].hp = 30;
    esqueleto[4].atk = 10;
    esqueleto[4].def = 2;
    esqueleto[4].gold = 0;
    esqueleto[5].nom = "esqueleto";

    esqueleto[5].hp = 30;
    esqueleto[5].atk = 10;
    esqueleto[5].def = 2;
    esqueleto[5].gold = 0;
    esqueleto[5].nom = "esqueleto";
}
////////////////////////////////////////////////////////////////////////////////////

bool fuga() {
    int ChanceDeFuga = rand() % 100 + 1;

    if (ChanceDeFuga > 30) {
        cout << "\nVoce conseguiu fugir!";
        return true;
    } else {
        cout << "\nOs cana te pegaram!";
        return false;
    }
}

void spawnInimigo(personagem inimigos[], int tamanho) {
    int SpawnRand;

    SpawnRand = rand() % tamanho; // Gera um índice aleatório com base no tamanho do vetor de inimigos
    cout << "\nUm " << inimoigos[SpawnRand].nom << " apareceu!\n";
    
    return SpawnRand;
}

void batalha(personagem& inimigo) {


    //int op = spawnInimigo(inimigos);
}

void InimigoAparece(personagem& inimigo) {
    int escolha;

    cout << "\nApareceu um inimigo!";
    cout << "\n(1) atacar \n(2) fugir";
    cin >> escolha;
    
    switch (escolha) {
        case 1:
            batalha(inimigo);
            break;
        
        case 2:
            if (fuga()) {
                // O personagem conseguiu fugir
            } else {
                // O personagem nao conseguiu fugir
            }
            break;
    }
}

int main() {
    srand(time(NULL));

    personagem pers, inimigo[10], chefao[20];
    string nome;

    cout << "\nBem vindo a alfa 0.1 do RPG 2\n";
    cout << "Esta e apenas uma versao teste do jogo\n";
    cout << "\nClique para continuar\n";
    getchar();
    getchar();

    cout << "Qual e o nome do seu personagem?\n";
    getline(cin, nome);
    pers.nom = nome;
    cout << "\nNome do personagem: " << pers.nom << endl;

    pers.hp = 100;
    pers.atk = 15;
    pers.def = 10;
    pers.gold = 0;

    cout << "\nVida: " << pers.hp << endl;
    cout << "Ataque: " << pers.atk << endl;
    cout << "Defesa: " << pers.def << endl;
    cout << "Gold: " << pers.gold << endl;

    InimigoAparece(inimigo[0]);

    return 0;
}