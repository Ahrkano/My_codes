/*
 * funcoes.cpp
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */
#include "funcoes.h"
#include "Sapo.h"

#include <iostream>
#include <stdlib.h>


int variacao(int min, int max)
{
	return rand() % max + min;
}

bool chegada(Sapo participante, int meta)
{
	if(participante.get_distancia() >= meta)
		return true;
	return false;
}

void estatistica(Sapo participante)
{
	std::cout<<"\nAO VENCEDOR OS ESPOLIOS";
	std::cout<<"\nID: "<<participante.get_id();
	std::cout<<"\nDISTANCIA PERCORRIDA: "<<participante.get_distancia()<<" M";
	std::cout<<"\nTOTAL DE PULOS: "<<participante.get_pulos();
}

void apresentacao()
{
	std::cout<<"\nBEM VINDO AO FROGRACE JUMP SIMULATOR 3000!";
}
