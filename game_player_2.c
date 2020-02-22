#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

#include "window.h"
#include "get_tecla.h"

int main(int argc, char** argv)
{
	int c = 44, l = 192, x=40, y=l -1;
	char tecla_acao;
	char fundo[c][l];
	
	GenerateEmptyWindow(c, l, fundo);
	fundo[40][191] = 'X';
	printf("presione qualquer tecla para iniciar...\n");
  	tecla_acao = getche();
	
	FILE *dados_game_j2;

	FILE *dados_game_j1;
	
	while(1)
	{
		system("clear");
		dados_game_j2 = fopen("dados_game_j2.txt", "r+");
		
		dados_game_j1 = fopen("dados_game_j1.txt", "r");

		int l1, c1;
		fscanf(dados_game_j1, "%d %d\n", &l1, &c1);
		fclose(dados_game_j1);

		fundo[l1][c1] = 'O';

		printf("X: %3d    Y: %3d   >>>Player 2<<< You", x, y);
		printf("\nX: %3d    Y: %3d    Player 1\n", l1, c1);

		for(int i=0; i<c; i++)
		{
			for(int j=0; j<l; j++)
			{
				if(fundo[i][j] == 'O' && (i!=l1 && j!=c1))
				{
					fundo[i][j] = ' ';
				}
			}
		}

		ShowWindow(c,l,fundo);

		fprintf(dados_game_j2, "%d %d\n", x,y);

		tecla_acao = getche();
		switch(tecla_acao)
		{
			case 'd': x++; 
			fundo[x-1][y] = ' ';
			fundo[x][y] = 'X'; 
			break;
			case 'e': x--; 
			fundo[x+1][y] = ' ';
			fundo[x][y] = 'X';
			break;
			case 'f': y++; 
			fundo[x][y-1] = ' ';
			fundo[x][y] = 'X';
			break;
			case 's': y--; 
			fundo[x][y+1] = ' ';
			fundo[x][y] = 'X';
			break;
		}

		fclose(dados_game_j2);
		
	}
  	

	return 0;
}
