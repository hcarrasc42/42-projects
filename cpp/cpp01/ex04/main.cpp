/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:36:04 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 13:32:14 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(std::string line, std::string s1, std::string s2) {
    std::string::size_type pos = 0;
    
	//line.find(s1, pos) returns the position of the first occurrence of s1 in line
    while ((pos = line.find(s1, pos)) != std::string::npos) { // std::string::npos is a constant representing the end of a string
        line.replace(pos, s1.length(), s2); // replace the substring s1 with s2
        pos += s2.length(); // increment pos to avoid infinite loop
    }
    
    return line;
}

int main(int argc, char const **argv) {
    if (argc == 4) {
        std::string     filename = argv[1];
        std::string     s1 = argv[2];
        std::string     s2 = argv[3];
        std::string     line;
        std::ifstream   infile;
        std::ofstream   outfile;
        
        infile.open(filename);
        if (infile.is_open()) {
            outfile.open(filename + ".replace", std::ios::trunc); // std::ios::trunc to overwrite the file
            if (outfile.is_open()) {
                while (std::getline(infile, line)) {
                    line = ft_replace(line, s1, s2);
                    outfile << line << std::endl;
                }
                outfile.close();
            }
            else {
                std::cout << "Error: could not open file" << std::endl;
                infile.close();
                return 1;
            }
            infile.close();
        } else {
            std::cout << "Error: could not create file" << std::endl;
            return 1;
        }
        return 0;
    }
    else {
        std::cout << "wrong arguments" << std::endl;
    }
    return 0;
}
