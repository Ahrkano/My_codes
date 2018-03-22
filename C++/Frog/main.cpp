/*
 * main.cpp
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Sapo.h"
#include "funcoes.h"

#define percurso 500

int main()
{
	srand (time(NULL));


	Sapo kako = Sapo(1,0,0);
	Sapo keko = Sapo(2,0,0);
	Sapo kiko = Sapo(3,0,0);

	apresentacao();

	while(Sapo::distancia_total < percurso)
	{
		kako.pular();
		if(chegada(kako, percurso))
		{
			estatistica(kako);
			continue;
		}
		keko.pular();
		{
		if(chegada(keko, percurso))
			estatistica(keko);
			continue;
		}
		kiko.pular();
		if(chegada(kiko, percurso))
		{
			estatistica(kiko);
			continue;
		}

	}

	return 0;
}


