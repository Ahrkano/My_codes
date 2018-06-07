/**
 * @file Corrida.h
 * @brief definicao da classe Corrida
 * @author Alexandre
 * @since 02/06/2018
 * @date 06/06/2018
 */

#ifndef SRC_CORRIDA_H_
#define SRC_CORRIDA_H_

#include <string>
#include <vector>
#include "Pista.h"
#include "Sapo.h"

/**
 * Classe que define uma Corrida.
 */
class Corrida
{
private:
	Pista* Track;						///< Ponteiro para pista onde acontecera a simulacao
	std::vector<Sapo*> Participantes;	///< Vetor de Sapo com todos os sapos da simulacao

public:

    /** @brief construtor da clase Corrida.
     */
	Corrida();

    /** @brief construtor da clase Corrida.
     *  @param trajeto pista da simulacao.
     *  @param colecao vetor de sapos.
     */
	Corrida(Pista* trajeto, std::vector<Sapo*>* colecao);

    /** @brief destrutor da classe Corrida.
     */
	~Corrida();

    /** @brief define a pista a ser usada.
     *  @param track ponteiro para pista.
     *  @return sem retorno.
     */
	void setTrack(Pista* track);

    /** @brief acessa e retorna o endereco da pista.
     *  @return ponteiro para pista.
     */
	Pista* getTrack();

    /** @brief adiciona um sapo no vetor.
     *  @param participante ponteiro para Sapo.
     *  @return sem retorno.
     */
	void setParticipantes(Sapo* participante);

    /** @brief acessa e retorna o vetor de sapos.
     *  @return vetor de ponteiro para Sapo.
     */
	std::vector<Sapo*> getParticipantes();

    /** @brief exibe os sapos do vetor.
     *  @return sem retorno.
     */
	void showParticipantes();

};

#endif /* SRC_CORRIDA_H_ */
