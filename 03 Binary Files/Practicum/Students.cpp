//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//namespace ConstantsStudent {
//	constexpr int MAX_STUDENTS_COUNT = 1024;
//	constexpr int MAX_NAME_LENGTH = 16;
//	constexpr int MAX_FN_LENGTH = 5;
//	constexpr int MAX_FIELD_COUNT = 5;
//	constexpr int HAIR_COUNT = 5;
//}
//
//using namespace ConstantsStudent;
//
//enum HairColor {
//	brown,
//	black,
//	blond,
//	red,
//	white
//};
//
//struct Student {
//	double averageGrade;
//	char firstName[MAX_NAME_LENGTH];
//	char secondName[MAX_NAME_LENGTH];
//	unsigned fn;
//	HairColor hair;
//};
//
//struct Group {
//	Student students[MAX_STUDENTS_COUNT];
//	unsigned groupSize;
//};
//
//HairColor assignHairColor(const char* hair) {
//	if (strcmp(hair, "brown")==0) {
//		return HairColor::brown;
//	}
//	if (strcmp(hair, "black")==0) {
//		return HairColor::black;
//	}
//	if (strcmp(hair, "blond")==0) {
//		return HairColor::blond;
//	}
//	if (strcmp(hair, "red")==0) {
//		return HairColor::red;
//	}
//	if (strcmp(hair, "white")==0) {
//		return HairColor::white;
//	}
//	
//}
//
//char* getHairColorAsArray(const HairColor& hair) {
//	char* toReturn = new char[MAX_NAME_LENGTH];
//	switch (hair) {
//	case HairColor::brown: strcpy(toReturn, "brown"); break;
//	case HairColor::black: strcpy(toReturn, "black"); break;
//	case HairColor::blond: strcpy(toReturn, "blond"); break;
//	case HairColor::red: strcpy(toReturn, "red"); break;
//	case HairColor::white:strcpy(toReturn, "white");break;
//	}
//	return toReturn;
//}
//
//int intLength(unsigned num) {
//	if (num == 0) {
//		return 0;
//	}
//	int count = 0;
//	while (num != 0) {
//		num %= 10;
//		count++;
//	}
//	return count;
//}
//
//void writeStudentToFile(std::ofstream& ofs, const Student& student) {
//	for (int i = 0;i < MAX_FIELD_COUNT;i++) {
//		ofs << student.firstName << ',' << student.secondName << ',' << student.fn << ',' << student.averageGrade << ',';
//		char* hair = getHairColorAsArray(student.hair);
//		ofs << hair << '\n';
//		delete[] hair;
//	}
//}
//
//void writeGroupToFile(const char* fileName, const Group& group) {
//	std::ofstream ofs(fileName, std::ios::trunc);
//	if (!ofs.is_open()) {
//		return;
//	}
//	for (int i = 0;i < group.groupSize;i++) {
//		writeStudentToFile(ofs, group.students[i]);
//	}
//	ofs.close();
//}
//
//void loadStudentFromFile(std::ifstream& ifs, Student& student) {
//	char hairBuffer[MAX_NAME_LENGTH];
//	ifs.getline(student.firstName, MAX_NAME_LENGTH,',');
//	ifs.getline(student.secondName, MAX_NAME_LENGTH, ',');
//	ifs >> student.fn;
//	ifs.get();
//	ifs >> student.averageGrade;
//	ifs.get();
//	ifs.getline(hairBuffer, MAX_NAME_LENGTH, ',');
//	student.hair=assignHairColor(hairBuffer);
//}
//
//void loadGroupFromFile(std::ifstream& ifs, Group& group) {
//	group.groupSize = 0;
//	while (!ifs.eof()) {
//		loadStudentFromFile(ifs, group.students[group.groupSize]);
//		group.groupSize++;
//	}
//	ifs.close();
//}
//
//void loadGroupFromFile(const char* fileName, Group& group) {
//	std::ifstream ifs(fileName);
//	if (!ifs.is_open()) {
//		return;
//	}
//	loadGroupFromFile(ifs, group);
//}
//
//bool validationFn(unsigned num) {
//	return intLength(num) == 5;
//}
//
