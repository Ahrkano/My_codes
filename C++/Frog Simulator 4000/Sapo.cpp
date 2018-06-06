/*
 * Sapo.cpp
 *
 *  Created on: 2 de jun de 2018
 *      Author: Alexandre
 */
#include <string>
#include "funcoes.h"
#include "Sapo.h"

int Sapo::distancia_total;

void Sapo::pular()
{
	int pulo = variacao(1,10);

	setQuantidade_de_pulos(getQuantidade_de_pulos()+1);
	setDistancia_percorrida(getDistancia_percorrida()+pulo);

	if(distancia_total < getDistancia_percorrida())
		distancia_total = getDistancia_percorrida();

}

Sapo::Sapo()
{
	this->identificador = -1;
	this->distancia_percorrida = 0;
	this->quantidade_de_pulos = 0;
	this->quantidade_de_provas_disputadas = 0;
	this->vitorias = 0;
	this->empates = 0;
	this->quantidade_de_pulos_total = 0;
	this->nome = "vazio";
}

Sapo::Sapo(int id, int provas, int vit, int emp, int pulos, const std::string& Nome)
{
	this->identificador = id;
	this->distancia_percorrida = 0;
	this->quantidade_de_pulos = 0;
	this->quantidade_de_provas_disputadas = provas;
	this->vitorias = vit;
	this->empates = emp;
	this->quantidade_de_pulos_total = pulos;
	this->nome = Nome;
}

void Sapo::setIdentificador(int id)
{
	this->identificador = id;
}
const int Sapo::getIdentificador()
{
	return identificador;
}

void Sapo::setDistancia_percorrida(int dist)
{
	this->distancia_percorrida = dist;
}

const int Sapo::getDistancia_percorrida()
{
	return distancia_percorrida;
}

void Sapo::setQuantidade_de_pulos(int qtd)
{
	this->quantidade_de_pulos = qtd;
}

const int Sapo::getQuantidade_de_pulos()
{
	return quantidade_de_pulos;
}

void Sapo::setQuantidade_de_provas_disputadas(int qtd)
{
	this->quantidade_de_provas_disputadas = qtd;
}

const int Sapo::getQuantidade_de_provas_disputadas()
{
	return quantidade_de_provas_disputadas;
}

void Sapo::setVitorias(int vit)
{
	this->vitorias = vit;
}

const int Sapo::getVitorias()
{
	return vitorias;
}

void Sapo::setEmpates(int emp)
{
	this->empates = emp;
}

const int Sapo::getEmpates()
{
	return empates;
}

void Sapo::setQuantidade_de_pulos_total(int qtd)
{
	this->quantidade_de_pulos_total = qtd;
}

const int Sapo::getQuantidade_de_pulos_total()
{
	return quantidade_de_pulos_total;
}

void Sapo::setNome(const std::string& palavra)
{
	this->nome = palavra;
}

const std::string& Sapo::getNome()
{
	return nome;
}

Sapo::~Sapo()
{

}

