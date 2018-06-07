/**
*@file main.cpp
*@brief programa principal
*@author Alexandre
*@since 30/05/2018
*@date 06/06/2018
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Sapo.h"
#include "funcoes.h"
#include "Pista.h"
#include "leitura.h"

/** @details funcao principal do programa que simula uma corrida de sapos.
 *  As informacoes acerca dos sapos sao obtidas a partir do arquivo "sapos.txt"
 *  e armazenadas no vetor de sapos 'Competidores'.
 *  As informacoes acerca das pistas sao obtidas a partir do arquivo "pistas.txt"
 *  e armazenadas no vetor de pistas 'Pistas_disponiveis'.
 *  Dentro de um laco principal ocorre o gerenciamento da corrida, onde o usuario
 *  pode criar novos sapos, criar corridas, ver as estatisticas dos sapos, ver as
 *  estatisticas das corridas e iniciar a corrida.
 *  Antes de terminar o processo de execucao da corida, eh gerado e exibido um
 *  ranking da corrida com todos os sapos em suas respectivas posicoes de chegada.
 *  Quando o processo de execucao da corrida acaba o usuario eh questionado se deseja jogar novamente.
 */
int main()
{
	srand (time(NULL));
	//guardar estatisticas
	std::vector<Sapo*> Ranking;
	//lista de pistas
	std::vector<Pista*>* Pistas_disponiveis = new std::vector<Pista*>();
	//lista de sapos
	std::vector<Sapo*>* Competidores = new std::vector<Sapo*>();
	//pista escolhida
	Pista* Atual = new Pista();
	//corrida
	Corrida* Silvestre = NULL;

	Sapo* sapo_aux;

	int opcao = 0;
	bool simulacao = true;
	char simu = 'x';

	if(!ler_arquivo_competidores(Competidores) || !ler_arquivo_trajetos(Pistas_disponiveis))
	{
		std::cerr<<"Falha na leitura dos arquivos"<<std::endl;
		return -1;
	}

	apresentacao();

	while(simulacao)
	{

		menu(&opcao);

		switch(opcao)
		{
			case 1:	criar_sapo(sapo_aux);
					Competidores->push_back(sapo_aux);
					salvar_arquivo_competidores(sapo_aux);
					break;
			case 2: Silvestre = new Corrida(Atual, Competidores);
					break;
			case 3	:estatistica(Competidores);
					break;
			case 4://estatistica das corridas
					break;
			case 5:	Atual = escolher_pista(Pistas_disponiveis);
					if(Atual == NULL)
						break;
					salvar_arquivo_corrida(Silvestre);
					Silvestre->showParticipantes();

					Silvestre->setTrack(Atual);
					int chegada = Atual->getTamanho();
					int ordem = 0;

					std::cout<<"Aperte Enter para comecar a corrida"<<std::endl;
					std::cin.get();

					for (unsigned i = 0; i < Silvestre->getParticipantes().size(); i++)
					{
						if(Silvestre->getParticipantes().at(i)->getDistancia_percorrida() < chegada )
							Silvestre->getParticipantes().at(i)->pular();

						if(Silvestre->getParticipantes().at(i)->getDistancia_percorrida() >=
								Silvestre->getParticipantes().at(i)->distancia_total)
						{
							for (unsigned j = 0; j < Competidores->size(); j++)
								if(Silvestre->getParticipantes().at(i)->getIdentificador() == Competidores->at(j)->getIdentificador())
									ordem++;

							if(ordem == 0)
								Competidores->push_back(Silvestre->getParticipantes().at(i));

							ordem = 0;
						}
					}

					estatistica(&Ranking);
					Ranking.clear();

					Atual = NULL;
					menu(&simu, &simulacao);

					if(!simulacao)
						encerrar_corrida(Silvestre);

					break;
		}
	}

	Pistas_disponiveis->clear();
	Competidores->clear();

	delete Pistas_disponiveis;
	delete Competidores;
	delete Silvestre;
	delete Atual;

	return 0;
}


