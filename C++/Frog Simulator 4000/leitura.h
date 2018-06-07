/**
 * @file leitura.h
 * @brief definicao de algumas funcoes para leitura.
 * @author Alexandre
 * @since 04/06/2018
 * @date 06/06/2018
 */

#ifndef SRC_LEITURA_H_
#define SRC_LEITURA_H_

#include <vector>
#include "Sapo.h"
#include "Pista.h"
#include "Corrida.h"

/** @brief dado um inteiro e um vetor de Sapo checa se existe um sapo no vetor
 *  com o id igual ao inteiro passado.
 *  @param num possivel id de Sapo.
 *  @param conjunto ponteiro para vetor de Sapo.
 *  @return booleano.
 */
bool ja_existe(int num, std::vector<Sapo*>* conjunto);

/** @brief dado um inteiro e um vetor de Pista checa se existe uma pista no vetor
 *  com o id igual ao inteiro passado.
 *  @param num possivel id de Pista.
 *  @param conjunto ponteiro para vetor de Pista.
 *  @return booleano.
 */
bool ja_existe(int num, std::vector<Pista*>* conjunto);

/** @brief le um arquivo e armazena os dados no vetor.
 *  @param conjunto ponteiro para vetor de Sapo.
 *  @return booleano.
 */
bool ler_arquivo_competidores(std::vector<Sapo*>* conjunto );

/** @brief escreve num arquivo os dados do sapo.
 *  @param novo ponteiro para Sapo.
 *  @return booleano.
 */
bool salvar_arquivo_competidores(Sapo* novo);

/** @brief le um arquivo e armazena os dados no vetor.
 *  @param conjunto ponteiro para vetor de Pista.
 *  @return booleano.
 */
bool ler_arquivo_trajetos(std::vector<Pista*>* conjunto);

/** @brief escreve num arquivo os dados da corrida.
 *  @param corr ponteiro para Corrida.
 *  @return booleano.
 */
bool salvar_arquivo_corrida(Corrida* corr);

/** @brief escreve num arquivo as estatisicas da corrida.
 *  @param corr ponteiro para Corrida.
 *  @param conjunto ponteiro para vetor de Sapo.
 *  @return booleano.
 */
bool salvar_arquivo_stats(std::vector<Sapo*>* conjunto, Corrida* corr);

/** @brief le um arquivo exibe os dados na tela.
 *  @param sem parametro.
 *  @return sem retorno.
 */
void mostrar_stats();

#endif /* SRC_LEITURA_H_ */
