/*
 * funcoes.cpp
 *
 *  Created on: 15 de mar de 2018
 *      Author: Alexandre
 */
#include "funcoes.h"
#include "Sapo.h"

#include <iostream>
#include <stdlib.h>


int variacao(int min, int max)
{
	return rand() % max + min;
}

bool chegada(Sapo participante, int meta)
{
	if(participante.getDistancia_percorrida() >= meta)
		return true;
	return false;
}

void estatistica(std::vector<Sapo*>* Participantes)
{
	for (unsigned i = 0; i < Participantes->size(); i++)
	{
		std::cout<<"Nome: "<<Participantes->at(i)->getNome()<<std::endl;
		std::cout<<"ID: "<<Participantes->at(i)->getIdentificador()<<std::endl;
		std::cout<<"Distancia percorrida: "<<Participantes->at(i)->getDistancia_percorrida()<<" unidades"<<std::endl;
		std::cout<<"Contagem de pulos: "<<Participantes->at(i)->getQuantidade_de_pulos()<<std::endl;
		std::cout<<std::endl;
	}
}

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

bool corrida_em_andamento(Corrida* corr)
{
	if (corr->getParticipantes().at(0)->distancia_total >= corr->getTrack()->getTamanho())
	{
		return false;
	}
	return true;
}

void apresentacao()
{
	std::cout<<"\nBEM VINDO AO FROGRACE JUMP SIMULATOR 3000!";
}

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

void criar_pista(Pista* add)
{
	add = new Pista();
	std::string nome;
	int tam;
	int id;

	std::cout<<"Nome: ";
	std::getline(std::cin, nome);
	std::cout<<std::endl;
	std::cout<<"Identificacao: ";
	std::cin>>id;
	std::cout<<std::endl;
	std::cout<<"Tamanho: ";
	std::cin>>tam;
	std::cout<<std::endl;

	add->setNome(nome);
	add->setId(id);
	add->setTamanho(tam);
}

void encerrar_corrida(Corrida* corr)
{
	for (unsigned i = 0; i < corr->getParticipantes().size(); i++)
	{
		corr->getParticipantes().pop_back();
	}
}
