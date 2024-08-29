#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// Dados de personagem e inimigos
struct personagem {
    int hp;
    int atk;
    int def;
    string nom;
    double gold;  
};
void dados(struct personagem inimigo[10]){

    //status iniciais do personagem
    inimigo[0].hp = 100;
    inimigo[0].atk = 15;
    inimigo[0].def = 10;
    inimigo[0].gold = 0;

    //status dos inimigos
    inimigo[1].hp = 30;
    inimigo[1].atk = 10;
    inimigo[1].def = 2;
    inimigo[1].gold = 0;
    inimigo[1].nom = "esqueleto";

    inimigo[2].hp = 30;
    inimigo[2].atk = 10;
    inimigo[2].def = 2;
    inimigo[2].gold = 0;
    inimigo[2].nom = "esqueleto";

    inimigo[3].hp = 30;
    inimigo[3].atk = 10;
    inimigo[3].def = 2;
    inimigo[3].gold = 0;
    inimigo[3].nom = "esqueleto";
    
    inimigo[4].hp = 30;
    inimigo[4].atk = 10;
    inimigo[4].def = 2;
    inimigo[4].gold = 0;
    inimigo[4].nom = "esqueleto";
    
    inimigo[5].hp = 30;
    inimigo[5].atk = 10;
    inimigo[5].def = 2;
    inimigo[5].gold = 0;
    inimigo[5].nom = "esqueleto";

    inimigo[6].hp = 30;
    inimigo[6].atk = 10;
    inimigo[6].def = 2;
    inimigo[6].gold = 0;
    inimigo[6].nom = "esqueleto";
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

int spawnInimigo(personagem inimigos[]) {
    int SpawnRand;

    SpawnRand = (rand() % 5)+1; // Gera um índice aleatório com base no tamanho do vetor de inimigos

    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    
    return SpawnRand;
}

void batalha(personagem inimigo, personagem player) {
    int escolha;
    cout << "\nvoce esta batalhando!";
    cout <<  "\n(1)atacar \n(2)defender";
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        //turno do player
        inimigo.hp = inimigo.def - player.atk;
        cout <<"\nvida do inimigo= " << inimigo.hp;
        break;
    
    case 2:
    cout << "\nblablabla";
        break;
    }


}

void InimigoAparece(personagem inimigo[], personagem player) {
    int escolha;
    int sla;
    sla = spawnInimigo(inimigo);

    cout << "\n(1) atacar \n(2) fugir";
    cin >> escolha;
    
    switch (escolha) {
        case 1:
            batalha(inimigo[sla], player);
            break;
        
        case 2:
            if (fuga()) {
                // O personagem conseguiu fugir
            } else {
                // O personagem nao conseguiu fugir
                batalha(inimigo[sla], player);
            }
            break;
    }
}

int main() {
    srand(time(NULL));
    personagem inimigo[5]; 
    personagem chefao[5];
    personagem pers;
    
    dados(inimigo);
    
    string nome;

    cout << "\nBem vindo a alfa 0.2 do RPG 2\n";
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

    InimigoAparece(inimigo, pers);

    return 0;
}