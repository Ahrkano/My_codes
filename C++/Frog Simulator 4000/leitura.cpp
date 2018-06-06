/*
 * leitura.cpp
 *
 *  Created on: 4 de jun de 2018
 *      Author: Alexandre
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "leitura.h"
#include "Sapo.h"
#include "Pista.h"

bool ja_existe(int num, std::vector<Sapo*>* conjunto)
{
	for (unsigned i = 0; i < conjunto->size(); i++)
	{
		if(conjunto->at(i)->getIdentificador() == num)
		{
			return true;
		}
	}
	return false;
}

bool ja_existe(int num, std::vector<Pista*>* conjunto)
{
	for (unsigned i = 0; i < conjunto->size(); i++)
	{
		if(conjunto->at(i)->getId() == num)
		{
			return true;
		}
	}
	return false;
}


bool ler_arquivo_competidores(std::vector<Sapo*>* conjunto )
{
	std::string nome;
	int _id;
	int _qtd_provas;
	int _vit;
	int _emp;
	int _qtd_pulos_total;

	std::ifstream file("sapos.txt", std::ios_base::in);
	std::string line;
	int controle;

	if(file.is_open())
	{
		controle = 0;

		while (std::getline(file, line))
		{

			int aux = controle%6;

			std::istringstream ss(line);

			switch(aux)
			{
				case 0: nome = line;
						break;
				case 1: ss.imbue(std::locale::classic());
			    		ss >> _id;
			    		break;
				case 2:	ss.imbue(std::locale::classic());
			    		ss >> _qtd_provas;
			    		break;
				case 3: ss.imbue(std::locale::classic());
	    				ss >> _vit;
	    				break;
				case 4: ss.imbue(std::locale::classic());
						ss >> _emp;
						break;
				case 5: ss.imbue(std::locale::classic());
						ss >> _qtd_pulos_total;

						if(!ja_existe(_id, conjunto))
						{
							Sapo* novo = new Sapo(_id, _qtd_provas, _vit, _emp, _qtd_pulos_total, nome);
							conjunto->push_back(novo);
						}
						break;
			}

			controle++;
		}
		file.close();
	}
	else
	{
		std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	}

	return false;
}

bool salvar_arquivo_competidores(Sapo* novo)
{
	 std::ofstream file;
	 file.open("sapos.txt", std::ios::out | std::ios::app);

	 if(file.is_open())
	 {
		 file<<novo->getNome()<<std::endl;
		 file<<novo->getIdentificador()<<std::endl;
		 file<<novo->getQuantidade_de_provas_disputadas()<<std::endl;
		 file<<novo->getVitorias()<<std::endl;
		 file<<novo->getEmpates()<<std::endl;
		 file<<novo->getQuantidade_de_pulos_total()<<std::endl;
		 file.close();
		 return true;
	 }
	 else
		 std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	 return false;
}

bool ler_arquivo_trajetos(std::vector<Pista*>* conjunto)
{
	std::ifstream file("pistas.txt", std::ios_base::in);
	std::string line;
	std::string nome;
	int tam;
	int id;
	int controle;
	int aux;

	if(file.is_open())
	{
		controle = 0;

		while (std::getline(file, line))
		{

			int aux = controle%3;

			std::istringstream ss(line);

			switch(aux)
			{
				case 0: nome = line;
						break;
				case 1: ss.imbue(std::locale::classic());
			    		ss >> tam;
			    		break;
				case 2:	ss.imbue(std::locale::classic());
			    		ss >> id;
			    		if(!ja_existe(id, conjunto))
			    		{
			    		   	Pista* novo = new Pista(nome, tam, id);
			    		   	conjunto->push_back(novo);
			    		}
			    		break;
			}

			controle++;
		}
		file.close();
		return true;
	}
	else
		std::cerr<<"Arquivo nao foi aberto"<<std::endl;

	return false;
}

bool salvar_arquivo_trajetos(Pista* conjunto)
{
	 std::ofstream file;
	 file.open("pistas.txt", std::ios::out | std::ios::app);

	 if(file.is_open())
	 {
		 file<<conjunto->getNome()<<std::endl;
		 file<<conjunto->getTamanho()<<std::endl;
		 file<<conjunto->getId()<<std::endl;
		 file.close();
		 return true;
	 }
	 else
		 std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	 return false;
}
