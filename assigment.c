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

int main(void)
{
	//read data from input to corresponding variables
	int baseHP1, baseHP2, wp1, wp2, ground;
    int i = 2;
    int SNT1 = 1;
    int SNT2 = 1;
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
    
    if (wp1 == 2 || wp2 == 2)
    {
        if (wp1==2)
        {
            realHP1=baseHP1;
        }
        else if (wp2==2) 
        {

        }
        else if (wp1 == 2 && wp2 == 2)
        {
            
        }
    }
    
    while (baseHP1<=1)
	for (i=2; i<=baseHP1/2 ; i++)
	  if (baseHP1%i == 0)
	  {
      SNT1 = 0;
      break;
	  }
	while (baseHP2<=1)
	  for (i=2; i<=baseHP2/2; i++)
	  if (baseHP2%i == 0)
	  {
      SNT2 = 0;
      break;
	  }
	//Truong hop dia hinh dac biet
	if (ground==baseHP1)
		realHP1*=1.10;
	if (ground==baseHP2)
		realHP2*=1.10;
	//Truong hop su dung vu khi dac biet
	if (wp1==3)
	{
		realHP1*=2;
		if (wp2==2)
			wp2=1;//Ao giap cua Saxon mat tac dung
	}
	if (realHP1>999)//Neu realHP vuot qua 999 thi lay bang 999
		realHP1=999;
	if (realHP2>999)
		realHP2=999;
out=(realHP1-realHP2+999)/2000;//Cho de ct tinh xa´c suat

//Truong hop vua Arthur va Cerdic dich than chien dau
	if (baseHP1==999)
		out=1;
	else 
		if (baseHP2==888)
			out=0;
if ((out<0.5 && wp1==2) || (out>0.5 && wp2==2))
	out=0.5;






	display(out);
	return 0;
}