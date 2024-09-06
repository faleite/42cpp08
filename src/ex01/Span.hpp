/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/06 20:15:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span &copyObj);
		Span &operator=(const Span &copyAssign);
		~Span();
	
		void addNumber(const unsigned int N);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif // SPAN_HPP