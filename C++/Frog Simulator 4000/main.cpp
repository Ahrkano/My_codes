/*
 * main.cpp
 *
 *  Created on: 13 de jun de 2018
 *      Author: Alexandre
 */
#include <iostream>
#include <fstream>
#include <string>

#include "Sapo.h"
#include "Pista.h"
#include "Corrida.h"
#include "leitura.h"
#include "funcoes.h"

using namespace std;

int main ()
{
	vector<Sapo*> conjunto;
	vector<Pista*> tracks;
	Corrida* Silvestre;

	Pista* Atual = NULL;
	Sapo* novo_sapo = NULL;
	vector<Sapo*> ranking;

	if(!ler_arquivo_competidores(&conjunto))
		cerr<<"Falha ao importar competidores"<<endl;

	if(!ler_arquivo_pistas(&tracks))
		cerr<<"Falha ao importar pistas"<<endl;

	int opcao;
	bool simulacao = true;

	while(simulacao)
	{
		controle_de_menu(&opcao);

		switch(opcao)
		{
			case 1:	novo_sapo = criar_sapo(&conjunto);
					conjunto.push_back(novo_sapo);
					salvar_arquivo_competidores(novo_sapo);
					break;
			case 2:	Silvestre->getParticipantes().clear();
					Silvestre->setTrack(NULL);
					liberar_espaco(&ranking);
					Silvestre = new Corrida(Atual, &conjunto);
					break;
			case 3:	ler_estatisticas_sapos();
					break;
			case 4: ler_estatisticas_corridas();
					break;
			case 5: if(!escolher_pista(Atual, &tracks))
					{
						std::cerr<<"Falha na escolha da pista"<<std::endl;
						break;
					}
					ver_participantes(&conjunto);
					pei();
					corre_negada(&conjunto, Atual->getTamanho(), &ranking);
					mostrar_ranking(&ranking);
					jogar_novamente(&simulacao);
					break;
			default:
					simulacao = false;
					break;
		}
	}

	liberar_espaco(&conjunto);
	liberar_espaco(&tracks);
	liberar_espaco(&ranking);
	Atual = NULL;
	novo_sapo = NULL;
	delete novo_sapo;

	std::cout<<"Aperte Enter para finalizar"<<std::endl;
	std::cin.get();

  return 0;
}



