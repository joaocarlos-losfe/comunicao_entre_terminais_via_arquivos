#include <stdio.h>
#include <stdlib.h>

// gera uma 'jenela' vazia para inser��o de outras
void GenerateEmptyWindow(int c, int l, char windows[c][l])
{
	printf("window create...%dx%d\n", c, l);
	int i,j;
	for(i=0; i<c; i++)
	{
		for(j=0; j<l; j++)
		{
			if(i==0 || i== c-1)
			{
				windows[i][j] = '=';
			}
			else
			{
				windows[i][j] = ' ';
			}
			
		}
	}
	//player 1

	windows[2][0] = '+';
	windows[2][1] = '+';
	windows[2][2] = '+'; 
	windows[2][3] = '+';
	windows[2][4] = '+';
	windows[3][4] = '+';
	

	windows[6][0] = '+';
	windows[6][1] = '+';
	windows[6][2] = '+'; 
	windows[6][3] = '+';
	windows[6][4] = '+';
	windows[5][4] = '+';

	//-----

	//player 2

	windows[42][191] = '+';
	windows[42][190] = '+';
	windows[42][189] = '+'; 
	windows[42][188] = '+';
	windows[42][187] = '+';
	windows[41][187] = '+';

	windows[38][191] = '+';
	windows[38][190] = '+';
	windows[38][189] = '+'; 
	windows[38][188] = '+';
	windows[38][187] = '+';
	windows[39][187] = '+';
	



}

void ShowWindow(int c, int l, char windows[c][l])
{
	int i,j;
	
	for(i=0; i<c; i++)
	{
		for(j=0; j<l; j++)
		{
			printf("%c",windows[i][j]);
		}
		printf("\n");
	}
}

// insere a janela na tela. necessario ter una janela vazia criada antes
void CreateWindow(int c, int l, char empty_window[c][l], int c1, int l1, char window[c1][l1], int coordinateX, int coordinateY)
{
	
	int i, j;
	int y = coordinateY;
	int x = coordinateX;
	
	for(i=0; i<c1; i++)
	{
		for(j=0; j<l1; j++)
		{
			empty_window[x][y] = window[i][j];
			y++;
		}
		y = coordinateY;
		x++;
	}	
			
}