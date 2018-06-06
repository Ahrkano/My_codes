/*
 * Corrida.cpp
 *
 *  Created on: 2 de jun de 2018
 *      Author: Alexandre
 */

#include <iostream>
#include "Corrida.h"

Corrida::Corrida()
{
	this->Track = NULL;
}

Corrida::Corrida(Pista* trajeto, std::vector<Sapo*>* colecao)
{
	this->Track = trajeto;
	for (unsigned i = 0; i < colecao->size(); i++)
	{
		Participantes.push_back(colecao->at(i));
	}
}

void Corrida::setTrack(Pista* track)
{
	this->Track = track;
}

Pista* Corrida::getTrack()
{
	return this->Track;
}

void Corrida::setParticipantes(Sapo* participantes)
{
	Participantes.push_back(participantes);
}

void Corrida::showParticipantes()
{
	std::cout << "Participantes:";
	for (unsigned i = 0; i < Participantes.size(); i++)
		std::cout << ' ' << Participantes[i]->getNome();
	std::cout << '\n';
}

std::vector<Sapo*> Corrida::getParticipantes()
{
	return Participantes;
}

void Corrida::ver_estatisticas()
{

}




Corrida::~Corrida()
{
	Participantes.clear();
}

