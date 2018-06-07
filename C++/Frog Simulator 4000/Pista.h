/**
 * @file Pista.h
 * @brief definicao da classe Pista
 * @author Alexandre
 * @since 29/05/2018
 * @date 06/06/2018
 */

#ifndef SRC_PISTA_H_
#define SRC_PISTA_H_

#include <string>

/**
 * Classe que define um Sapo.
 */
class Pista
{
private:
	std::string nome;		///< Nome da pista.
	int tamanho;			///< Tamanho da pista.
	int id;					///< Id da pista.

public:

    /** @brief construtor da clase Pista.
     */
	Pista();

    /** @brief construtor da clase Pista.
     *  @param Nome indica o nome do pista.
     *  @param tam indica o tamanho da pista
     *  @param _id indica a numeracao do pista.
     */
	Pista(std::string Nome, int tam, int _id);

    /** @brief destrutor da classe Pista.
     */
	~Pista();

    /** @brief acessa o nome da pista.
     *  @return string.
     */
	const std::string& getNome() const;

    /** @brief define o nome da pista.
     *  @param nome nome da pista.
     *  @return sem retorno.
     */
	void setNome(const std::string& nome);

    /** @brief acessa o tamanho da pista.
     *  @return inteiro.
     */
	int getTamanho() const;

    /** @brief define o tamanho da pista.
     *  @param tamanho tamanho da pista.
     *  @return sem retorno.
     */
	void setTamanho(int tamanho);

    /** @brief acessa o id da pista.
     *  @return inteiro.
     */
	const int getId() const;

    /** @brief define o id da pista.
     *  @param _id id da pista.
     *  @return sem retorno.
     */
	void setId(int _id);
};

#endif /* SRC_PISTA_H_ */
