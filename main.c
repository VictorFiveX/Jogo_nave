#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "molde.cpp"
void main()
{
	
	int tecla=0, pos=3, tiro, x=0,y=0,z=0, tela[120][30], ponto=0, inimigo=0, xant=0, yant=0, zant=0;
	int vida=3;
	DesligaCursor();
	
	gotoxy(49,14);
	printf("Carregando....");
	Beep(440,500);      
	Beep(440,500);
	Beep(440,500);      
	Beep(349,350);     
	Beep(523,150);    
	Beep(440,500);   
	Beep(349,350);  
	Beep(523,150); 
	Beep(440,1000);
	Beep(659,500);     
	Beep(659,500);    
	Beep(659,500);   
	Beep(698,350);  
	Beep(523,150); 
	Beep(415,500);
	Beep(349,350);
	Beep(523,150);
	Beep(440,1000);

	menu:
    system("cls");
	moldura();
	gotoxy(50,1);
	printf("MENU");
	
	gotoxy(50,3);
	printf("Jogar");
	
	gotoxy(50, 5);
	printf("Tutorial");
	
	gotoxy(50,7);
	printf("Sair");
	
	gotoxy(2, 9);
	printf("Use a seta para cima e para baixo para navegar");
	gotoxy(2,10);
	printf("Pressione enter para selecionar ");

	while(1)
	{
		tecla = getch();
		gotoxy(45, pos);
		printf("   ");
		if(tecla == 72)
		{
			pos = pos - 2;
			Beep (170, 200);
			if(pos < 3)
			{
				pos = pos + 2;
			}
		}
		if(tecla == 80)
		{
			pos = pos + 2;
			Beep (170, 200);
			if(pos > 7)
			{
				pos = pos - 2;
			}
		}
		if(tecla == 13)
		{
			if(pos == 3)
			{
				goto jogar;
			}
			if(pos == 5)
			{
				goto tutorial;
			}
			if(pos == 7)
			{
				goto sair;
			}
		}
		gotoxy(45, pos);
		printf("\x3E");
	}
	tutorial:
	system("cls");
	moldura();
	gotoxy(45,2);
	printf("Bem-vindo ao tutorial!");
	gotoxy(5,4);
	printf("%c - Podem estar sorrindo mas, ELES SAO SEU PIOR INIMIGO MATE TODOS ELES!", 2);
	gotoxy(5,5);
	printf("%c - Ah um belo coracao, ATIRE NELE PARA ELE TE DAR VIDA!", 3);
	gotoxy(5,6);
	printf("%c - Parace especial ne, ELE TE DA PONTOS ADICIONAIS!", 4);
	
	gotoxy(4, 9);
	printf("Controles: ");
	gotoxy(4,10);
	printf("MATAR(ATIRA): espaço");
	gotoxy(4,11);
	printf("MOVIMENTACAO: para esquerda, seta esquerda o resto voce sabe espero que voce nao seja burro");
	gotoxy(4,12);
	printf("A nave nao se move na vertical apenas na horizontal");
	
	gotoxy(2,15);
	printf("HISTORIA");
	gotoxy(4,16);
	printf("Um aluno desesperado para passar de semestre cria um mundo parelelo onde uma nave destrui rosto sorrindo"); 
	gotoxy(4,17);
	printf("atira em coracao e simbolos para mostrar ao professor que ele merecer passar (ou nao)");
	
	
	gotoxy(4,20);
    printf("Para voltar pressione enter!");
    tecla = getch();
    if(tecla == 13)
    {
    	goto menu;
	}
	
	jogar:
	system("cls");

	Beep(440,500);      
	Beep(440,500);
	Beep(440,500);      
	Beep(349,350);     
	Beep(523,150);    
	Beep(440,500);   
	Beep(349,350);  
	Beep(523,150); 
	Beep(440,1000);
	Cor(0x4);

	gotoxy(50,14);
	printf("Primeira fase");
	Beep (170, 400);
	Sleep(2000);
	system("cls");
	Cor(0x07);
	moldura();
	gotoxy(pos,26);
	printf("A");
	gotoxy(pos-1,27);
	printf("\xC9 \xBB");
	gotoxy(2,28);
	printf("Pontos = %02d",ponto);
	gotoxy(15,28);
	printf("Inimigos: %02d",inimigo);
	gotoxy(30,28);
	printf("Vidas: %02d",vida);
	
	//fase 1
	while(ponto<5)
	{
		srand(time(NULL));
		if(kbhit())
		{
			tecla = getch();
			Beep (200, 40);
			gotoxy(pos,26);
			printf(" ");
			gotoxy(pos-1,27);
			printf("   ");
			printf(" ");
			if(tecla == 77)
			{
				if(pos<116)
				{
					pos++;
				}
			}
			if(tecla == 75)
			{
				if(pos>2)
				{
					pos--;
				}
			}
			gotoxy(pos,26);
			printf("A");
			gotoxy(pos-1,27);
			printf("\xC9 \xBB");
			if(tecla==32)
			{
				Beep (400, 200);
				for(tiro=25;tiro>=1;tiro--)
				{
					gotoxy(pos,tiro);
					Cor(0xFC);
					printf("^");
					Cor(0x07);
					Sleep(40);
					gotoxy(pos,tiro);
					printf(" ");	
					if(tela[pos][tiro]==1)
					{
						Beep(120,300);
						ponto++;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}	
					if(tela[pos][tiro]==2)
					{
						Beep(220,300);
						vida++;
						gotoxy(30,28);
						printf("Vidas: %02d",vida);
						tela[pos][tiro]=0;
						break;	
					}		
					if(tela[pos][tiro]==3)
					{
						Beep(220,300);
						ponto = ponto + 2;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}	
				}
			}
		}
		if(!kbhit())
		{
			x=rand() % 110+5;
			y=rand() % 20+1;	
			z=rand() % 8+1;
			if(x != xant && z != zant|| y != yant && z != zant)	
			{	
				if(z % 2 == 0)
				{
					gotoxy(x,y);
					Cor(0x4);
					printf("%c", 3);
					Cor(0x07);
					tela[x][y]=2;
					xant = x;
					yant = y;
					zant = z;
				}
				else if(z == 1)
				{
					gotoxy(x,y);
					Cor(0x6);
					printf("%c", 4);
					Cor(0x07);
					tela[x][y]=3;
					xant = x;
					yant = y;
					zant = z;
				}
				else 
				{
					gotoxy(x,y);
					printf("%c", 02);
					tela[x][y]=1;
					inimigo++;	
					gotoxy(15,28);
					printf("Inimigos: %02d",inimigo);
					xant = x;
					yant = y;
				}
				if(inimigo % 5 == 0 && inimigo!=0)
				{
					vida--;
					gotoxy(30,28);
					printf("Vidas: %02d",vida);
					if(vida < 0)
					{
						system("cls");
						moldura();
						gotoxy(50,15);
						Cor(0x4);
						printf("Game Over!!!");
						Sleep(2000);
						getch();
						exit(1);
					}
				}
			}
		}
	}
	//fase 2	
 	Cor(0x0770);
 	moldura();
	Beep(659,500);     
	Beep(659,500);    
	Beep(659,500);   
	Beep(698,350);  
	Beep(523,150); 
	Beep(415,500);
	Beep(349,350);
	Beep(523,150);
	Beep(440,1000);
	gotoxy(50,14);
	printf("Segunda fase");
	Beep (170, 400);
	Sleep(2000);
	system("cls");
	moldura();
	tecla=0, pos=60, tiro, x,y, tela[120][30], ponto=0, inimigo=0, xant=0, yant=0, vida=3;
	gotoxy(2,28);
	printf("Pontos = %02d",ponto);
	gotoxy(15,28);
	printf("Inimigos: %02d",inimigo);
	gotoxy(30,28);
	printf("Vidas: %02d",vida);
	while(ponto<10)
	{
		srand(time(NULL));
		if(kbhit())
		{
			tecla = getch();
			Beep (200, 40);
			gotoxy(pos,26);
			printf(" ");
			gotoxy(pos-1,27);
			printf("   ");
			printf(" ");
			if(tecla == 77)
			{
				if(pos<116)
				{
					pos++;
				}
			}
			if(tecla == 75)
			{
				if(pos>2)
				{
					pos--;
				}
			}
			gotoxy(pos,26);
			printf("A");
			gotoxy(pos-1,27);
			printf("\xC9 \xBB");
			if(tecla==32)
			{
				Beep (400, 200);
				for(tiro=25;tiro>=1;tiro--)
				{
					gotoxy(pos,tiro);
					Cor(0xFC);
					printf("^");
					Cor(0x0770);
					Sleep(40);
					gotoxy(pos,tiro);
					printf(" ");	
					if(tela[pos][tiro]==1)
					{
						Beep(120,300);
						ponto++;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}	
					if(tela[pos][tiro]==2)
					{
						Beep(220,300);
						vida++;
						gotoxy(30,28);
						printf("Vidas: %02d",vida);
						tela[pos][tiro]=0;
						break;	
					}
					if(tela[pos][tiro]==3)
					{
						Beep(220,300);
						ponto = ponto + 2;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}			
				} 
			}
		}
		if(!kbhit())
		{
			x=rand() % 110+5;
			y=rand() % 20+1;	
			z=rand() % 15+1;
			if(x != xant && z != zant|| y != yant && z != zant)	
			{	
				if(z % 2 == 0)
				{
					gotoxy(x,y);
					Cor(0x4);
					printf("%c", 3);
					Cor(0x0770);
					tela[x][y]=2;
					xant = x;
					yant = y;
					zant = z;
				}
				else if(z == 1)
				{
					gotoxy(x,y);
					Cor(0x6);
					printf("%c", 4);
					Cor(0x0770);
					tela[x][y]=3;
					xant = x;
					yant = y;
					zant = z;
				}
				else 
				{
					gotoxy(x,y);
					printf("%c", 02);
					tela[x][y]=1;
					inimigo++;	
					gotoxy(15,28);
					printf("Inimigos: %02d",inimigo);
					xant = x;
					yant = y;
				}
				if(inimigo % 5 == 0 && inimigo!=0)
				{
					vida--;
					gotoxy(30,28);
					printf("Vidas: %02d",vida);
					if(vida < 0)
					{
						system("cls");
						moldura();
						gotoxy(50,15);
						printf("Game Over!!!");
						Sleep(2000);
						getch();
						exit(1);
					}
				}
			}
		}
	}	

	// Fase Final
	Cor(0x07);
 	moldura();
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
	gotoxy(50,14);	
	printf("Fase Final");
	Beep (170, 400);
	Sleep(1000);
	gotoxy(46,14);
	printf("O Mundo esta um caos va rapido");
	Beep (170, 400);
	Sleep(2000);
	system("cls");
	moldura();
	Cor(y);
	tecla=0, pos=60, tiro, x,y, tela[120][30], ponto=0, inimigo=0, xant=0, yant=0, vida=3;
	gotoxy(2,28);
	printf("Pontos = %02d",ponto);
	gotoxy(15,28);
	printf("Inimigos: %02d",inimigo);
	gotoxy(30,28);
	printf("Vidas: %02d",vida);
	while(ponto<15)
	{
		srand(time(NULL));
		if(kbhit())
		{
			Cor(x);
			tecla = getch();
			Beep (200, 40);
			gotoxy(pos,26);
			printf(" ");
			gotoxy(pos-1,27);
			printf("   ");
			printf(" ");
			Cor(0x0);
			if(tecla == 77)
			{
				if(pos<116)
				{
					pos++;
				}
			}
			if(tecla == 75)
			{
				if(pos>2)
				{
					pos--;
				}
			}
			gotoxy(pos,26);
			Cor(x);
			printf("A");
			gotoxy(pos-1,27);
			Cor(y);
			printf("\xC9 \xBB");
			if(tecla==32)
			{
				Beep (400, 200);
				for(tiro=25;tiro>=1;tiro--)
				{
					gotoxy(pos,tiro);
					Cor(z);
					printf("^");
					Cor(0x0);
					Sleep(40);
					gotoxy(pos,tiro);
					printf(" ");	
					if(tela[pos][tiro]==1)
					{
						Beep(120,300);
						ponto++;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}	
					if(tela[pos][tiro]==2)
					{
						Beep(220,300);
						vida++;
						gotoxy(30,28);
						printf("Vidas: %02d",vida);
						tela[pos][tiro]=0;
						break;	
					}
					if(tela[pos][tiro]==3)
					{
						Beep(220,300);
						ponto = ponto + 2;
						gotoxy(2,28);
						printf("Pontos = %02d",ponto);
						tela[pos][tiro]=0;
						break;	
					}				
				}
			}
		}
		if(!kbhit())
		{
			x=rand() % 110+5;
			y=rand() % 20+1;	
			z=rand() % 20+1;
			if(x != xant && z != zant|| y != yant && z != zant)	
			{	
				if(z % 2 == 0)
				{
					gotoxy(x,y);
					Cor(z);
					printf("%c", 3);
					tela[x][y]=2;
					xant = x;
					yant = y;
					zant = z;
				}
				else if(z == 1 || z == 5)
				{
					gotoxy(x,y);
					Cor(y);
					printf("%c", 4);
					tela[x][y]=3;
					xant = x;
					yant = y;
					zant = z;
				}
				else 
				{
					gotoxy(x,y);
					Cor(x);
					printf("%c", 02);
					tela[x][y]=1;
					inimigo++;	
					gotoxy(15,28);
					printf("Inimigos: %02d",inimigo);
					xant = x;
					yant = y;
				}
				if(inimigo % 5 == 0 && inimigo!=0)
				{
					vida--;
					gotoxy(30,28);
					printf("Vidas: %02d",vida);
					if(vida < 0)
					{
						system("cls");
						moldura();
						gotoxy(50,15);
						printf("Game Over!!!");
						Sleep(2000);
						getch();
						exit(1);
					}
				}
			}
		}
	}	
	
	system("cls");
	Cor(0x07);
	Sleep(2000);
	printf("VOCE VENCEU!!! AS FORCAS DO MAL VENCARAM..........");
	Beep (170, 400);
	gotoxy(50,14);
	printf("A");
    gotoxy(50-1,15);
	printf("\xC9 \xBB");
	gotoxy(52,14);
	printf("* *");
	Sleep(1000);
	gotoxy(0,14);
	printf("VOCE ERA DAS FORCAS DO MAL, NAO SABIA ?");
	Beep (170, 400);
	Sleep(3000);
	gotoxy(70,15);
	printf("PUTS NEM ME LIGUEI");
	Beep (180, 400);
	Sleep(3000);
	gotoxy(70,17);
	printf("QUE MERDA HEIM, A GENTE SE VE");
	Beep (180, 400);
	Sleep(3000);
	gotoxy(0, 16);
	printf("VOU DESATIVAR A NAVE, FALO MANO");
	Beep (180, 400);
	gotoxy(52, 14);
	printf("*  ");
	gotoxy(53, 14);
	printf("*");
	for(x = 14; x < 29; x++)
	{
		Sleep(300);
		gotoxy(53,x-1);
		printf(" ");
		gotoxy(53,x);
		printf("*");
		Beep (100, 400);
	}
	gotoxy(53,x);
	printf(" ");
	Beep (180, 400);
	Sleep(2000);
	gotoxy(50-1,15);
	printf("         ");
	Beep (500, 400);
	Sleep(2000);
	gotoxy(50,14);
	printf(" ");
	Beep (500, 400);
	Sleep(1000);
	system("cls");
	printf("FIM");
	Beep (10, 5000);
	
	goto sair;
	
	sair:
	system("cls");
	musica();
	exit(1);
}
