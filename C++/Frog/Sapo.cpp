/*
 * Sapo.cpp
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */
#include "funcoes.h"
#include "Sapo.h"



int Sapo::distancia_total;

void Sapo::pular()
{
	int pulo = variacao(1,10);

	set_pulos(get_pulos()+1);
	set_distancia(get_distancia()+pulo);

	if(distancia_total < get_distancia())
		distancia_total = get_distancia();

}

Sapo::Sapo()
{
	identificador = -1;
	distancia_percorrida = 0;
	quantidade_de_pulos = 0;
}

Sapo::Sapo(int id, int dis, int qtd)
{
	identificador = id;
	distancia_percorrida = dis;
	quantidade_de_pulos = qtd;
}

Sapo::~Sapo() {
	// NOTHING NOW
}

void Sapo::set_id(int id)
{
	identificador = id;
}
void Sapo::set_distancia(int dist)
{
	distancia_percorrida = dist;
}
void Sapo::set_pulos(int qtd)
{
	quantidade_de_pulos = qtd;
}

const int Sapo::get_id()
{
	return identificador;
}

const int Sapo::get_distancia()
{
	return distancia_percorrida;
}

const int Sapo::get_pulos()
{
	return quantidade_de_pulos;
}
