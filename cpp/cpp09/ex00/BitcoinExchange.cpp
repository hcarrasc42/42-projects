/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 17:07:48 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _minValue(0), _maxValue(1000) {
	_data = saveData("data.csv"); // guarda los datos en el contenedor map
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	_minValue = obj.getMinValue();
	_maxValue = obj.getMinValue();
	_data = obj.getData();
	return *this;
}

int BitcoinExchange::getMinValue() const {
	return _minValue;
}

int BitcoinExchange::getMaxValue() const {
	return _maxValue;
}

std::map<std::string, float> BitcoinExchange::getData() const {
	return _data;
}

void BitcoinExchange::showData() const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << " - " << it->first << " ==> " << it->second << "\n";
	}
}

void BitcoinExchange::checkInput(const char *inputFile) const {
	std::ifstream input(inputFile);
	if (input) {
		std::string line;
		std::getline(input, line); // lee la primera linea
		while (std::getline(input, line)) {
			size_t div = line.find_first_of(" |");
			std::string date = line.substr(0, div); // guarda la fecha
			float value = std::strtod(line.substr(line.find('|') + 1).c_str(), NULL); // guarda el valor
			if (!validDate(date)) { // valida la fecha
				std::cerr << "Error: bad input => " << date << "\n";
			} else if (line.find('|') == std::string::npos) { // valida el formato
				std::cerr << "Error: value not found.\n";
			} else if (value > 1000) { // valida el valor
				std::cerr << "Error: too large a number.\n";
			} else if (value < 0) { // valida el valor
				std::cerr << "Error: not a positive number.\n";
			} else {
				std::map<std::string, float>::const_iterator it = _data.upper_bound(date); // busca la fecha mas cercana
				if (it->first.compare(date) != 0)
					--it;
				std::cout << date << " => " << value << " = " << it->second*value << "\n"; // muestra la fecha, el valor y el resultado
			}
		}
	} else {
		std::cerr << "Error: could not open the input file\n";
	}
}

std::map<std::string, float> BitcoinExchange::saveData(const char *fileName) { // guarda los datos del archivo ".csv" en el contenedor map
	std::map<std::string, float> data;
	std::ifstream file(fileName);
	if (file) {
		std::string line;
		std::getline(file, line);
		while (std::getline(file, line)) {
			size_t div = line.find(",");
			std::string date = line.substr(0, div);
			float rate = std::strtod(line.substr(div + 1).c_str(), NULL);
			data[date] = rate;
		}
	} else {
		std::cerr << "Error: could not open the data base file\n";
	}
	return data;
}

bool validDate(const std::string date) { // valida la fecha
	int count = 0;
	for (size_t i = 0; date[i]; i++) {
		if (!std::isdigit(date[i]) && date[i] != '-')
			return false;
		if (date[i] == '-')
			count++;
	}
	if (count != 2)
		return false;
	size_t div1 = date.find('-', 0);
	size_t div2 = date.find('-', div1 + 1);
	int year = std::atof(date.substr(0, div1).c_str());
	int month = std::atof(date.substr(div1 + 1, div2 - div1 - 1).c_str());
	int day = std::atof(date.substr(div2 + 1).c_str());
	if (year > 2023 || year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
		return false;
	return true;
}
