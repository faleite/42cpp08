/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:58:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/11 19:06:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "Default Test:" << std::endl;
	{	
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	std::cout << "\nMultiple number and single number test:" << std::endl;
	{
		int arr[] = {12, 134, 14, 23, 84, 102, 7, 65, 99, 10};
		int sizeArr =  sizeof(arr) / sizeof(int);
		std::vector<int> numbers(arr, arr + sizeArr);
		try
		{
			Span sp = Span(12);
			
			sp.addNumber(1);
			sp.addNumber(3);
			sp.addAnyNumbers(numbers);	
			
			// sp.getNumbers();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\nMore than 10,000 numbers in addition:" << std::endl;
	{
		std::vector<int> numbers(12000);
		for (size_t i = 0; i < 12000; ++i)
			numbers[i] = i;
		try
		{
			Span sp = Span(12000);
			
			sp.addAnyNumbers(numbers);	
			
			// sp.getNumbers();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}