/**
 * @file Sapo.h
 * @brief definicao da classe Sapo
 * @author Alexandre
 * @since 29/05/2018
 * @date 06/06/2018
 */

#ifndef SRC_SAPO_H_
#define SRC_SAPO_H_

#include <string>

/**
 * Classe que define um Sapo.
 */
class Sapo {
private:
	int identificador;						///< Id do sapo.
	int distancia_percorrida;				///< Distancia percorrida.
	int quantidade_de_pulos;				///< A quantidade de pulos dada em uma corrida.
	int quantidade_de_provas_disputadas;	///< A quantidade de provas disputadas.
	int vitorias;							///< A Quantidade de vitorias.
	int empates;							///< A Quantidade de empates.
	int quantidade_de_pulos_total;			///< A quantidade de pulos dada em todas as corridas.
	std::string nome;						///< Nome do Sapo.
	bool chegou;

public:
	static int distancia_total;				///< Indica a distancia percorrida pelo primeiro sapo durante a corrida.

    /** @brief construtor da clase Sapo.
     */
	Sapo();

    /** @brief construtor da clase Sapo.
     *  @param id indica a numeracao do sapo.
     *  @param provas indica a quantidade de provas disputadas pelo sapo.
     *  @param vit indica a quantidade de vitorias do sapo.
     *  @param emp indica a quantidade de empates do sapo.
     *  @param pulos indica a quantidade de pulos do sapo.
     *  @param Nome indica o nome do sapo.
     */
	Sapo(int id, int provas, int vit, int emp, int pulos, const std::string& Nome);

    /** @brief destrutor da classe Sapo.
     */
	~Sapo();

    /** @brief simula o pulo do sapo, incrementando assim sua distancia percorrida.
     *  @param sem parametro.
     *  @return sem retorno.
     */
	void pular();

    /** @brief define a numeracao do sapo.
     *  @param id numero do sapo.
     *  @return sem retorno.
     */
	void setIdentificador(int id);

    /** @brief acessa a numeracao do sapo.
     *  @return inteiro.
     */
	const int getIdentificador();

    /** @brief define a distancia percorrida.
     *  @param dist distancia percorrida pelo sapo.
     *  @return sem retorno.
     */
	void setDistancia_percorrida(int dist);

    /** @brief acessa a distancia percorrida pelo sapo.
     *  @return inteiro.
     */
	const int getDistancia_percorrida();

    /** @brief define a quantidade de pulos do sapo.
     *  @param qtd quantidade de pulos dados pelo sapo.
     *  @return sem retorno.
     */
	void setQuantidade_de_pulos(int qtd);

    /** @brief acessa a quantidade de pulos do sapo.
     *  @return inteiro.
     */
	const int getQuantidade_de_pulos();

    /** @brief define a quantidade de provas disputadas pelo sapo.
     *  @param qtd quantidade de provas.
     *  @return sem retorno.
     */
	void setQuantidade_de_provas_disputadas(int qtd);

    /** @brief acessa a quantidade de provas disputadas pelo sapo.
     *  @return inteiro.
     */
	const int getQuantidade_de_provas_disputadas();

    /** @brief define a quantidade de vitorias do sapo.
     *  @param vit quantidade de vitorias.
     *  @return sem retorno.
     */
	void setVitorias(int vit);

    /** @brief acessa a quantidade de vitorias do sapo.
     *  @return inteiro.
     */
	const int getVitorias();

    /** @brief define a quantidade de empates do sapo.
     *  @param emp quantidade de empates.
     *  @return sem retorno.
     */
	void setEmpates(int emp);

    /** @brief acessa a quantidade de empates do sapo.
     *  @return inteiro.
     */
	const int getEmpates();

    /** @brief define a quantidade de pulos do sapo em todas as suas corridas.
     *  @param qtd quantidade de pulos dados pelo sapo.
     *  @return sem retorno.
     */
	void setQuantidade_de_pulos_total(int qtd);

    /** @brief acessa a quantidade de pulos do sapo em todas as suas corridas.
     *  @return inteiro.
     */
	const int getQuantidade_de_pulos_total();

    /** @brief define o nome do sapo.
     *  @param palavra nome do sapo.
     *  @return sem retorno.
     */
	void setNome(const std::string& palavra);

    /** @brief acessa  o nome do sapo.
     *  @return string.
     */
	const std::string& getNome();

	void setChegou(bool valor);

	bool getChegou();

};

#endif /* SRC_SAPO_H_ */
