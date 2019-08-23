/**
 * @file funcoes.cpp
 * @brief implementacao de algumas funcoes auxiliares.
 * @author Alexandre
 * @since 15/05/2018
 * @date 06/06/2018
 */
#include <stdlib.h>
#include "funcoes.h"

int variacao(int min, int max)
{
	return rand() % max + min;
}


bool procurar_id(std::vector<Sapo*>* lista, int _id)
{
	for(unsigned int i = 0; i < lista->size(); i++)
		if(lista->at(i)->getIdentificador() == _id)
			return true;
	return false;
}

bool procurar_id(std::vector<Pista*>* lista, int _id)
{
	for(unsigned int i = 0; i < lista->size(); i++)
		if(lista->at(i)->getId() == _id)
			return true;
	return false;
}

Sapo* criar_sapo(std::vector<Sapo*>* lista)
{
	int id;
	int provas;
	int vit;
	int emp;
	int pulos;
	std::string Nome;

	Sapo* novo = NULL;

	std::cout<<"Nome: ";
	std::cin.ignore();
	std::getline(std::cin, Nome);
	std::cout<<std::endl;
	std::cout<<"Id: ";
	std::cin>>id;
	std::cout<<std::endl;
	std::cout<<"Provas disputadas: ";
	std::cin>>provas;
	std::cout<<std::endl;
	std::cout<<"Vitorias: ";
	std::cin>>vit;
	std::cout<<std::endl;
	std::cout<<"Empates: ";
	std::cin>>emp;
	std::cout<<std::endl;
	std::cout<<"Historico de pulos: ";
	std::cin>>pulos;
	std::cout<<std::endl;

	if(!procurar_id(lista, id))
	{
		novo = new Sapo(id, provas, vit, emp, pulos, Nome);
	}
	else
	{
		std::cerr<<"ID fornecido ja existe. Competidor nao cadastrado."<<std::endl;
	}
	return novo;
}

Corrida* preparar_corrida(Corrida* evento, std::vector<Pista*>* tracks, std::vector<Sapo*>* part)
{
	int id_pista;
	std::cout<<std::endl;
	std::cout<<"Digite o id da Pista: ";
	std::cin>>id_pista;
	evento->setTrack(tracks->at(id_pista));
	evento->setParticipantes(part);
	return evento;
}

bool chegada(std::vector<Sapo*>* lista, int meta,std::vector<Sapo*>* ranking)
{
	std::vector<Sapo*> finalistas;
	std::vector<Sapo*> empatados;
	Sapo* maximo;

	for(unsigned int i = 0; i < lista->size(); i++)
	{
		if(lista->at(i)->getDistancia_percorrida() >= meta)
			finalistas.push_back(lista->at(i));
	}

	maximo = finalistas.at(0);

	for(unsigned int i = 0; i < finalistas.size(); i++)
	{
		if(finalistas.at(i)->getDistancia_percorrida() > maximo->getDistancia_percorrida())
		{
			maximo = finalistas.at(i);
		}
	}

	for(unsigned int i = 0; i < finalistas.size(); i++)
	{
		if(maximo->getDistancia_percorrida() == finalistas.at(i)->getDistancia_percorrida())
		{
				empatados.push_back(finalistas.at(i));
		}
	}

	if(empatados.size() > 1)
	{
		for(unsigned int i = 0; i < empatados.size(); i++)
		{
			empatados.at(i)->setEmpates(empatados.at(i)->getEmpates()+1);
			ranking->push_back(empatados.at(i));
		}
		return true;
	}
	else
	{
		maximo->setVitorias(maximo->getVitorias()+1);
		ranking->push_back(maximo);
		return true;
	}

	return false;
}

