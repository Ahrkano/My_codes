/*
 * Sapo.h
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */

#ifndef SRC_SAPO_H_
#define SRC_SAPO_H_

class Sapo {
private:
	int identificador;
	int distancia_percorrida;
	int quantidade_de_pulos;

public:
	static int distancia_total;

	void set_id(int id);
	void set_distancia(int dist);
	void set_pulos(int qtd);

	const int get_id();
	const int get_distancia();
	const int get_pulos();

	void pular();

	Sapo();
	Sapo(int id, int dis, int qtd);
	~Sapo();
};

#endif /* SRC_SAPO_H_ */
