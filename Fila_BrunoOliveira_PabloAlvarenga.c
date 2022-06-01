#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila2.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main()
{

	struct sfila filaCamposGuarus, filaGuarusCampos;

	char placa[7], placaSaindoDeCampos[8], placaSaindoDeGuarus[8];

	int opcao = 0, contador = 0, continuar = 1;

	qinit(&filaCamposGuarus);
	qinit(&filaGuarusCampos);

	while(1)
	{
		printf("1) - Cadastrar Sentido Campos -> Guarus\n\n2) - Cadastrar Sentido Guarus -> Campos\n\n3) - Liberar Travessia\n\n4) - Sair\n\n ---->> ");
		scanf("%d",&opcao);

		switch (opcao)
		{
			case 1:
			{
				continuar = 1;
				while(continuar == 1)
				{
					if (qisFull(&filaCamposGuarus))
					{
						printf("\nFila cheia!\n\n");
						break;
					}
					else
					{
						printf("\nEscreva a placa do carro: ");
						scanf(" %s", placa);
						for(contador = 0; contador <= 0; contador++)
						{
							enqueue(&filaCamposGuarus,placa[contador]);
						}
					}
					printf("\n\ngostaria de adicionar mais um carro? Escreva 0 para nao e 1 para sim: ");
					scanf("%d",&continuar);
				}
				break;
			}
			
			case 2:
			{
				continuar = 1;
				while(continuar == 1)
				{
					if (qisFull(&filaGuarusCampos))
					{
						printf("\nFila cheia!\n\n");
						break;
					}
					else
					{
						printf("\nEscreva a placa do carro: ");
						scanf(" %s", placa);
						for(contador = 0; contador <= 0; contador++)
						{
							enqueue(&filaGuarusCampos,placa[contador]);
						}
						contador = 0;
					}
					printf("\n\ngostaria de adicionar mais um carro? Escreva 0 para nao e 1 para sim: ");
					scanf("%d",&continuar);
				}
				break;
			}
			
			case 3:
			{
				continuar = 1;
				while(continuar == 1)
				{
					if (!qisEmpty(&filaCamposGuarus))
					{
						for(contador = 0; contador < 7; contador++)
						{
							placaSaindoDeCampos[contador] = dequeue(&filaCamposGuarus);
						}
						contador = 0;
						placaSaindoDeCampos[7] = '\0';
						printf("\nCarro de placa %s atravessando sentido Campos->Guarus\n", placaSaindoDeCampos);
					}
					else
					{
						printf("\nNao ha carros para atravessar no sentido Campos->Guarus\n");
					}
					if (!qisEmpty(&filaGuarusCampos))
					{
						for(contador = 0; contador < 7; contador++)
						{
							placaSaindoDeGuarus[contador] = dequeue(&filaGuarusCampos);
						}
						contador = 0;
						placaSaindoDeCampos[7] = '\0';
						printf("\nCarro de placa %s atravessando sentido Guarus->Campos\n", placaSaindoDeGuarus);
					}
					else
					{
						printf("\nNao ha carros para atravessar no sentido Guarus->Campos\n");
					}
					printf("\n\ngostaria de permitir mais uma travessia? Escreva 0 para nao e 1 para sim: ");
					scanf("%d",&continuar);
				}
			}
			
			case 4:
			{
				return 0;
				break;
			}
			
			default:
			{
				printf("Opcao Invalida!");
			}
			
		}
	}
	return 0;
}
