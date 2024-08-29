#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream> // Biblioteca para manipulação de arquivos

using namespace std;

// Dados de personagem e inimigos
struct personagem {
    int hp;
    int atk;
    int def;
    int xp;
    int nivel;
    string nom;
    double gold;
    int HPmax;
    //bool is_chefe; 
};

int pontos=0; //contador de pontos do personagem
int mortes=0; //contador de mortes do jogador
int InimigoDerrotado=0; //contador de quantos chefes foram derrotados
int potion=1; //pocao

void dados(struct personagem inimigo[100]) {
    //status iniciais do personagem
    inimigo[0].hp = 60;
    inimigo[0].atk = 15;
    inimigo[0].def = 5;
    inimigo[0].gold = 0;
    inimigo[0].xp = 0;
    inimigo[0].nivel = 1;
    inimigo[0].HPmax=60;
    //bool is_chefe= false;

    //status dos inimigos
    for (int i = 1; i < 7; ++i) {
        inimigo[i].hp = 30;
        inimigo[i].atk = 10;
        inimigo[i].def = 2;
        inimigo[i].gold = 0;
        inimigo[i].xp= 4;
        inimigo[i].nivel= 1;
        inimigo[i].nom = "esqueleto";
    }

     for (int i = 7; i < 12; ++i) {
        inimigo[i].hp = 30;
        inimigo[i].atk = 15;
        inimigo[i].def = 10;
        inimigo[i].gold = 0;
        inimigo[i].xp= 6;
        inimigo[i].nivel= 2;
        inimigo[i].nom = "super macaco";
    }

    
     for (int i = 12; i < 18; ++i) {
        inimigo[i].hp = 45;
        inimigo[i].atk = 22;
        inimigo[i].def = 8;
        inimigo[i].gold = 0;
        inimigo[i].xp= 8;
        inimigo[i].nivel= 3;
        inimigo[i].nom = "bruxa";
    }

    for (int i = 18; i < 24; ++i) {
        inimigo[i].hp = 60;
        inimigo[i].atk = 30;
        inimigo[i].def = 15;
        inimigo[i].gold = 0;
        inimigo[i].xp= 10;
        inimigo[i].nivel= 4;
        inimigo[i].nom = "Espadachim Sombrio";
    }

    for (int i = 24; i < 30; ++i) {
        inimigo[i].hp = 100;
        inimigo[i].atk = 20;
        inimigo[i].def = 30;
        inimigo[i].gold = 0;
        inimigo[i].xp= 15;
        inimigo[i].nivel= 5;
        inimigo[i].nom = "golem";
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

int spawnInimigo(personagem inimigos[], int level) {
    int SpawnRand;

// Gera um indice aleatorio dentro dos limites do vetor
    if(level==1){
    SpawnRand = rand() % 5+1; // Gera um indice aleatorio dentro dos limites do vetor
    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    }

    if(level>=2 && level<=4){
    SpawnRand = rand() % 5+6; 
    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    }

    if(level>=5 && level<=7){
    SpawnRand = rand() % 5+11; 
    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    }

    if(level>=8 && level<=9){
    SpawnRand = rand() % 5+16; 
    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    }

    if(level>=10){
    SpawnRand = rand() % 5+21; 
    cout << "\nUm " << inimigos[SpawnRand].nom << " apareceu!\n";
    }
    
    return SpawnRand;
}

void batalha(personagem &player, personagem inimigo) {
    
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
                    cout << "Vida do inimigo e " << inimigo.hp <<" \n";
                } else {
                    cout << "Sua jogada nao causou dano ao " << inimigo.nom << "!\n";
                }
                break;
            }
            case 2:
            {
                // Logica de pocao
                cout << "Voce optou por usar pocao.\n";
                if (potion>0){
                    player.hp+=20;
                    potion --;
                    cout <<"se curou!\n";
                    if(player.hp>player.HPmax){
                        player.hp = player.HPmax;
                        cout <<"\nnao sei";
                    }
                    cout << "sua vida agora e: " << player.hp; 
                }
                break;
            }
        }

        // Verificar se o inimigo foi derrotado apos a acao do jogador
        if (inimigo.hp <= 0) {
            InimigoDerrotado++;
            
            int PlusXP;
            player.xp += inimigo.xp;
            PlusXP= inimigo.xp;
            pontos+=5;
            cout << "Voce derrotou o " << inimigo.nom << "!\n";
            cout << "\nGanhou " << PlusXP << "de experiencia\n"; 

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
       //cout << endl << "os dados sao atk-inim play-def e dano inimigo" << inimigo.atk << player.def << danoInimigo << endl;
        if (danoInimigo > 0) {
            player.hp -= danoInimigo;
            cout << "O " << inimigo.nom << " causou " << danoInimigo << "  de dano a voce!\n";
            cout << "Sua vida agora e " << player.hp <<" \n";
        } else {
            cout << "O " << inimigo.nom << " nao causou dano a voce!\n";
        }

        // Verificar se o jogador foi derrotado apos o ataque do inimigo
        if (player.hp <= 0) {
            mortes ++;
            cout << "Voce foi derrotado pelo " << inimigo.nom << "!\n";
            break;
        }

        // Opcao para o jogador decidir entre atacar ou defender apos o ataque do inimigo
        cout << "\nPressione ENTER para continuar...\n";
        cin.ignore();
        cin.get();
    }

     if (player.xp >= 10 * player.nivel) {
        player.nivel++;
        potion ++;
        player.atk += 3; // Exemplo de aumento de atributos ao subir de nível
        player.def += 2;
        player.HPmax +=20; //aumenta a vida maxima do jogador
        player.hp =player.HPmax ; // Recupera HP ao subir de nível
        cout << "Parabens! Voce subiu para o nivel " << player.nivel << "!\n";
    }
}


