/**
*@file dado.h
*@brief definicao da classe Dado
*@author Alexandre
*@since 13/03/2018
*@date 13/03/2018
*@sa https://github.com/Ahrkano/My_codes/tree/master/C%2B%2B/Dice
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dado.h"

/** @details recebe um vetor de Dado, um tamanho e a partir dai
 *  executa um laco em que a cada iteracao cria um Dado na posicao
 *  atual do vetor
 *  @param colecao vetor de Dado
 *  @param qtd inteiro que representa o tamanho do vetor
 */
void cria_dado(Dado* colecao, int qtd)
{
	int i = 0;

	for(i = 0; i < qtd; i++ )
	{
		colecao[i] = Dado();
	}

}

/** @details funcao que simula um lancamento de um dado atraves da funcao rand()
 *  defininfo ao final o atributo lado da variavel My_dado
 *  @param My_dado ponteiro do tipo Dado *
 */
void lanca_dado(Dado* My_dado)
{
	 My_dado->set_lado( rand() % (My_dado->get_faces()) + 1);
}

/** @details funcao principal do programa
 *  Dada uma certa quantidade de dados e de jogadas
 *  o programa simula o lancamento de dados e ao final
 *  exibe a pontuacao total
 */
int main()
{
	srand (time(NULL));

	int i, j, sum, qtd_dados, qtd_jogos = 0;

	std::cout<<"Quantas jogadas?: "<<std::endl;
	std::cin>>qtd_jogos;
	std::cout<<"Quantas dados?: "<<std::endl;
	std::cin>>qtd_dados;
	
	Dado colecao[qtd_dados];


	for(i = 0; i < qtd_jogos; i++)
	{
		std::cout<<"Rodada "<<i+1<<": "<<std::endl;
				
		for(j = 0; j < qtd_dados; j++)
		{
			cria_dado(colecao,qtd_dados);
			lanca_dado(&colecao[j]);
			std::cout<<"  dado "<<j+1<<": "<<colecao[j].get_lado()<<""<<std::endl;
			sum += sum + colecao[j].get_lado();
		}
		
	}

	std::cout<<"Pontuacao total: "<<sum<<std::endl;

	return 0;
}


