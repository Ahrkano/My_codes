/*
 * dado.cpp
 *
 *  Created on: 13 de mar de 2018
 *      Author: Alexandre
 */

#include "dado.h"

void Dado::set_lado(int n)
{
	lado = n;
}

const int Dado::get_lado()
{
	return lado;
}
