/*
 * Pista.cpp
 *
 *  Created on: 2 de jun de 2018
 *      Author: Alexandre
 */

#include "Pista.h"

Pista::Pista()
{
	this->nome = "Pista de Teste";
	this->tamanho = 500;
	this->id = 0;
}

Pista::Pista(std::string Nome, int tam, int _id)
{
	this->nome = Nome;
	this->tamanho = tam;
	this->id = _id;
}

const std::string& Pista::getNome() const
{
	return this->nome;
}

void Pista::setNome(const std::string& nome)
{
	this->nome = nome;
}

int Pista::getTamanho() const
{
	return tamanho;
}

void Pista::setTamanho(int tamanho) {
	this->tamanho = tamanho;

}

const int Pista::getId() const
{
	return id;
}
void Pista::setId(int _id)
{
	this->id = _id;
}

Pista::~Pista()
{

}

