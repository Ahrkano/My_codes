/**
 * @file funcoes.h
 * @brief definicao de algumas funcoes auxiliares.
 * @author Alexandre
 * @since 15/03/2018
 * @date 06/06/2018
 */

#ifndef SRC_FUNCOES_H_
#define SRC_FUNCOES_H_

#include <vector>
#include "Sapo.h"
#include "Corrida.h"

/** @brief calcula o tamanho do pulo que o sapo pode dar.
 *  @param min limite inferior do pulo.
 *  @param max limite superior do pulo.
 *  @return inteiro.
 */
int variacao(int min, int max);

/** @brief checa se um sapo atingiu o final da pista.
 *  @param participante sapo a ser analisado.
 *  @param meta tamnaho da pista.
 *  @return booleano.
 */
bool chegada(Sapo participante, int meta);

/** @brief imprime as informacoes acerca de todos os sapos de um conjunto.
 *  @param Participantes vetor de sapos.
 *  @return sem retorno.
 */
void estatistica(std::vector<Sapo*>* Participantes);

/** @brief imprime mensagem de boas-vindas.
 *  @return sem retorno.
 */
void apresentacao();

/** @brief imprime o menu do programa.
 *  @param op ponteiro para inteiro que guarda a opcao do menu.
 *  @return sem retorno.
 */
void menu(int *op);

/** @brief imprime mensagem de jogar novamente.
 *  @param op ponteiro para caractere que guarda a opcao do menu.
 *  @param si ponteiro para booleano que guarda o valor verdade da resposta.
 *  @return sem retorno.
 */
void menu(char *op, bool *si);

/** @brief cria um novo sapo.
 *  @param add ponteiro para Sapo destinado a guardar o objeto.
 *  @return sem retorno.
 */
void criar_sapo(Sapo* add);

/** @brief funcao que escolhe uma pista do conjunto de pistas baseado no id da mesma.
 *  @param pis ponteiro para um vetor de ponteiros para Pista.
 *  @return Pista.
 */
Pista* escolher_pista(std::vector<Pista*>* pis);

/** @brief limpa um vetor de sapo.
 *  @param corr ponteiro para corrida.
 *  @return sem retorno.
 */
void encerrar_corrida(Corrida* corr);

#endif /* SRC_FUNCOES_H_ */
