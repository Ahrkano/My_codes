/*
 * leitura.h
 *
 *  Created on: 4 de jun de 2018
 *      Author: Alexandre
 */

#ifndef SRC_LEITURA_H_
#define SRC_LEITURA_H_

#include <vector>
#include "Sapo.h"
#include "Pista.h"

bool ler_arquivo_competidores(std::vector<Sapo*>* conjunto );

bool salvar_arquivo_competidores(Sapo* novo);

bool ler_arquivo_trajetos(std::vector<Pista*>* conjunto);

bool salvar_arquivo_trajetos(Pista* conjunto);

bool ja_existe(int num, std::vector<Sapo*>* conjunto);
bool ja_existe(int num, std::vector<Pista*>* conjunto);


#endif /* SRC_LEITURA_H_ */
