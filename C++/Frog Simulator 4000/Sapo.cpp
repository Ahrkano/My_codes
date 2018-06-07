/**
 * @file Sapo.cpp
 * @brief implementacao da classe Sapo
 * @author Alexandre
 * @since 29/05/2018
 * @date 06/06/2018
 */
#include <iostream>
#include <string>
#include "funcoes.h"
#include "Sapo.h"

int Sapo::distancia_total;

/** @details funcao que simula o pulo do sapo.
 *  faz uso da funcao variacao que gera um numero aleatorio e depois incrementa a
 *  tanto a quantidade de pulos durante uma corrida quanto a quantidade total de pulos
 *  dados pelo sapo ao longo de todas as suas corridas.
 *  A cada execucao eh exibida uma informacao acerca da distancia pulada.
 */
void Sapo::pular()
{
	int pulo = variacao(1,10);

	setQuantidade_de_pulos(getQuantidade_de_pulos()+1);
	setDistancia_percorrida(getDistancia_percorrida()+pulo);
	setQuantidade_de_pulos_total(getQuantidade_de_pulos_total()+1);

	std::cout<<this->getNome()<<std::endl;
	std::cout<<this->getIdentificador()<<std::endl;
	std::cout<<"pulou: "<<pulo<<" unidades"<<std::endl;

	if(distancia_total < getDistancia_percorrida())
		distancia_total = getDistancia_percorrida();

}

/** @details cria um Sapo que por padrao tem id igual -1 e o resto inicia com zero.
 * 	o nome do sapo eh vazio.
 */
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

/** @details cria um Sapo com os atributos especificados pelos parametros abaixo.
 *  @param id indica a numeracao do sapo.
 *  @param provas indica a quantidade de provas disputadas pelo sapo.
 *  @param vit indica a quantidade de vitorias do sapo.
 *  @param emp indica a quantidade de empates do sapo.
 *  @param pulos indica a quantidade de pulos do sapo.
 *  @param Nome indica o nome do sapo.
 */
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

/** @details identificador recebe o valor id.
 *  @param id indica a numeracao do sapo.
 */
void Sapo::setIdentificador(int id)
{
	this->identificador = id;
}

/** @details retorna a numeracao do sapo.
 *  @return inteiro.
 */
const int Sapo::getIdentificador()
{
	return identificador;
}

/** @details distancia_percorrida recebe o valor dist.
 *  @param dist indica a distancia percorrida pelo sapo.
 */
void Sapo::setDistancia_percorrida(int dist)
{
	this->distancia_percorrida = dist;
}

/** @details retorna a distancia percorrida pelo sapo.
 *  @return inteiro.
 */
const int Sapo::getDistancia_percorrida()
{
	return distancia_percorrida;
}

/** @details quantidade_de_pulos recebe o valor qtd.
 *  @param qtd indica a quantidade de pulos do sapo.
 */
void Sapo::setQuantidade_de_pulos(int qtd)
{
	this->quantidade_de_pulos = qtd;
}

/** @details retorna a quantidade de pulos dados pelo sapo.
 *  @return inteiro.
 */
const int Sapo::getQuantidade_de_pulos()
{
	return quantidade_de_pulos;
}


/** @details quantidade_de_provas_disputadas recebe o valor qtd.
 *  @param qtd indica a quantidade de provas disputadas disputadas pelo sapo.
 */
void Sapo::setQuantidade_de_provas_disputadas(int qtd)
{
	this->quantidade_de_provas_disputadas = qtd;
}

/** @details retorna a quantidade de provas disputadas disputadas pelo sapo.
 *  @return inteiro.
 */
const int Sapo::getQuantidade_de_provas_disputadas()
{
	return quantidade_de_provas_disputadas;
}

/** @details vitorias recebe o valor vit.
 *  @param vit indica a quantidade de vitorias do sapo.
 */
void Sapo::setVitorias(int vit)
{
	this->vitorias = vit;
}

/** @details retorna a quantidade de vitorias do sapo.
 *  @return inteiro.
 */
const int Sapo::getVitorias()
{
	return vitorias;
}

/** @details empates recebe o valor emp.
 *  @param emp indica a quantidade de empates do sapo.
 */
void Sapo::setEmpates(int emp)
{
	this->empates = emp;
}

/** @details retorna a quantidade de empates do sapo.
 *  @return inteiro.
 */
const int Sapo::getEmpates()
{
	return empates;
}

/** @details quantidade_de_pulos_total recebe o valor qtd.
 *  @param qtd indica a quantidade de pulos que o sapo deu em todas as corridas.
 */
void Sapo::setQuantidade_de_pulos_total(int qtd)
{
	this->quantidade_de_pulos_total = qtd;
}

/** @details retorna a quantidade de pulos que o sapo deu em todas as corridas.
 *  @return inteiro.
 */
const int Sapo::getQuantidade_de_pulos_total()
{
	return quantidade_de_pulos_total;
}

/** @details nome recebe o valor palavra.
 *  @param nome indica nome do sapo.
 */
void Sapo::setNome(const std::string& palavra)
{
	this->nome = palavra;
}

/** @details retorna o nome do sapo.
 *  @return string.
 */
const std::string& Sapo::getNome()
{
	return nome;
}

/** @details destrutor da classe Sapo.
 */
Sapo::~Sapo()
{

}

