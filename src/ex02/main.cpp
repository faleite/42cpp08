/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:11:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/09 21:09:08 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << "======= Looking at a MutantStack =======" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "The first element: " << *mstack.begin() << std::endl;
	std::cout << "The last element (out): " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Stack size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	
	for (size_t i = 1; i <= 10; i++)
		mstack.push(i);

	mstack.push(17);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "Elements: ";
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	
	std::cout << "\n======= Reverse Iterator =======" << std::endl;
	std::cout << "Elements: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	
	std::cout << "\n========= Looking at a stack ==========" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "Stack (s) is empty: " << (s.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Stack size: " <<s.size() << std::endl;

	s.push(9);
	s.pop();
	s.push(48);
	s.top() -= 6;
	std::cout << "The last element: " << s.top() << std::endl;
	
	return (0);
}
