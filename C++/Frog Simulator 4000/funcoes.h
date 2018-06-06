/*
 * funcoes.h
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */

#ifndef SRC_FUNCOES_H_
#define SRC_FUNCOES_H_

#include <vector>
#include "Sapo.h"
#include "Corrida.h"

int variacao(int min, int max);

bool chegada(Sapo participante, int meta);

void estatistica(std::vector<Sapo*>* Participantes);

void apresentacao();

void menu(int *op);

void menu(char *op, bool *si);

bool corrida_em_andamento(Corrida* corr);

void criar_sapo(Sapo* add);

void criar_pista(Pista* add);

void encerrar_corrida(Corrida* corr);

#endif /* SRC_FUNCOES_H_ */
