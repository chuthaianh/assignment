#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
struct  Player{
    char name [15];
    int baseHP;
    int wp;
    float realHP;
};
//Prime Number

bool PrimeNumber(unsigned int n) {
    if (n <= 1) return false;
    for (unsigned int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
// Fibonacci Number

int fibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0;
    int b = 1;
    int c;
    
    for (unsigned int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}
int findNearestFibonacci(int x) {
    int a = 0;
    int b = 1;
    int c;
    
    while (b <= x) {
        c = a + b;
        a = b;
        b = c;
    }
    
    if (abs(a - x) <= abs(b - x)) {
        return a;
    } else {
        return b;
    }
}
// Perfect number
bool PerfectNumber(int n){
int sum=1;
    for (int i = 2; i < n; i++) {
        if (n % i ==0){
            sum +=i;
        } 
    }
    if (n == sum && n!= 1) return true;
        return false;
}

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
    if (players[0].baseHP < 99 || players[0].baseHP > 999){
		return 1;
    }
    if (players[0].wp < 0 || players[0].wp > 3){
		return 1;
    }
    if (players[1].baseHP < 1 || players[1].baseHP > 888){
		return 1;
    }
    if (players[1].wp < 0 || players[1].wp > 3){
		return 1;
    }
    if (ground < 1 || ground > 999){
		return 1;
    }
    //weapon
    //wp =1 & wp = 0
    if (players[0].wp == 1){
        players[0].realHP = players[0].baseHP;
    }
    if (players[0].wp == 0){
        players[0].realHP = (int)(players[0].baseHP/10);
    }
    if (players[1].wp == 1 && ground !=777){
        players[1].realHP = players[1].baseHP;
    }
    if (players[1].wp == 0 && ground !=777){
        players[1].realHP = (int)(players[1].baseHP/10);
    }
    //wp = 2
    if (players[0].baseHP != 999){
        if (players[0].wp == 2){
            players[0].realHP=players[0].baseHP;
            if (players[0].realHP < players[1].realHP){
            printf("0.50");
            return 0;
            }
        }
        if (players[1].wp == 2 && players[0].wp != 3 && ground != 777){
            players[1].realHP=players[1].baseHP;
            if (players[1].realHP < players[0].realHP){
            printf("0.50");
            return 0;
            }
        }
    }
    //wp = 3
    if ( players[0].wp == 3){
        players[0].realHP = players[0].baseHP*2;
        if (players[0].realHP > 999){
            players[0].realHP = 999;
        }
    }
    if (players[1].wp == 3){
        players[1].realHP = players[1].baseHP;
    }

    //players[0].baseHP = 999 (Arthur)
    if (players[0].baseHP == 999){
        printf("1");
        return 0;
    }
    //players[1].baseHP = 888 (Cerdic)
    if (players[1].baseHP == 888){
        if (players[0].baseHP == 999){
            printf("1");
            return 0;
        }else{
            printf("0.00");
            return 0;
        }
    }
    
    // baseHP = prime number
    if (PrimeNumber(players[0].baseHP)== true && PrimeNumber(players[1].baseHP)== false){
        printf("0.99");
        return 0;
    }
    if (PrimeNumber(players[0].baseHP)== false && PrimeNumber(players[1].baseHP)== true){
        printf("0.01");
        return 0;
    }
    if (PrimeNumber(players[0].baseHP)== true && PrimeNumber(players[1].baseHP)== true && players[0].baseHP == players[1].baseHP){
        printf("0.50"); 
        return 0;
    }
    //ground 
    for ( int i = 0; i <=1; i++ ){
        if (ground == players[i].baseHP ){
            players[i].realHP = players[i].realHP*1.1;
                if (players[i].realHP > 999) {
                    players[i].realHP = 999;
                }
        }
    }
    //ground = 666
    if (ground == 666){
        for ( int i = 0; i <=1; i++ ){
            if (fibonacci(players[i].baseHP) == players[i].baseHP){
                    players[i].realHP = players[i].baseHP;
            } else{
            players[i].realHP = findNearestFibonacci(players[i].baseHP);
            }
        }
    }
    //groud = 777
    
    if ( ground == 777){
        int n;
        scanf("%d", &n);
        if (n>1){
            char godWeapon[1000];
            char realhp[1000];
            int max = realhp[0];
            for (int i = 0; i < n; i++){
                godWeapon[i] = n+1+i;
            }
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (PerfectNumber(players[1].baseHP + godWeapon[i])== true){
                        realhp[j] = players[1].baseHP + godWeapon[i];
                    }
                }
            }
                for (int j = 0; j < n; j++){    
                    if (realhp[j] > max){
                        max = realhp[j];
                    }   
                }
            players[1].realHP=max;
        }
        if (n==1){
                if (PerfectNumber(players[1].baseHP + 2)== true){
                    players[1].realHP = players[1].baseHP + 2;
                }
            }
    }
    //ground = 999
    if ( ground == 999){
        char s[20];
        fgets(s,20,stdin);
        char s1[20]="Arthur";
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
    //probability
    probability=(players[0].realHP-players[1].realHP+999)/(float)2000;
    printf("%.2f", probability);
    
return 0;
}
