﻿#include<stdio.h>
#include<string.h>
struct  Player{
    char name [15];
    int baseHP;
    int wp;
    int realHP;
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
        scanf("%d",&players[i].baseHP);
    }
    for ( int i = 0; i <= 1; i++ ){
        scanf("%d",&players[i].wp);
    }
    for ( int i = 0; i <=1; i++ ){
        if (players[i].wp == 1 ){
                players[i].realHP = players[i].baseHP;
            }else if (players[i].wp == 0){
                players[i].realHP = (int)(players[i].baseHP/10);
            }
    }
    float probability; 
    probability=((player1.realHP-player2.realHP+999)/2000);
    printf("%.2f",probability);

    return 0;
}
 


