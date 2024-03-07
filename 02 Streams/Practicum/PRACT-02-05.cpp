
const constexpr int MAX_LENGTH = 1024;

int stringCompare(const char* first, const char* second) {
	if (!first || !second) {
		return -1;
	}
	while (*first == *second && *first && *second) {
		first++;
		second++;
	}
	return *first - *second;
}

void writeDifferencesToFile(std::ifstream& ifs1, std::ifstream& ifs2, std::ofstream& ofs) {
	if (!ifs1.is_open() || !ifs2.is_open() || !ofs.is_open()) {
		return;
	}
	char before[MAX_LENGTH];
	char after[MAX_LENGTH];
	while (!ifs1.eof() && !ifs2.eof()) {
		ifs1.getline(before, MAX_LENGTH, '\n');
		ifs2.getline(after, MAX_LENGTH, '\n');
		if (stringCompare(before, after) == 0) {
			ofs << before << std::endl;
		}
		else {
			if (!ifs1.eof()) {
				ofs << "- " << before << '\n';
			}
			if (!ifs2.eof()) {
				ofs << "+ " << after << '\n';
			}
		}
	}
	ofs.flush();
	while (true) {
		ifs1.getline(before, MAX_LENGTH, '\n');
		if (ifs1.eof()) {
			break;
		}
		ofs << '-' << before << std::endl;
	}
	while (true) {
		ifs2.getline(after, MAX_LENGTH, '\n');
		if (ifs2.eof()) {
			break;
		}
		ofs << '-' << after << std::endl;
	}
}
int main() {
	std::ifstream ifs1("file1.txt");
	std::ifstream ifs2("file2.txt");
	std::ofstream ofs("file3.txt");
	writeDifferencesToFile(ifs1, ifs2, ofs);
}
