#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

#include "window.h"
#include "get_tecla.h"

int main(int argc, char** argv)
{
	int c = 44, l = 192, x=4, y=0;
	char tecla_acao;
	char fundo[c][l];
	
	GenerateEmptyWindow(c, l, fundo);
	fundo[4][0] = 'O';
	printf("presione qualquer tecla para iniciar...\n");
  	tecla_acao = getche();
	
	FILE *dados_game_j1;

	FILE *dados_game_j2;
	
	while(1)
	{
		system("clear");
		dados_game_j1 = fopen("dados_game_j1.txt", "r+");

		dados_game_j2 = fopen("dados_game_j2.txt", "r");

		int l2, c2;
		fscanf(dados_game_j2, "%d %d \n", &l2, &c2);
		fclose(dados_game_j2);

		fundo[l2][c2] = 'X';

		printf("X: %3d    Y: %3d   >>>Player 1<<< You", x, y);
		printf("\nX: %3d    Y: %3d    Player 2\n", l2, c2);

		for(int i=0; i<c; i++)
		{
			for(int j=0; j<l; j++)
			{
				if(fundo[i][j] == 'X' && (i!=l2 && j!=c2))
				{
					fundo[i][j] = ' ';
				}
			}
		}

		ShowWindow(c,l,fundo);

		fprintf(dados_game_j1, "%d %d\n", x,y);

		tecla_acao = getche();
		switch(tecla_acao)
		{
			case 'd': x++; 
			fundo[x-1][y] = ' ';
			fundo[x][y] = 'O'; 
			break;
			case 'e': x--; 
			fundo[x+1][y] = ' ';
			fundo[x][y] = 'O';
			break;
			case 'f': y++; 
			fundo[x][y-1] = ' ';
			fundo[x][y] = 'O';
			break;
			case 's': y--; 
			fundo[x][y+1] = ' ';
			fundo[x][y] = 'O';
			break;
		}

		fclose(dados_game_j1);

		
	}
  	

	return 0;
}
