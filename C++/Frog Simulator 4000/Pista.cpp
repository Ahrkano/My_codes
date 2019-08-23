/**
 * @file Pista.cpp
 * @brief implementacao da classe Pista
 * @author Alexandre
 * @since 29/05/2018
 * @date 06/06/2018
 */

#include "Pista.h"

/** @details cria uma Pista que por padrao tem id igual a zero, tamanho igual quinhentos
 *  e nome de "Pista de Teste".
 */
Pista::Pista()
{
	this->nome = "Pista de Teste";
	this->tamanho = 500;
	this->id = 0;
}

/** @details construtor da clase Pista.
 *  @param Nome indica o nome do pista.
 *  @param tam indica o tamanho da pista
 *  @param _id indica a numeracao do pista.
 */
Pista::Pista(std::string Nome, int tam, int _id)
{
	this->nome = Nome;
	this->tamanho = tam;
	this->id = _id;
}

/** @details acessa o e retorna o nome da pista.
 *  @return string.
 */
const std::string& Pista::getNome() const
{
	return this->nome;
}

/** @details define o nome da pista.
 *  @param nome nome da pista.
 *  @return sem retorno.
 */
void Pista::setNome(const std::string& nome)
{
	this->nome = nome;
}

/** @details acessa e retorna o tamanho da pista.
 *  @return inteiro.
 */
int Pista::getTamanho() const
{
	return tamanho;
}

/** @details define o tamanho da pista.
 *  @param tamanho tamanho da pista.
 *  @return sem retorno.
 */
void Pista::setTamanho(int tamanho)
{
	this->tamanho = tamanho;

}

/** @details acessa e retorna o id da pista.
 *  @return inteiro.
 */
const int Pista::getId() const
{
	return id;
}

/** @details define o id da pista.
 *  @param _id id da pista.
 *  @return sem retorno.
 */
void Pista::setId(int _id)
{
	this->id = _id;
}

/** @details destrutor da classe Pista.
 */
Pista::~Pista()
{

}

