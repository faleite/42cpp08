/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:19:57 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/10 17:16:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	{	
		std::vector<int> myVector;
		for(size_t i = 1; i <= 42; i++)
			myVector.push_back(i);
		
		// std::srand(unsigned(std::time(0)));
		std::random_shuffle(myVector.begin(), myVector.end());
		std::cout << "Numbers in vector:" << std::endl;
		for(size_t i = 0; i < 42; i++)
			std::cout << myVector[i] << " ";
		std::cout << std::endl;
		
		std::cout << "Number search:" << std::endl;
		try
		{
			std::vector<int>::iterator it = easyfind(myVector, 42);
			int index = std::distance(myVector.begin(), it);
			std::cout << "Found " << *it
			<< " at index " << index << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{	
		std::list<int> myList;
		for(size_t i = 1; i <= 42; i++)
			myList.push_back(i);

		std::cout << "\nNumbers in list:" << std::endl;
		for(std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Number search:" << std::endl;
		try
		{
			std::list<int>::iterator it = easyfind(myList, 12);
			int index = std::distance(myList.begin(), it);
			std::cout << "Found " << *it
			<< " at index " << index << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
