#include <iostream>
#include <fstream>

constexpr int BUFF_SIZE = 1024;
constexpr char FILE_NAME[] = "ExamplesFromGithub.cpp";

int main() {
	std::ifstream ifs(FILE_NAME);
	if (!ifs.is_open()) {
		std::cout << "Error" << std::endl;
		return -1;
	}

	while (!ifs.eof()) {
		char buff[BUFF_SIZE];
		ifs.getline(buff, BUFF_SIZE);

		//std::cout << buff << std::endl;
	}
	ifs.close();
}