/**
 * @file Corrida.cpp
 * @brief implementacao da classe Corrida
 * @author Alexandre
 * @since 02/06/2018
 * @date 06/06/2018
 */

#include <iostream>
#include "Corrida.h"

/** @details cria uma Corrida com o ponteiro para pista sendo nulo.
 */
Corrida::Corrida()
{
	this->Track = NULL;
}

/** @details construtor da clase Corrida.
 *  @param trajeto pista da simulacao.
 *  @param colecao vetor de sapos.
 */
Corrida::Corrida(Pista* trajeto, std::vector<Sapo*>* colecao)
{
	this->Track = trajeto;
	for (unsigned i = 0; i < colecao->size(); i++)
	{
		Participantes.push_back(colecao->at(i));
	}
}

/** @details define a pista para a simulacao.
 *  @param track ponteiro para Pista.
 *  @return sem retorno.
 */
void Corrida::setTrack(Pista* track)
{
	this->Track = track;
}

/** @details acessa e retorna o ponteiro para pista.
 *  @return ponteiro para pista.
 */
Pista* Corrida::getTrack()
{
	return this->Track;
}

/** @details insere um sapo no vetor de sapos.
 *  @param participante ponteiro para Sapo.
 *  @return sem retorno.
 */
void Corrida::setParticipantes(Sapo* participante)
{
	Participantes.push_back(participante);
}

/** @details acessa e retorna o vetor de sapos.
 *  @return vetor de ponteiro para Sapo.
 */
std::vector<Sapo*> Corrida::getParticipantes()
{
	return Participantes;
}

/** @details percorre o vetor de sapos e exibe o nome de ada um deles.
 *  @return sem retorno.
 */
void Corrida::showParticipantes()
{
	std::cout << "Participantes:";
	for (unsigned i = 0; i < Participantes.size(); i++)
		std::cout << ' ' << Participantes[i]->getNome();
	std::cout << '\n';
}

/** @details limpa o vetor de sapos.
 */
Corrida::~Corrida()
{
	Participantes.clear();
}

