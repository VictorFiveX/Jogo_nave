#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ControlesDaTela.cpp"
void moldura()
{
	int x;
	system("cls");
	
	gotoxy(0,0);
	printf("\xC9");
	gotoxy(119,0);
	printf("\xBB");
	
	gotoxy(0,29);
	printf("\xC8");
	gotoxy(119,29);
	printf("\xBC");
	
	for(x=1; x<=118; x++)
	{
		gotoxy(x,0);
		printf("\xCD");
		gotoxy(x,29);
		printf("\xCD");
	}
	
	for(x=1; x<=28; x++)
	{
		gotoxy(0,x);
		printf("\xBA");
		gotoxy(119,x);
		printf("\xBA");
	}
	
}
void musica()
{
Beep(440, 545);
Beep(440, 545);
Beep(440, 545);
Beep(349, 409);
Beep(523, 136);
system("cls");
Cor(0x4);
moldura();
Beep(440, 545);
Beep(349, 409);
Beep(523, 136);
Beep(440, 1090);

Beep(659, 545);
Beep(659, 545);
Beep(659, 545);
Beep(698, 409);
Beep(523, 136);

Beep(415, 545);
Beep(349, 409);
Beep(523, 136);
Beep(440, 1090);
system("cls");
Cor(0x4C);
moldura();
Beep(880, 545);
Beep(440, 409);
Beep(440, 136);
Beep(880, 545);
Beep(831, 273);
Beep(784, 273);

Beep(740, 136);
Beep(698, 136);
Beep(740, 273);
Sleep(273);
Beep(415, 273);
Beep(554, 545);
Beep(587, 272);
Beep(554, 273);
system("cls");
Cor(0x4C0);
gotoxy(50,15);
printf("CREDITOS: PROFESSOR ME PERDOA ");
moldura();
Beep(523, 136);
Beep(494, 136);
Beep(523, 273);
Sleep(273);
Beep(349, 273);
Beep(415, 273);
Beep(349, 409);
Beep(415, 136);

Beep(523, 273);
Beep(440, 273);
Beep(523, 273);
Beep(659, 1090);

Beep(880, 545);
Beep(440, 409);
Beep(440, 136);
Beep(880, 545);
Beep(831, 273);
Beep(784, 273);
system("cls");
Cor(0xC0);
moldura();
gotoxy(50,15);
printf("CREDITOS: SAMUEL SILVA COSTA");
Beep(740, 136);
Beep(698, 136);
Beep(740, 273);
Sleep(273);
Beep(415, 273);
Beep(554, 545);
Beep(587, 272);
Beep(554, 273);

Beep(523, 136);
Beep(494, 136);
Beep(523, 273);
Sleep(273);
Beep(349, 273);
Beep(415, 545);
Beep(349, 409);
Beep(523, 136);

Beep(440, 545);
Beep(349, 409);
Beep(523, 136);
Beep(440, 1090);
Beep(523, 136);
Beep(440, 2090);
system("cls");
Cor(0xC000);
moldura();

Sleep(1000);
}
