/**
*@file dado.h
*@brief definicao da classe Dado
*@author Alexandre
*@since 13/03/2018
*@date 13/03/2018
*@sa https://github.com/Ahrkano/My_codes/tree/master/C%2B%2B/Dice
*/

#ifndef SRC_DADO_H_
#define SRC_DADO_H_

/**
 * Classe que define um dado.
 */
class Dado
{
	private :
		int lado; ///< Face voltada para cima.
		int faces;	///< Quantidade de faces do dado.

	public:

	    /** @brief define a face voltada para cima.
	     *  @param n numero da face voltada para cima.
	     *  @return sem retorno.
	     */
		void set_lado(int n);
	    /** @brief retorna a face voltada para cima.
	     *  @return numero inteiro.
	     */
		const int get_lado();
	    /** @brief define a quantidade de faces do dado.
	     *  @param f numero de faces .
	     *  @return sem retorno.
	     */
		void set_faces(int f);
	    /** @brief retorna a quantidade de faces do dado.
	     *  @return numero inteiro.
	     */
		const int get_faces();
	    /** @brief construtor da clase Dado .
	     */
		Dado();
	    /** @brief construtor da clase Dado.
	     *  @param _lado face que esta voldata para cima do dado a ser criado.
	     *  @param _faces quantidade de faces do dado a ser criado.
	     */
		Dado(int _lado, int _faces);
	    /** @brief destrutor da classe Dado.
	     */
		~Dado();
};





#endif /* SRC_DADO_H_ */
