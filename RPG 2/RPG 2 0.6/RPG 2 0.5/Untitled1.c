#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int mercado(int potion, int gold){
    srand(time(NULL));
    int chanmerc= rand() % 1;
    char comprar;

    switch(chanmerc){
        case(1):

            printf("\n ");
            printf("\nvoce encontrou uma loja");
            printf("\n pressione (p) para comprar uma pocao");
            scanf("%c", &comprar);

            if(comprar=='p'){
                    if(gold>=15){
                potion=potion+1;
                gold-15;
                }
            else{
                printf("voce nao tem dinheiro suficiente");
            }
            }
              break;
    }
    return potion;
}

int combate(int hp, int atk, int atkp, int hpp, int pocao){
    char decisao;
    char p;
    char a;
    int hpmax=150;


    char nome[20];
    printf("\nescolha atacar(a) ou pocao(p)");
    scanf(" %c", &decisao);
    if(decisao=='p'){
            if(pocao>0){
        printf("\nvoce usou a pocao ");
        hpp=hpp+30;
         pocao-1;
         if(hpp>hpmax){
            hpp=hpmax;
        }
        printf("\nsua vida agora e %d", hpp);
    }
        else{
            printf("voce nao tem mais pocoes!");
        }
    }
    else if(decisao=='a'){
   int dano = atkp;
        printf("\nVoce atacou o inimigo e causou %d de dano!\n", dano);
        printf("\nA vida do inimigo agora e %d", hp);
        hp -= dano;

    }
    return hp;
}


int combateii(int hp, int atk, int atkp){
    char decisao;
    char p;
    char a;
    int dano = atkp;

    printf("\no inimigo te atacou e infringiu %d de dano!\n", dano);
    hp -= dano;

    if (hp <= 0) {
        printf("\nO voce morreu!\n");
    }
        printf("\nagora voce tem %d de HP restante.\n", hp);

     return hp;
}


int drop(int dinheiro){
    srand(time(NULL));
    int gold=rand() % 11;
    int golda=dinheiro;


    switch(gold){

        case(0):
            printf("\nvoce ganhou 0 moedas :(");
            golda=golda+0;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

        case(1):
            printf("\nvoce ganhou 1 moeda!");
            golda=golda+1;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

        case(2):
            printf("\nvoce ganhou 2 moedas!");
            golda=golda+2;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

        case(3):
            printf("\nvoce ganhou 3 moedas!");
            golda=golda+3;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

         case(4):
            printf("\nvoce ganhou 4 moedas!");
            golda=golda+4;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

          case(5):
            printf("\nvoce ganhou 5 moedas!");
            golda=golda+5;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

          case(6):
            printf("\nvoce ganhou 6 moedas!");
            golda=golda+6;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

           case(7):
            printf("\nvoce ganhou 7 moedas!");
            golda=golda+7;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

             case(8):
            printf("\nvoce ganhou 8 moedas!");
            golda=golda+8;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

             case(9):
            printf("\nvoce ganhou 9 moedas!");
            golda=golda+9;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

             case(10):
            printf("\nvoce ganhou 10 moedas!");
            golda=golda+10;
            printf("\nagora voce tem %d moedas", golda);
            return golda;
            break;

    }

}



int main (){

    int dinheiro=10;
    int pocao=2;
    char c;
    char nome[20];
    //STATUS
    //ratão
    int hpr=80;
    int atkr=10;

    //morcego
    int hpm=100;
    int atkm=15;

    //Urso
    int hpu=150;
    int atku=30;

    //dragao
    int hpd=200;
    int atkd=40;

    //player
    int hpp=150;
    int atkp=20;


    while(hpp>0){
    printf("                                                          ∑ *RPG SUPER FODA* Ω");

    printf("\ndigite o nome do seu personagem:");
    scanf("%s", nome);
    printf("\nvoce tem %d moedas", dinheiro);
    printf("\nvoce tem %d de pocoes", pocao);

    printf("\n ");
    printf("\n ");

    printf("\nencontrou um inimigo!");
    srand(time(NULL));
    int tipo= rand() % 4;

    switch(tipo){

    case(0):
        printf("aparareceu um ratao!");
        while(hpr>0 && hpp>0){
            hpr=combate(hpr, atkr, atkp, hpp,pocao);
            printf("\n ");
            printf("\nfim do turno. Aperte qualque tecla para continuar");
            getchar();
            getchar();

            if(hpr>0){
                printf("\n ");
                printf("o ratao ataca!");
                hpp= combateii(hpp,atkp, atkr);
            }
        }
             if(hpr<=0){
            printf("\n ");
            printf("\no ratao foi derrotado!");
            dinheiro=drop(dinheiro);
            pocao=mercado(pocao,dinheiro);

            printf("Deseja continuar? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);

            if (continuar == 'n') {
                break;
            }

             }

             else if(hpp<=0){
            printf("\n perdeu playboy!");
            }

            break;


       case(1):
        printf("aparareceu um morcego!");
        while(hpm>0 && hpp>0){
            hpm=combate(hpm, atkm, atkp, hpp, pocao);
            printf("\n ");
            printf("\nfim do turno. Aperte qualquer tecla para continuar");
            getchar();
            getchar();

            if(hpm>0){
            printf("\n ");
            printf("\no morcego ataca!");
            hpp= combateii(hpp,atkp, atkm);
        }
        }
             if(hpm<=0){
            printf("\n ");
            printf("/no morcego foi derrotado!");
            dinheiro=drop(dinheiro);
            pocao=mercado(pocao,dinheiro);

            printf("Deseja continuar? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);
            pocao=mercado(pocao,dinheiro);

            if (continuar == 'n') {
                break;
            }

             }

             else if(hpp<=0){
            printf("\n perdeu playboy!");
        }
        break;


        case(2):
        printf("aparareceu um urso!");
        while(hpu>0 && hpp>0){
            hpu=combate(hpu, atku, atkp, hpp, pocao);
            printf("\n ");
            printf("\nfim do turno. qualquer para continuar");
            getchar();
            getchar();

            if(hpu>0){
            printf("\n ");
            printf("o urso ataca!");
            hpp= combateii(hpp,atkp, atku);
        }
        }
             if(hpu<=0){
            printf("\n ");
            printf("\no urso foi derrotado!");
            dinheiro=drop(dinheiro);
            pocao=mercado(pocao,dinheiro);

            printf("Deseja continuar? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);

            if (continuar == 'n') {
                break;
            }

             }

             else if(hpp<=0){
            printf("\n perdeu playboy!");
        }
        pocao=mercado(pocao, dinheiro);

            break;


        case(3):
        printf("aparareceu um dragao!");
        while(hpd>0 && hpp>0){
            hpd=combate(hpd, atkd, atkp,hpp, pocao);
            printf("\n ");
            printf("\nfim do turno. Aperte qualqur para continuar");
            getchar();
            getchar();


            if(hpd>0){
            printf("\n ");
            printf("o dragao ataca!");
            hpp= combateii(hpp,atkp, atkd);
        }
        }
             if(hpd<=0){
            printf("\n ");
            printf("\nno dragao foi derrotado!");
            dinheiro=drop(dinheiro);

            printf("Deseja continuar? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);
            pocao=mercado(pocao,dinheiro);
            if (continuar == 'n') {
                break;
            }

             }

             else if(hpp<=0){
            printf("\n perdeu playboy!");

        }
        break;
}

    hpr = 80;
    hpm=100;
    hpu=150;
    hpd=200;

    return 0;
}
}
