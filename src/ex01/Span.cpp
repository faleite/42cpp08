/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/11 19:04:55 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Orthodox Canonical Form

Span::Span(): _maxIntegers(0), _currentStored(0)
{
	// std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(const unsigned int N):
	_maxIntegers(N), _currentStored(0), _integers(std::vector<int>())
{
	// std::cout << "Span Parameter Constructor called" << std::endl;

	// if (static_cast<int>(_maxIntegers) < 2)
	if (_maxIntegers < 2)
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
		unsigned int span = sortInt[i] - sortInt[i - 1];
		if (span < getSpan)
			getSpan = span;
	}
	return (getSpan);
}

long int Span::longestSpan()
{
	if (_currentStored < 2)
		throw std::logic_error("Cannot find Span");
	
	long int minElement = *std::min_element(_integers.begin(), _integers.end());
	long int maxElement = *std::max_element(_integers.begin(), _integers.end());

	// less efficient option O(n log n)
	// std::vector<int> sortInt = _integers;
	// std::sort(sortInt.begin(), sortInt.end());
	// return(sortInt.back() - sortInt.front());
	
	return(maxElement - minElement);
}

void Span::addAnyNumbers(const std::vector<int> &arr)
{
	size_t sizeArr = arr.size();
	
	if (_currentStored + sizeArr > _maxIntegers)
		throw std::runtime_error("Span class storage is full");
	
	_integers.insert(_integers.end(), arr.begin(), arr.end());
	_currentStored += sizeArr;
}

void Span::getNumbers()
{
	for (size_t i = 0; i < _integers.size(); i++)
		std::cout << _integers[i] << " ";
	std::cout << std::endl;
}