void InimigoAparece(personagem &player, personagem inimigo[]) {
    int escolha;
    int sla;
    int level=player.nivel;

    sla = spawnInimigo(inimigo, level);

    //cout<<"\nvalor no vetor " << sla;
    cout << "\n(1) atacar \n(2) fugir";
    cin >> escolha;
    
    switch (escolha) {
        case 1:
            if (sla >= 0 && sla < 100) {
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
   
    personagem inimigo[100]; 
    personagem boss[5];
    personagem pers;
    personagem SavePers; //salvas os valores do jogados apos sua morte para serem aplicados no chefe
    int qtd=0; //funciona como um contador, para definir com qual chefe ira lutar/ qual e o chefe atual

    dados(inimigo);
     
    string nome;

    cout << "\nBem vindo ao RPG 2!\n";
    cout << "Versao 1.0 do jogo\n";
    cout << "\nClique para continuar\n";
    getchar();
    getchar();

    cout << "Qual e o nome do seu personagem?\n";
    getline(cin, nome);
    pers.nom = nome;
    cout << "\nNome do personagem: " << pers.nom << endl;

   while(mortes<6){
        cout << "\nVida: " << inimigo[0].hp << endl;
        cout << "Ataque: " << inimigo[0].atk << endl;
        cout << "Defesa: " << inimigo[0].def << endl;
        cout << "Gold: " << inimigo[0].gold << endl;
        cout << "xp: " << inimigo[0].xp << endl;
    
        InimigoAparece(inimigo[0], inimigo);
        int saveHp= inimigo[0].HPmax; //atualiza o valor do personagem depois que le morre (restaura a vida)

        if(inimigo[0].hp<=0){
            qtd++;
            inimigo[0].hp = saveHp;
            SavePers.hp= inimigo[0].hp;
            SavePers.atk= inimigo[0].atk;
            SavePers.def= inimigo[0].def;
            SavePers.gold= inimigo[0].gold;
            SavePers.xp= inimigo[0].xp;
            cout<< "qtd= "<< qtd;
            }

        if(InimigoDerrotado==5 && mortes>0){
            cout<<"\num chefe apareceu!";
            batalha(inimigo[0],SavePers);
        
        }
    }

    if(mortes>5){
        cout << "\nFim de jogo!\nVoce fez " << pontos << " pontos";

        ofstream Wpoints("dados.txt");
        if (!Wpoints) {
            cerr << "Erro ao abrir o arquivo de saída!" << endl;
            return 1;
        }

         Wpoints << pontos << endl;
         Wpoints.close();
         cout << "Dados foram escritos no arquivo com sucesso!\nConfira seu score!" << endl;
         cout << "\nObrigado por jogar!!!";
    }
    return 0;
}
