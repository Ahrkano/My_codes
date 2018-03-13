/*
 * main.cpp
 *
 *  Created on: 13 de mar de 2018
 *      Author: Alexandre
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dado.h"

void lanca_dado(Dado* My_dado)
{
	 My_dado->set_lado( rand() % 6 + 1);
}

int main()
{
	srand (time(NULL));

	int i, qtd_jogos = 0;

	Dado* meu_dado = new Dado;

	std::cout<<"Quantas jogadas?: "<<std::endl;
	std::cin>>qtd_jogos;

	for(i = 0; i < qtd_jogos; i++)
	{
		lanca_dado(meu_dado);
		std::cout<<"rodada "<<i+1<<": "<<meu_dado->get_lado()<<std::endl;

	}

	delete meu_dado;
	return 0;
}


