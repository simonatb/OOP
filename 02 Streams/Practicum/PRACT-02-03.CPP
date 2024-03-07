#include <iostream>
#include <fstream>

const constexpr int MAX_RELATION_SIZE = 25;
const char FILENAME[] = "relation.txt";

struct Pair {
	int x;
	int y;
};

struct Relation
{
	Pair pairs[MAX_RELATION_SIZE];
	unsigned int size;
};

Pair initPair(int x,int y) {
	Pair created;
	created.x = x;
	created.y = y;
	return created;
}

Pair createPair() {
	Pair created;
	int x, y;
	std::cin >> x >> y;
	created.x = x;
	created.y = y;
	return created;
}

Pair readPairFromFile(std::ifstream& ifs) {
	Pair pair;
	if (!ifs.is_open()) {
		return ;
	}
	
	ifs >> pair.x >> pair.y;
	return pair;
}

void writePairToFile(std::ofstream& ofs, const Pair& pair) {
	if (!ofs.is_open()) {
		return;
	}
	ofs << pair.x << " " << pair.y<<std::endl;
}

void addPairToRelation(const Pair& pair, Relation& relation) {
	if (relation.size < MAX_RELATION_SIZE) {
		relation.pairs[relation.size] = pair;
		relation.size++;
	}
	else return;
} 

void writeRelationToFile(std::ofstream& ofs,const Relation& relation) {
	if (!ofs.is_open()) {
		return;
	}
	for (int i = 0;i < relation.size;i++) {
		writePairToFile(ofs, relation.pairs[i]);
	}
}

Relation readRelationFromFile(std::ifstream& ifs) {
	Relation relation;
	ifs >> relation.size;
	for (int i = 0;i < relation.size;i++) {
		relation.pairs[i] = readPairFromFile(ifs);
	}
	return relation;
}
