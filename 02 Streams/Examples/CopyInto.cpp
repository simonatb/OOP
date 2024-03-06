#include <iostream>
#include <fstream>

constexpr char SOURCE[] = "ExamplesFromGithub.cpp";
constexpr char DEST[] = "dest.txt";
const int BUFF_SIZE = 1024;


void copyInto(std::ifstream& source, std::ofstream& dest) {
	char buff[BUFF_SIZE];
	while (source.getline(buff, BUFF_SIZE)) {
		dest << buff << std::endl;
	}
}
void openingFiles(const char* source, const char* dest) {
	std::ifstream ifs(source);

	if (!ifs.is_open()) {
		std::cout << "error" << std::endl;
		return;
	}

	std::ofstream ofs(dest);

	if (!ofs.is_open()) {
		std::cout << "error" << std::endl;
		return;
	}

	copyInto(ifs, ofs);
}