/**
 * @file funcoes.h
 * @brief definicao de algumas funcoes auxiliares.
 * @author Alexandre
 * @since 15/03/2018
 * @date 06/06/2018
 */

#ifndef SRC_FUNCOES_H_
#define SRC_FUNCOES_H_

#include <iostream>
#include <string>
#include <vector>
#include "Sapo.h"
#include "Pista.h"
#include "Corrida.h"

int variacao(int min, int max);

bool procurar_id(std::vector<Sapo*>* lista, int _id);

bool procurar_id(std::vector<Pista*>* lista, int _id);

Sapo* criar_sapo(std::vector<Sapo*>* lista);

Corrida* preparar_corrida(Corrida* evento, std::vector<Pista*>* tracks, std::vector<Sapo*>* part);

bool chegada(std::vector<Sapo*>* lista, int meta,std::vector<Sapo*>* ranking);

void controle_de_menu(int* opcao);

bool escolher_pista(Pista* pistao, std::vector<Pista*>* pis);

void ver_participantes(std::vector<Sapo*>* lista);

void pei();

void corre_negada(std::vector<Sapo*>* lista, int meta, std::vector<Sapo*>* ranking);

void resetar_sapos(std::vector<Sapo*>* lista);

void mostrar_ranking(std::vector<Sapo*>* ranking);

void jogar_novamente(bool* jogar);

void liberar_espaco(std::vector<Sapo*>* lista);

void liberar_espaco(std::vector<Pista*>* lista);

#endif /* SRC_FUNCOES_H_ */
