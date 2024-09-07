/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/07 20:52:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

/*
Desenvolva uma classe Span que possa armazenar um máximo de N inteiros. N é 
uma variável unsigned int e será o único parâmetro passado ao construtor.

Esta classe terá uma função membro chamada addNumber() para adicionar um único 
número ao Span. Ele será usado para preenchê-lo. Qualquer tentativa de adicionar 
um novo elemento se já houver N elementos armazenados deve lançar uma exceção.

Em seguida, implemente duas funções membro: shortestSpan() e longestSpan()

Elas descobrirão respectivamente o menor span ou o maior span (ou distância, 
se preferir) entre todos os números armazenados e o retornarão. Se não houver 
números armazenados, ou apenas um, nenhum span poderá ser encontrado. 
Portanto, lance uma exceção.

Claro, você escreverá seus próprios testes e eles serão muito mais completos 
do que os abaixo. Teste seu Span pelo menos com um minimo de 10.000 números. 
Mais seria ainda melhor.

Por último, mas não menos importante, seria maravilhoso preencher seu Span 
usando um intervalo de iteradores. Fazer milhares de chamadas para addNumber() 
é muito chato. Implemente uma função membro para adicionar muitos números ao 
seu Span em uma chamada.

Se você não tem ideia, estude os Containers. Algumas funções membro usam um 
intervalo de iteradores para adicionar uma sequência de elementos ao container.
*/

class Span
{
	private:
		Span();
		size_t _maxIntegers;
		size_t _currentStored;
		std::vector<int> _integers;
	public:
		Span(const unsigned int N);
		Span(const Span &copyObj);
		Span &operator=(const Span &copyAssign);
		~Span();
	
		void addNumber(const int &num);
		long int shortestSpan();
		// long int longestSpan();
		// void addAnyNumbers();
		void getNumber();
};

Span::Span(): _maxIntegers(0), _currentStored(0)
{
	// std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(const unsigned int N):
	_maxIntegers(N), _currentStored(0), _integers(std::vector<int>())
{
	// std::cout << "Span Parameter Constructor called" << std::endl;
	if (_maxIntegers <= 1)
		throw std::runtime_error("Span class must store more than 1 integer");
}

Span::Span(const Span &copyObj): _maxIntegers(copyObj._maxIntegers), 
	_currentStored(copyObj._currentStored), _integers(copyObj._integers)
{
	// std::cout << "Span Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Span &Span::operator=(const Span &copyAssign)
{
	// std::cout << "Span Assignment Constructor called" << std::endl;
	if (this != &copyAssign)
	{
		_maxIntegers = copyAssign._maxIntegers;
		_currentStored = copyAssign._currentStored;
		_integers = copyAssign._integers;
	}
	return (*this);
}

Span::~Span()
{
	// std::cout << "Span Destructor called" << std::endl;
}

// Members Functions
void Span::addNumber(const int &num)
{
	if (_currentStored == _maxIntegers)
		throw std::runtime_error("Span class storage is full");
	_integers.push_back(num);
	_currentStored++;
}

long int Span::shortestSpan()
{
	if (_currentStored < 2)
		throw std::logic_error("Cannot find Span");

	std::vector<int> sortInt = _integers;
	std::sort(sortInt.begin(), sortInt.end());
	
	long int getSpan = std::numeric_limits<long int>::max();
	for (size_t i = 1; i < sortInt.size(); ++i)
	{
		long int span = sortInt[i] - sortInt[i - 1];
		if (span < getSpan)
			getSpan = span;
	}
	return (getSpan);
}

// long int Span::longestSpan()
// {

// }

// void Span::addAnyNumbers()
// {

// }

void Span::getNumber()
{
	for (size_t i = 0; i < _integers.size(); i++)
		std::cout << _integers[i] << " ";
	std::cout << std::endl;
}

#endif // SPAN_HPP