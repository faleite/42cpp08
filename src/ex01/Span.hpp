/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/08 17:14:33 by faaraujo         ###   ########.fr       */
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
		long int longestSpan();
		void addAnyNumbers(const std::vector<int> &nums);
		void getNumbers();
};

#endif // SPAN_HPP