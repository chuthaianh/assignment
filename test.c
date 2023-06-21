#include<stdio.h>
#include<string.h>
struct  Player{
    char name [15];
    int baseHP;
    int wp;
    float realHP;
};
int main(){
    //TASK 1 & 2

    //player
    struct Player player1;
    struct Player player2;
    strcpy(player1.name,"Cavalier");
    strcpy(player2.name,"Saxon");
    struct Player players[] = {player1, player2};
    for ( int i = 0; i <=1; i++ ){
        scanf("%d\n",&players[i].baseHP);
        scanf("%d\n",&players[i].wp);
    }
    for ( int i = 0; i <=1; i++ ){
        if (players[i].wp == 1 )
        {
                players[i].realHP = players[i].baseHP;
            }else if (players[i].wp == 0){
                players[i].realHP = (int)(players[i].baseHP/10);
            }
    }
    // TASK 3

    //ground
    int ground;
    scanf("%d",&ground);
    for ( int i = 0; i <=1; i++ ){
        
            if (ground == players[i].baseHP ){
                players[i].realHP = players[i].realHP*1.1;
                if (players[i].realHP > 999) {
                    players[i].realHP = 999;
                }
            }
    }
    //TASK 4
    if (players[0].wp == 2){
        if(players[0].realHP < players[1].realHP){
            probability = (float)0.50;
        }else {
            probability=(players[0].realHP-players[1].realHP+999)/(float)2000;
        }
    }
    if (players[1].wp == 2){
        if(players[1].realHP < players[0].realHP){
            probability = (float)0.50;
        }else {
            probability=(players[0].realHP-players[1].realHP+999)/(float)2000;
        }
    }
    // Probability of Cavalier against Saxon
    float probability; 
    probability=(players[0].realHP-players[1].realHP+999)/(float)2000;
    printf("%.2f",probability);

    return 0;
}
