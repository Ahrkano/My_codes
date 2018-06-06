/*
 * main.cpp
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Sapo.h"
#include "funcoes.h"
#include "Pista.h"
#include "leitura.h"


int main()
{
	srand (time(NULL));
	//guardar estatisticas
	std::vector<Corrida*> Competicoes;
	//lista de pistas
	std::vector<Pista*>* Pistas_disponiveis = new std::vector<Pista*>();
	//lista de sapos
	std::vector<Sapo*>* Competidores = new std::vector<Sapo*>();
	//pista escolhida
	Pista* Atual = NULL;
	//corrida
	Corrida* Silvestre = NULL;

	Sapo* sapo_aux;
	Pista* pista_aux;

	int opcao = 0;
	bool simulacao = true;
	char simu = 'x';

	if(!ler_arquivo_competidores(Competidores) || !ler_arquivo_trajetos(Pistas_disponiveis))
	{
		std::cerr<<"Falha na leitura dos arquivos"<<std::endl;
		return -1;
	}

	while(simulacao)
	{

		menu(&opcao);

		switch(opcao)
		{
			case 1:	criar_sapo(sapo_aux);
					Competidores->push_back(sapo_aux);
					salvar_arquivo_competidores(sapo_aux);
					break;
			case 2: criar_pista(pista_aux);
					Pistas_disponiveis->push_back(pista_aux);
					salvar_arquivo_trajetos(pista_aux);
					break;
			case 3	:estatistica(Competidores);
					break;
			case 4://estatistica das corridas
					break;
			case 5:	Silvestre = new Corrida(Atual, Competidores);

					while(corrida_em_andamento(Silvestre))
						for (unsigned i = 0; i < Silvestre->getParticipantes().size(); i++)
							Silvestre->getParticipantes().at(i)->pular();

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

	return 0;
}


