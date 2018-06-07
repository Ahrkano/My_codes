/**
 * @file leitura.cpp
 * @brief implementacao de algumas funcoes para leitura.
 * @author Alexandre
 * @since 04/06/2018
 * @date 06/06/2018
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "leitura.h"
#include "Sapo.h"
#include "Pista.h"
#include "Corrida.h"

/** @details percorre o vetor de Sapo checando se existe um sapo no vetor
 *  com o id igual ao inteiro que foi passado.
 *  @param num possivel id de Sapo.
 *  @param conjunto ponteiro para vetor de Sapo.
 *  @return booleano.
 */
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

/** @details percorre o vetor de Pista checando se existe uma pista no vetor
 *  com o id igual ao inteiro que foi passado.
 *  @param num possivel id de Pista.
 *  @param conjunto ponteiro para vetor de Pista.
 *  @return booleano.
 */
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

/** @details le o arquivo "sapos.txt" e armazena as informacoes de cada sapo no vetor.
 *  Se nao for possivel abrir o arquivo uma mensagemde erro sera exibida na tela.
 *  @param conjunto ponteiro para vetor de Sapo.
 *  @return booleano.
 */
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

/** @brief abre o arquivo "sapos.txt" e concatena as informacoes acerca do novo sapo
 *  ao final do arquivo.
 *  @param novo ponteiro para Sapo.
 *  @return booleano.
 */
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

/** @details le o arquivo "pistas.txt" e armazena as informacoes de cada pista no vetor.
 *  Se nao for possivel abrir o arquivo uma mensagemde erro sera exibida na tela.
 *  @param conjunto ponteiro para vetor de Pista.
 *  @return booleano.
 */
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

			aux = controle%3;

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

/** @details escreve num arquivo os dados da corrida, sendo eles:
 * 	o nome da pista e seu id, bem com o nome de cada sapo e seu
 * 	respecrivo id.
 *  @param corr ponteiro para Corrida.
 *  @return booleano.
 */
bool salvar_arquivo_corrida(Corrida* corr)
{
	 std::ofstream file;
	 file.open("corridas.txt", std::ios::out | std::ios::app);

	 if(file.is_open())
	 {
		 file<<corr->getTrack()->getNome()<<std::endl;
		 file<<corr->getTrack()->getTamanho()<<std::endl;

		 for (unsigned i = 0; i < corr->getParticipantes().size(); i++)
		 {
		 		file<<corr->getParticipantes().at(i)->getNome()<<std::endl;
		 		file<<corr->getParticipantes().at(i)->getIdentificador()<<std::endl;
		 }

		 file.close();
		 return true;
	 }
	 else
		 std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	 return false;
}
