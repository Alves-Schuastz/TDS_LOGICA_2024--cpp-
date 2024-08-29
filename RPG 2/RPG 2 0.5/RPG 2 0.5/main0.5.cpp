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

void dados(struct personagem inimigo[10]) {
    //status iniciais do personagem
    inimigo[0].hp = 100;
    inimigo[0].atk = 15;
    inimigo[0].def = 5;
    inimigo[0].gold = 0;

    //status dos inimigos
    for (int i = 1; i < 7; ++i) {
        inimigo[i].hp = 30;
        inimigo[i].atk = 10;
        inimigo[i].def = 2;
        inimigo[i].gold = 0;
        inimigo[i].nom = "esqueleto";
    }
}

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

    SpawnRand = rand() % 5+1; // Gera um indice aleatorio dentro dos limites do vetor

    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    
    return SpawnRand;
}

void batalha(personagem player, personagem inimigo) {
    cout << "\nComecou o combate!\n";
    int danoInimigo, danoPlayer;
    while (player.hp > 0 && inimigo.hp > 0) {
        // Turno do jogador
        cout << "E seu turno.\n";
        cout << "(1) Atacar\n";
        cout << "(2) Pocao\n";
        int escolhaJogador;
        cin >> escolhaJogador;

        switch (escolhaJogador) {
            case 1:
            {
                danoPlayer = player.atk - inimigo.def;
                if (danoPlayer > 0) {
                    inimigo.hp -= danoPlayer;
                    cout << "Voce causou " << danoPlayer << " de dano ao " << inimigo.nom << "!\n";
                } else {
                    cout << "Sua jogada nao causou dano ao " << inimigo.nom << "!\n";
                }
                break;
            }
            case 2:
            {
                // Logica de defesa (se desejar implementar)
                cout << "Voce optou por usar pocao.\n";
                break;
            }
        }

        // Verificar se o inimigo foi derrotado apos a acao do jogador
        if (inimigo.hp <= 0) {
            cout << "Voce derrotou o " << inimigo.nom << "!\n";
            break;
        }

        // Opcao para o jogador decidir entre atacar ou defender apos a acao
        cout << "\nPressione ENTER para continuar...\n";
        cin.ignore();
        cin.get();

        // Turno do inimigo
        cout << "Agora e a vez do " << inimigo.nom;
        
        // Ataque do inimigo
        danoInimigo = inimigo.atk - player.def;
        cout << endl << "os dados sao atk-inim play-def e dano inimigo" << inimigo.atk << player.def << danoInimigo << endl;
        if (danoInimigo > 0) {
            player.hp -= danoInimigo;
            cout << "O " << inimigo.nom << " causou " << danoInimigo << " de dano a voce!\n";
        } else {
            cout << "O " << inimigo.nom << " nao causou dano a voce!\n";
        }

        // Verificar se o jogador foi derrotado apos o ataque do inimigo
        if (player.hp <= 0) {
            cout << "Voce foi derrotado pelo " << inimigo.nom << "!\n";
            break;
        }

        // Opcao para o jogador decidir entre atacar ou defender apos o ataque do inimigo
        cout << "\nPressione ENTER para continuar...\n";
        cin.ignore();
        cin.get();
    }
}


void InimigoAparece(personagem player, personagem inimigo[]) {
    int escolha;
    int sla;
    sla = spawnInimigo(inimigo);

    cout<<"\nvalor no vetor " << sla;
    cout << "\n(1) atacar \n(2) fugir";
    cin >> escolha;
    
    switch (escolha) {
        case 1:
            if (sla >= 0 && sla < 6) {
                batalha(player, inimigo[sla]);
            } else {
                cout << "Erro: indice de inimigo fora dos limites validos.\n";
            }
            break;
        
        case 2:
            if (fuga()) {
                // O personagem conseguiu fugir
            } else {
                // O personagem nao conseguiu fugir
                batalha(player, inimigo[sla]);
            }
            break;
    }
}

int main() {
    srand(time(NULL));
    personagem inimigo[7]; // alterado para 6 para conter os seis inimigos
    personagem chefao[5];
    personagem pers;
    
    dados(inimigo);
    
    string nome;

    cout << "\nBem vindo a alfa 0.5 do RPG 2\n";
    cout << "Esta e apenas uma versao teste do jogo\n";
    cout << "\nClique para continuar\n";
    getchar();
    getchar();

    cout << "Qual e o nome do seu personagem?\n";
    getline(cin, nome);
    pers.nom = nome;
    cout << "\nNome do personagem: " << pers.nom << endl;

    cout << "\nVida: " << inimigo[0].hp << endl;
    cout << "Ataque: " << inimigo[0].atk << endl;
    cout << "Defesa: " << inimigo[0].def << endl;
    cout << "Gold: " << inimigo[0].gold << endl;

    InimigoAparece(inimigo[0], inimigo);

    return 0;
}
