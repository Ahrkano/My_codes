/**
 * @file leitura.h
 * @brief definicao de algumas funcoes para leitura.
 * @author Alexandre
 * @since 04/06/2018
 * @date 06/06/2018
 */

#ifndef SRC_LEITURA_H_
#define SRC_LEITURA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Sapo.h"
#include "Pista.h"
#include "Corrida.h"
#include "funcoes.h"


bool ler_arquivo_competidores(std::vector<Sapo*>* conjunto );

bool salvar_arquivo_competidores(Sapo* novo);

bool ler_arquivo_pistas(std::vector<Pista*>* conjunto );

bool salvar_corrida(Corrida* evento, Sapo* vencedor);

bool ler_estatisticas_corridas();

bool ler_estatisticas_sapos();

bool atualizar_sapos(std::vector<Sapo*>* conjunto);

#endif /* SRC_LEITURA_H_ */
