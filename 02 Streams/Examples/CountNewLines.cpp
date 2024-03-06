#include <iostream>
#include <fstream>

constexpr char SOURCE[] = "ExamplesFromGithub.cpp";
constexpr char DEST[] = "dest.txt";
const int BUFF_SIZE = 1024;

unsigned getCharCountFromFile(std::ifstream& ifs, char ch) {
	if (!ifs.is_open()) {
		return 0;
	}
	unsigned int count = 0;

	while (true) {
		char current = ifs.get();
		if (ifs.eof()) {
			break;
		}
		if (current == ch) {
			count++;
		}
	}
	return count;
}

unsigned getLinesCount(const char* fileName) {
     std::ifstream myFile(fileName);

	 if (!myFile.is_open()) {
		 return 0;
	 }
	 return getCharCountFromFile(myFile, '\n') + 1;

}