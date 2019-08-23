/**
 * @file leitura.cpp
 * @brief implementacao de algumas funcoes para leitura.
 * @author Alexandre
 * @since 04/06/2018
 * @date 06/06/2018
 */
#include "leitura.h"

bool ler_arquivo_competidores(std::vector<Sapo*>* conjunto )
{
	std::string nome;
	int _id;
	int _qtd_provas;
	int _vit;
	int _emp;
	int _qtd_pulos_total;

	std::string line;
	std::ifstream file ("sapos.txt");
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
						if(!procurar_id(conjunto, _id))
						{
							Sapo* novo = new Sapo(_id, _qtd_provas, _vit, _emp, _qtd_pulos_total, nome);
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
		 file<<std::endl;
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

bool ler_arquivo_pistas(std::vector<Pista*>* conjunto)
{
	std::string line;
	std::ifstream file ("pistas.txt");
	std::string nome;
	int tam;
	int id;
	int controle;

	if(file.is_open())
	{
		controle = 0;

		while (std::getline(file, line))
		{

			std::istringstream ss(line);

			switch(controle%3)
			{
				case 0: nome = line;
						break;
				case 1: ss.imbue(std::locale::classic());
			    		ss >> tam;
			    		break;
				case 2:	ss.imbue(std::locale::classic());
			    		ss >> id;
			    		if(!procurar_id(conjunto, id))
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

bool salvar_corrida(Corrida* evento, Sapo* vencedor)
{
	std::ofstream file;
	file.open("corridas.txt", std::ios::out | std::ios::app);

	if(file.is_open())
	{
		file<<evento->getTrack()->getNome()<<std::endl;
		file<<evento->getParticipantes().size()<<" participantes"<<std::endl;
		file<<vencedor->getNome()<<" foi o vencedor"<<std::endl;
		file<<std::endl;
		file.close();
		return true;
	}
	else
		 std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	 return false;
}

bool ler_estatisticas_corridas()
{
	  std::string line;
	  std::ifstream file ("corridas.txt");

	  if (file.is_open())
	  {

	    while(std::getline(file, line))
	    {
	    	std::cout << line <<std::endl;
	    }
	    file.close();
	    return true;
	  }

	  else
		  std::cerr<<"Arquivo nao foi aberto"<<std::endl;

	  return false;
}

bool ler_estatisticas_sapos()
{

	std::string line;
	std::ifstream file ("sapos.txt");
	int controle = 0;

	if(file.is_open())
	{
		while (std::getline(file, line))
		{
			std::cout<<std::endl;

			if(controle%6 == 0)
				std::cout<<"Nome: "<<line<<std::endl;
			if(controle%6 == 1)
				std::cout<<"Id: "<<line<<std::endl;
			if(controle%6 == 2)
				std::cout<<"Provas disputadas : "<<line<<std::endl;
			if(controle%6 == 3)
				std::cout<<"Vitorias : "<<line<<std::endl;
			if(controle%6 == 4)
				std::cout<<"Empates : "<<line<<std::endl;
			if(controle%6 == 5)
				std::cout<<"Pulos totais : "<<line<<std::endl;

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

bool atualizar_sapos(std::vector<Sapo*>* conjunto)
{
	std::ofstream file;
	file.open("sapos.txt");

	if(file.is_open())
	{
		for(unsigned int i = 0; i < conjunto->size(); i++)
		{
			file<<conjunto->at(i)->getNome()<<std::endl;
			file<<conjunto->at(i)->getIdentificador()<<std::endl;
			file<<conjunto->at(i)->getQuantidade_de_provas_disputadas()<<std::endl;
			file<<conjunto->at(i)->getVitorias()<<std::endl;
			file<<conjunto->at(i)->getEmpates()<<std::endl;
			file<<conjunto->at(i)->getQuantidade_de_pulos_total()<<std::endl;
		}
	 	 file.close();
	 	 return true;
	}
	else
		std::cerr<<"Arquivo nao foi aberto"<<std::endl;
	return false;
}
