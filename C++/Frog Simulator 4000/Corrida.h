/*
 * Corrida.h
 *
 *  Created on: 2 de jun de 2018
 *      Author: Alexandre
 */

#ifndef SRC_CORRIDA_H_
#define SRC_CORRIDA_H_

#include <string>
#include <vector>
#include "Pista.h"
#include "Sapo.h"

class Corrida
{
private:
	Pista* Track;
	std::vector<Sapo*> Participantes;

public:
	Corrida();
	Corrida(Pista* trajeto, std::vector<Sapo*>* colecao);
	virtual ~Corrida();

	void setTrack(Pista* track);
	Pista* getTrack();

	void setParticipantes(Sapo* participantes);
	std::vector<Sapo*> getParticipantes();

	void showParticipantes();


	void ver_estatisticas();



};

#endif /* SRC_CORRIDA_H_ */