void controle_de_menu(int* opcao)
{
	int op = -1;

	std::cout<<"==================================="<<std::endl;
	std::cout<<"FROG SIMULATOR 4000"<<std::endl;
	std::cout<<"==================================="<<std::endl;
	std::cout<<"1 - Cria novo Sapo"<<std::endl;
	std::cout<<"2 - Criar nova Corrida"<<std::endl;
	std::cout<<"3 - Ver estatisticas do sapos"<<std::endl;
	std::cout<<"4 - Ver estatisticas das corridas"<<std::endl;
	std::cout<<"5 - Start"<<std::endl;
	std::cout<<"===================================="<<std::endl;

	while(op < 0 || op > 5)
	{
		std::cout<<"Escolha a opcao desejada:"<<std::endl;
		std::cin>>op;
	}

	 system("@cls||clear");

	 *opcao = op;
}

bool escolher_pista(Pista* pistao, std::vector<Pista*>* pis)
{
	int num = -1;
	std::cout<<"Entre com o numero da pista"<<std::endl;
	std::cin>>num;

	for (unsigned i = 0; i < pis->size(); i++)
	{
		if (num == pis->at(i)->getId())
		{
			*pistao = *pis->at(i);
			return true;
		}
	}

	std::cout<<"Pista nao encontrada"<<std::endl;

	return false;
}

void ver_participantes(std::vector<Sapo*>* lista)
{
	std::cout<<"Participantes: "<<std::endl;

	for(unsigned int i = 0; i < lista->size(); i++)
	{
		std::cout<<"Nome: "<<lista->at(i)->getNome()<<std::endl;
		std::cout<<"Id: "<<lista->at(i)->getIdentificador()<<std::endl;
	}
}

void pei()
{
	std::cout<<"Aperte Enter para comecar a corrida!"<<std::endl;
	std::cin.get();
	system("@cls||clear");
}

void corre_negada(std::vector<Sapo*>* lista, int meta, std::vector<Sapo*>* ranking)
{
	bool meta_alcancada = false;

	while(!meta_alcancada)
	{
		for (unsigned i = 0; i < lista->size(); i++)
		{
			if(lista->at(i)->getDistancia_percorrida() < meta )
				lista->at(i)->pular();
		}

		if(lista->at(0)->distancia_total >= meta)
		{
			meta_alcancada = true;
			chegada(lista, meta, ranking);
		}
	}

	for (unsigned i = 0; i < lista->size(); i++)
	{
		if(lista->at(i)->getDistancia_percorrida() < meta && lista->at(i)->getChegou() == false)
		{
			lista->at(i)->pular();
			if(lista->at(i)->getDistancia_percorrida() >= meta )
			{
				lista->at(i)->setChegou(true);
				ranking->push_back(lista->at(i));
			}
		}
	}

}

void resetar_sapos(std::vector<Sapo*>* lista)
{
	for (unsigned i = 0; i < lista->size(); i++)
	{
		lista->at(i)->setDistancia_percorrida(0);
		lista->at(i)->setQuantidade_de_pulos(0);
		lista->at(i)->setQuantidade_de_provas_disputadas(lista->at(i)->getQuantidade_de_provas_disputadas()+1);
		lista->at(i)->setChegou(false);
	}
}

void mostrar_ranking(std::vector<Sapo*>* ranking)
{
	std::cout<<"Resultado da corrida: "<<std::endl;
	ver_participantes(ranking);
}

void jogar_novamente(bool* jogar)
{
	char j = 'x';

	while(j != 78 || j!= 89 || j != 110 || j != 121)
	{
		std::cout<<"Jogar novamente (y/n) ?";
		std::cin>>j;
	}
	if(j == 121 || j == 89)
		*jogar = true;
	else
		*jogar = false;
}


void liberar_espaco(std::vector<Sapo*>* lista)
{
	for (unsigned i = lista->size(); i > 0 ; i--)
	{
			delete lista->at(i);
			lista->pop_back();
	}
	lista->clear();
}

void liberar_espaco(std::vector<Pista*>* lista)
{
	for (unsigned i = lista->size(); i > 0 ; i--)
	{
			delete lista->at(i);
			lista->pop_back();
	}
	lista->clear();
}
