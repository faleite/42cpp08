/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:44:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/05 21:09:03 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // in use: random_shuffle and find()
#include <iterator>
#include <exception>
// #include <ctime>

/*
Um primeiro exercício fácil é a maneira de começar com o pé direito.

Escreva um modelo de função easyfind que aceite um tipo T. 
Ele pega dois parâmetros. O primeiro tem o tipo T e o segundo é um inteiro.

Supondo que T seja um contêiner de inteiros, esta função tem que encontrar 
a primeira ocorrência do segundo parâmetro no primeiro parâmetro.

Se nenhuma ocorrência for encontrada, você pode lançar uma exceção ou retornar 
um valor de erro de sua escolha. Se precisar de inspiração, 
analise como os contêineres padrão se comportam.

Claro, implemente e entregue seus próprios testes para garantir 
que tudo funcione conforme o esperado.

Você não precisa lidar com contêineres associativos.
*/

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return (it);
}

#endif // EASYFIND_HPP