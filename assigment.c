#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void display(double out)
//display value of fOut in format of 0.XX
{
	if (out == 1)
    {
		printf("1");
	}
	else
    {
		printf("%.2f",out);
	}
}

char checkPrimeNumber(int hp)
{
    if (hp==0 || hp ==1) return 0;
    if (hp==2) return 1;
    for (int i=3;i*i <= hp; i++)
    {
        if (hp % i == 0) return 0;
    }
    return 1;
}
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

int main(void)
{
	int baseHP1, baseHP2, wp1, wp2, ground;
    //int i = 2;
   //int SNT1 = 1;
    //int SNT2 = 1;
    float P, realHP1, realHP2;
	double out = 0.0;
	scanf("%d %d %d %d %d",&baseHP1, &wp1, &baseHP2, &wp2, &ground);
    if (baseHP1 < 99 || baseHP1 > 999)
		return 1;
	
    if (wp1 < 0 || wp1 > 3)
		return 1;
	
    if (baseHP2 < 1 || baseHP2 > 888)
		return 1;
	
    if (wp2 < 0 || wp2 > 3)
		return 1;
	
    if (ground < 1 || ground > 999)
		return 1;
	
    if (wp1==1) realHP1=baseHP1;
    if (wp2==1) realHP2=baseHP2;
    
    if (wp1==0) 
    {
        int temp = baseHP1/10;
        realHP1 = temp;
    }
    if (wp2==0) 
    {
        int temp = baseHP2/10;
        realHP2 = temp;
    }

    if (ground==baseHP1)
    {
		realHP1*=1.10;
        if (realHP1>999) realHP1 = 999;
    }
	if (ground==baseHP2)
    {
		realHP2*=1.10;
        if (realHP2>999) realHP2 = 999;
    }

    if (wp1==2 && realHP1 < realHP2)
        {
            out = 0.5;
        }
        
    if (wp2==2 && realHP2 < realHP1 && wp1!=3) 
        {
            out = 0.5;
        }

    if (wp1 == 3)
    {
        realHP1 *= 2;
        if (realHP1>999) realHP1 = 999;
    }

    if (baseHP1 == 999) //vua arthur end game
    {
        display(1);
        return 1;
    }

    if (baseHP2 == 888) 
    {
        display(0.00);
        return 1;
    }

    if (checkPrimeNumber(baseHP1) == '1' && checkPrimeNumber(baseHP2) != '1')
    {
        display(0.99);
        return 0;
    }

    if (checkPrimeNumber(baseHP2) == '1' && checkPrimeNumber(baseHP1) != '1')
    {
        display(0.01);
        return 0;
    }
    if (checkPrimeNumber(baseHP1) == '1' && checkPrimeNumber(baseHP2) == '1' && baseHP1==baseHP2)
    {
        display(0.5);
        return 0;
    }
    int n;
   // int array[1000];
    if (ground == 666)
    {
        realHP1 = findNearestFibonacci(baseHP1);
        realHP2 = findNearestFibonacci(baseHP2);
    }
    if (ground == 777)
    {
        scanf("%d", &n);
        for (int i=0;i<n;i++)
        {
            scanf("%d", &n);
            
        }
    }
    out = (realHP1-realHP2+999)/2000;
	display(out);
	return 0;
}