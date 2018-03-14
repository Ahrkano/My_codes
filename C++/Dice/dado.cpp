/**
*@file dado.h
*@brief definicao da classe Dado
*@author Alexandre
*@since 13/03/2018
*@date 13/03/2018
*@sa https://github.com/Ahrkano/My_codes/tree/master/C%2B%2B/Dice
*/

#include "dado.h"

/** @details cria um Dado que por padrao tem 6 faces e a
* 	face voltada para cima vale 1.
*/
Dado::Dado ()
{
	lado = 1;
	faces = 6;
}

/** @details cria um Dado com (_faces) faces e cujo lado
*   voltado para cima vale (_lado).
*  @param _lado face que esta voldata para cima do dado a ser criado.
*  @param _faces quantidade de faces do dado a ser criado.
*/
Dado::Dado(int _lado, int _faces)
{
	lado = _lado;
	faces = _faces;
}

/** @details destrutor da classe Dado.
 */
Dado::~Dado ()
{

}

/** @details lado recebe o valor n.
 *  @param n numero da face voltada para cima.
 */
void Dado::set_lado(int n)
{
	lado = n;
}

/** @details retorna a face voltada para cima.
 *  @return numero inteiro.
 */
const int Dado::get_lado()
{
	return lado;
}

/** @details define a quantidade de faces do dado.
 *  @param f numero de faces .
 */
void Dado::set_faces(int f)
{
	faces = f;
}

/** @details retorna a quantidade de faces do dado.
 *  @return numero inteiro.
 */
const int Dado::get_faces()
{
	return faces;
}
