/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:36:17 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/09 19:57:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

/*
Agora, é hora de passar para coisas mais sérias. 
Vamos desenvolver algo estranho.

O contêiner std::stack é muito bom. Infelizmente, é um dos únicos 
contêineres STL que NÃO é iterável. Que pena.

Mas por que aceitaríamos isso? Especialmente se pudermos tomar a liberdade 
de massacrar a pilha original para criar recursos ausentes.

Para reparar essa injustiça, você precisa tornar o 
contêiner std::stack iterável.

Escreva a classe MutantStack. Ela será implementada em termos de um std::stack. 
Ela oferecerá todas as suas funções de membro, 
além de um recurso adicional: iteradores.

Claro, você escreverá e entregará seus próprios testes para garantir que tudo 
funcione conforme o esperado.

Se você executá-lo pela primeira vez com seu MutantStack e pela segunda vez 
substituindo o MutantStack por, por exemplo, um std::list, as duas saídas devem 
ser as mesmas. Claro, ao testar outro contêiner, atualize o código abaixo com as 
funções de membro correspondentes (push() pode se tornar push_back()).
*/


/*
By default, if no container class is specified for a particular stack class 
instantiation, the standard container deque is used.
The container shall support the following operations:
empty, size, back, push_back, pop_back
*/
template<
	typename T,
	typename Container = std::deque<T>
> class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator 		begin(); // retorna um iterador para o início do contêiner.
		const_iterator 	begin() const; // retorna um iterador constante para o início do contêiner.
		iterator 		end(); // retorna um iterador para o final do contêiner.
		const_iterator 	end() const; // retorna um iterador constante para o final do contêiner.

		reverse_iterator rbegin(); // retorna um iterador reverso para o início do contêiner.
		const_reverse_iterator rbegin() const; // retorna um iterador reverso constante para o início do contêiner.
		reverse_iterator rend(); // retorna um iterador reverso para o final do contêiner.
		const_reverse_iterator rend() const; // retorna um iterador reverso constante para o final do contêiner.
};

template<
	typename T,
	typename Container
> typename Container::iterator MutantStack<T, Container>::begin()
{
	// return (std::stack<, Container>::c.begin());
	return (this->c.begin());
}

template<
	typename T,
	typename Container
> typename Container::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template<
	typename T,
	typename Container
> typename Container::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template<
	typename T,
	typename Container
> typename Container::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template<
	typename T,
	typename Container
> typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template<
	typename T,
	typename Container
> typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template<
	typename T,
	typename Container
> typename Container::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template<
	typename T,
	typename Container
> typename Container::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}

#endif // MUTANTSTACK_HPP
