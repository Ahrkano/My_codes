/*
 * Pista.h
 *
 *  Created on: 2 de jun de 2018
 *      Author: Alexandre
 */

#ifndef SRC_PISTA_H_
#define SRC_PISTA_H_

#include <string>

class Pista
{
private:
	std::string nome;
	int tamanho;
	int id;

public:
	Pista();
	Pista(std::string Nome, int tam, int _id);
	virtual ~Pista();

	const std::string& getNome() const;
	void setNome(const std::string& nome);
	int getTamanho() const;
	void setTamanho(int tamanho);
	const int getId() const;
	void setId(int _id);
};

#endif /* SRC_PISTA_H_ */
