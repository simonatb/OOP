//#include <fstream>
//#include <iostream>
//
////1
//constexpr char FILE_NAME[] = "results.txt";
//
//void getDiffFile() {
//    std::ifstream file(FILE_NAME);
//    if (!file.is_open()) {
//        std::cout << "Error!" << std::endl;
//        return;
//    }
//
//    int sum, mult;
//    file >> sum >> mult;
//    std::cout << (sum - mult)<<std::endl;
//    file.close();
//
//}
//
//int main()
//{
//    std::ofstream file(FILE_NAME);
//    if (!file.is_open()) {
//        std::cout << "Error!" << std::endl;
//        return -1;
//    }
//
//    int x, y, z;
//    std::cin >> x >> y >> z;
//    int sum = x + y + z;
//    int mult = x * y * z;
//    file << sum << " " << mult;
//    file.close();
//    getDiffFile();
//    
//}
//
////2