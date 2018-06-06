/*
 * Sapo.h
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */

#ifndef SRC_SAPO_H_
#define SRC_SAPO_H_

#include <string>

class Sapo {
private:
	int identificador;
	int distancia_percorrida;
	int quantidade_de_pulos;
	int quantidade_de_provas_disputadas;
	int vitorias;
	int empates;
	int quantidade_de_pulos_total;
	std::string nome;

public:
	static int distancia_total;

	Sapo();
	Sapo(int id, int provas, int vit, int emp, int pulos, const std::string& Nome);
	~Sapo();
	void pular();

	void setIdentificador(int id);
	const int getIdentificador();

	void setDistancia_percorrida(int dist);
	const int getDistancia_percorrida();

	void setQuantidade_de_pulos(int qtd);
	const int getQuantidade_de_pulos();

	void setQuantidade_de_provas_disputadas(int qtd);
	const int getQuantidade_de_provas_disputadas();

	void setVitorias(int vit);
	const int getVitorias();

	void setEmpates(int emp);
	const int getEmpates();

	void setQuantidade_de_pulos_total(int qtd);
	const int getQuantidade_de_pulos_total();

	void setNome(const std::string& palavra);
	const std::string& getNome();

};

#endif /* SRC_SAPO_H_ */
