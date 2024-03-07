const constexpr int MAX_USER = 128;
const constexpr int MAX_SYSTEM = 100;

void copyString(const char* source, char* dest) {
	if (!source || !dest) {
		return;
	}
	while (*source) {
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

struct User {
	char name[MAX_USER];
	char mail[MAX_USER];
	char password[MAX_USER];
};

struct System {
	User users[MAX_SYSTEM];
	unsigned size;
};

User readUserFromFile(std::ifstream& ifs) {
	User user;
	if (!ifs.is_open()) {
		return;
	}
	
	ifs >> user.name >> user.mail >> user.password;
	return user;
}

void writeUserToFile(std::ofstream& ofs,const User& user) {
	if (!ofs.is_open()) {
		return;
	}
	ofs << user.name << ' ' << user.mail << ' ' << user.password << std::endl;
}

System readSystemFromFile(std::ifstream& ifs) {
	System system;
	if (!ifs.is_open()) {
		return;
	}
	ifs >> system.size;
	for (int i = 0;i < system.size;i++) {
		system.users[i] = readUserFromFile(ifs);
	}
	return system;
}

void writeSystemToFile(std::ofstream& ofs, const System& system) {
	if (!ofs.is_open()) {
		return;
	}
	for (int i = 0;i < system.size;i++) {
		writeUserToFile(ofs, system.users[i]);
	}

}
