/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:26:44 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/31 14:08:09 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange {
	private:
		int _minValue;
		int _maxValue;
		std::map<std::string, float> _data; // contenedor map
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange();

		BitcoinExchange& operator=( const BitcoinExchange& obj );

		int getMinValue() const;
		int getMaxValue() const;
		std::map<std::string, float> getData() const;

		void showData() const;
		void checkInput(const char *inputFile) const;
		
		static std::map<std::string, float> saveData( const char *fileName );
};

bool validDate(const std::string date);

#endif
