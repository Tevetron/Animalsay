#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

void ReadFile(const std::string &name, std::vector<std::string> &animal, unsigned int &height, unsigned int &width) {
	std::string picfile = name + ".txt";
	std::ifstream in_str(picfile.c_str());
	if(!in_str.good()) {
		std::cerr << "Error: Cannot open " << picfile << " for reading." << std::endl;
		exit(0);
	}
	std::string temp;
	int i = 0;
	while(true) {
		if(in_str.eof()) { break; }
		std::getline(in_str, temp);
		temp = temp.substr(0,temp.size() - 1);
		animal.push_back(temp);
		i ++;
	}
	height = animal.size();
	width = animal[0].size();
}

int main (int argc, char* argv[]) {
	
	if(argc != 3) {
		std::cerr << "Invalid Number of Arguments" << std::endl;
		exit(0);
	}
	unsigned int height, width;
	std::vector<std::string> animal;
	std::string str = argv[2];
	ReadFile(argv[1], animal, height, width);

	for(unsigned int i = 0; i < animal.size(); i ++) {
		for(unsigned int j = 0; j < animal[i].size(); j ++) {
			std::cout << animal[i][j]; 
		}
		if(i == height / 2 - 3) {
			std::cout << "     ";
			for(unsigned int k = 0; k < str.size() + 1; k ++)
				std::cout << "_";
		}
		else if(i == height / 2 - 2) {
			std::cout << "    /";
			for(unsigned int k = 0; k < str.size(); k ++)
				std::cout << " ";
			std::cout << "/";
		}
		else if(i == height / 2 - 1) {
			std::cout << "   /" << str << "/";
		}
		else if(i == height / 2) {
			std::cout << "__/";
			for(unsigned int k = 0; k < str.size(); k ++)
				std::cout << "_";
			std::cout << "/";
		}
		std::cout << std::endl;
	}
}