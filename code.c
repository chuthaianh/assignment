#include<stdio.h>
#include<string.h>
struct  Player{
    char name [15];
    int baseHP;
    int wp;
    int realHP;
};

int main(void){
    float probability;
    //TASK 1 & 2
    //player
    struct Player player1;
    struct Player player2;
    strcpy(player1.name,"Cavalier");
    strcpy(player2.name,"Saxon");
    struct Player players[] = {player1, player2};
     for ( int i = 0; i <=1; i++ ){
        scanf("%d",&players[i].baseHP);
        scanf("%d",&players[i].wp);
    }
    //ground
    int ground;
    scanf("%d",&ground);
    //weapon
    for ( int i = 0; i <=1; i++ ){
        if (players[i].wp == 1 ){
                players[i].realHP = players[i].baseHP;
            }else if (players[i].wp == 0){
                players[i].realHP = (int)(players[i].baseHP/10);
            }
    }
    if (players[0].wp == 2){
        players[0].realHP=players[0].baseHP;
        if (players[0].realHP < players[1].realHP){
        printf("0.50");
        }else{
            probability=(players[0].realHP-players[1].realHP+999)/(float)2000;
        }
    }
    if (players[1].wp == 2){
        players[1].realHP=players[1].baseHP;
        if (players[1].realHP < players[0].realHP){
        printf("0.50");
        }else{
            probability=(players[0].realHP-players[1].realHP+999)/(float)2000; 
        }
    }
    //ground = 999
    if ( ground == 999){
        char s[20];
        fgets(s,20,stdin);
        char s1[20] = "Arthur";
        char s2[20]="arthur";
        for ( int j = 0; j < 100; j++ ){
            if (j >8){
                for ( int i = 0; i <=1; i++ ){
                players[0].realHP-=50;
                    if ( players[0].realHP < 1){
                        players[0].realHP = 1;
                    }
                }
            }
            if (s[j] == 's' || s[j] == 'a' || s[j] == 'x' || s[j] == 'o' || s[j] == 'n'){
                int count = 0;
                count++;
                if (count > 3){
                    players[1].realHP +=50;
                    if ( players[1].realHP > 888 ){
                        players[1].realHP = 888;
                    }
                }
            }
            if(strcmp(s,s1)==0 || strcmp(s,s2)==0){
                players[0].wp = 0;
            }
        }
    }
    if (probability == 1){
        printf("1");
    }
    else {
        printf("%.2f", probability);
    }
return 0;
}