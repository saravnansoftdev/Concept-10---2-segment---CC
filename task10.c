

//Header file...
#include<reg51.h>

//for segment selction...
sbit D1 = P3^0;
sbit D2 = P3^1;

//for signal selection..
sbit N_Red = P3^2;
sbit N_Yellow = P3^3;
sbit N_Green = P3^4;

sbit S_Red = P3^5;
sbit S_Yellow = P3^6;
sbit S_Green = P3^7;



//function declarations...
void delay(unsigned int d);
void portInit(void);
void North_signal(void);
void South_signal(void);
void Stay_alert(void);


//for common cathode...
unsigned char arr_cc[10] = {0x3f, 0x06, 0x5b,0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char d1, d2; //digit1 and digit2
unsigned int i;
	
//entry loop of the program...
void main(void)
{
	portInit();
	//infinite loop...
	while(1)
	{
		North_signal();
		Stay_alert();
		South_signal();
		Stay_alert();
	}
}

void North_signal(void)
{
		//North Signal opening
		for(i=1; i<=40; i++)
		{
			//P3 = 0x & (~0xfc);
			N_Red = S_Green = 1;
			d1=i/10;
			D1=1;D2=0;
			P2 = arr_cc[d2];delay(1);
			d2=i%10;
			D2=1;D1=0;
			P2 = arr_cc[d1];delay(4);
			N_Red = S_Green = 0;
		}	
}

void South_signal(void)
{
		//South signal opening
		for(i=1; i<=40; i++)
		{
			//P3 = 0x & (~0xfc);
			N_Green = S_Red = 1;
			d1=i/10;
			D1=1;D2=0;
			P2 = arr_cc[d2];delay(1);
			d2=i%10;
			D2=1;D1=0;
			P2 = arr_cc[d1];delay(4);
			N_Green = S_Red = 0;
		}
	}

void Stay_alert(void)
{
		//Stay alert
		for(i=1; i<=20; i++)
		{
			//P3 = 0x & (~0xfc);
			N_Yellow = S_Yellow = 1;
			d1=i/10;
			D1=1;D2=0;
			P2 = arr_cc[d2];delay(1);
			d2=i%10;
			D2=1;D1=0;
			P2 = arr_cc[d1];delay(4);
			N_Yellow = S_Yellow = 0;
		}	
}

//Port Initialization...
void portInit(void)
{
	P2 = 0x00;
	P3 = 0x00;
}

//delay function...
void delay(unsigned int d)
{
	unsigned int i, j;
	for(i=0; i<d; i++)
	{
		for(j=0; j<8400; j++);
	}
}
