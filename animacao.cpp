#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ControlesDaTela.cpp"

void anima()
{
	int x, y;
	DesligaCursor();

	for(x = 2, y=59; x < 6, y > 53; x++, y--)
	{
		gotoxy(y, x);
		printf("/");
	}
	for(x = 0; x < 15; x++) 
	{
		gotoxy(60, x+2);
		printf("|");
	}
	Sleep(1500);
	system("cls");
	
   for(y = 40; y < 60; y++)
   {
	   	gotoxy(y,3);
	   	printf("_");
	   	gotoxy(y,13);
	   	printf("_");
	   	gotoxy(y, 8);
	   	printf("_");
	}	
	for(x = 13; x > 8; x--)
	{
		gotoxy(40, x);
		printf("|");
		gotoxy(60, x-5);
		printf("|");
	}
	Sleep(1500);
	system("cls");
	
	for(y = 50; y < 60; y++)
   {
	   	gotoxy(y,3);
	   	printf("_");
	   	gotoxy(y,13);
	   	printf("_");
	   	gotoxy(y, 8);
	   	printf("_");
	}	
	for(x = 4; x < 14; x++)
	{
		gotoxy(60, x);
		printf("|");
	}
	Sleep(1500);
	system("cls");
	
}
