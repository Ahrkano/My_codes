/**
 * @file funcoes.cpp
 * @brief implementacao de algumas funcoes auxiliares.
 * @author Alexandre
 * @since 15/05/2018
 * @date 06/06/2018
 */

#include "funcoes.h"
#include "Sapo.h"

#include <iostream>
#include <stdlib.h>

/** @details calcula o tamanho do pulo que o sapo pode dar usando valores aleatorios de um conjunto limitado de inteiros.
 *  @param min limite inferior do pulo.
 *  @param max limite superior do pulo.
 *  @return inteiro.
 */
int variacao(int min, int max)
{
	return rand() % max + min;
}

/** @details checa se um sapo atingiu o final da pista.
 *  @param participante sapo a ser analisado.
 *  @param meta tamnaho da pista.
 *  @return booleano.
 */
bool chegada(Sapo participante, int meta)
{
	if(participante.getDistancia_percorrida() >= meta)
		return true;
	return false;
}

/** @details imprime as informacoes acerca de todos os sapos presentes no conjunto.
 *  @param Participantes vetor de sapos.
 *  @return sem retorno.
 */
void estatistica(std::vector<Sapo*>* Participantes)
{
	system("@cls||clear");

	for (unsigned i = 0; i < Participantes->size(); i++)
	{
		std::cout<<"Nome: "<<Participantes->at(i)->getNome()<<std::endl;
		std::cout<<"ID: "<<Participantes->at(i)->getIdentificador()<<std::endl;
		std::cout<<"Distancia percorrida: "<<Participantes->at(i)->getDistancia_percorrida()<<" unidades"<<std::endl;
		std::cout<<"Contagem de pulos: "<<Participantes->at(i)->getQuantidade_de_pulos_total()<<std::endl;
		std::cout<<"Vitorias: "<<Participantes->at(i)->getVitorias()<<std::endl;
		std::cout<<"Empates: "<<Participantes->at(i)->getEmpates()<<std::endl;
		std::cout<<std::endl;
	}
}

/** @details imprime mensagem de boas-vindas no comeco do programa.
 *  @return sem retorno.
 */
void apresentacao()
{
	std::cout<<"\nBEM VINDO AO FROGRACE JUMP SIMULATOR 4000!";
}

/** @details imprime o menu do programa com todas as opcoes disponiveis,
 *  em seguida eh feito o tratamento da opcao escolhida para que nao seja possivel
 *  entrar com uma opcao inexistente no menu.
 *  @param op ponteiro para inteiro que guarda a opcao do menu.
 *  @return sem retorno.
 */
void menu(int *op)
{
	int opcao = -1;

	std::cout<<"==================================="<<std::endl;
	std::cout<<"FROG SIMULATOR 4000"<<std::endl;
	std::cout<<"==================================="<<std::endl;
	std::cout<<"1 - Cria novo Sapo"<<std::endl;
	std::cout<<"2 - Criar nova Corrida"<<std::endl;
	std::cout<<"3 - Ver estatisticas do sapos"<<std::endl;
	std::cout<<"4 - Ver estatisticas das corridas"<<std::endl;
	std::cout<<"5 - Start"<<std::endl;
	std::cout<<"===================================="<<std::endl;

	while(opcao < 0 || opcao > 5)
	{
		std::cout<<"Escolha a opcao desejada:"<<std::endl;
		std::cin>>opcao;
	}

	 system("@cls||clear");

	 *op = opcao;
}

/** @details imprime mensagem de jogar novamente, em seguida eh feito
 *  o tratamento da opcao escolhida para que nao seja possivel
 *  entrar com uma opcao inexistente.
 *  @param op ponteiro para caractere que guarda a opcao do menu.
 *  @param si ponteiro para booleano que guarda o valor verdade da resposta.
 *  @return sem retorno.
 */
void menu(char *op, bool *si)
{
	while(*op != 'y' || *op != 'n')
	{
		std::cout<<"Deseja jogar novamete (y/n) ?"<<std::endl;
		std::cin>>*op;
	}

	if(*op == 'n')
		*si = false;

	system("@cls||clear");
}

/** @details cria um novo objeto sapo.
 *  @param add ponteiro para Sapo destinado a guardar o objeto.
 *  @return sem retorno.
 */
void criar_sapo(Sapo* add)
{
	add = new Sapo();
	std::string nome;
	int num;

	std::cout<<"Nome: ";
	std::getline(std::cin, nome);
	std::cout<<std::endl;
	std::cout<<"Identificacao: ";
	std::cin>>num;
	std::cout<<std::endl;

	add->setNome(nome);
	add->setIdentificador(num);
}

/** @details funcao que escolhe uma pista do conjunto de pistas baseado no id da mesma.
 *  Se o id informado nao estiver no vetor um ponteiro nulo eh retornado.
 *  @param pis ponteiro para um vetor de ponteiros para Pista.
 *  @return Pista.
 */
Pista* escolher_pista(std::vector<Pista*>* pis)
{
	int num = -1;
	std::cout<<"Entre com o numero da pista"<<std::endl;
	std::cin>>num;

	for (unsigned i = 0; i < pis->size(); i++)
	{
		if (num == pis->at(i)->getId())
			return pis->at(i);
	}
	return NULL;
}

/** @details limpa o vetor de sapo usado a corrida.
 *  @param corr ponteiro para corrida.
 *  @return sem retorno.
 */
void encerrar_corrida(Corrida* corr)
{
	for (unsigned i = 0; i < corr->getParticipantes().size(); i++)
	{
		corr->getParticipantes().pop_back();
	}
}
