//#include <fstream>
//#include <iostream>
//#include <sstream>
//
//namespace ConstsFirst {
//    constexpr char FIRST_FILE[] = "fst.txt";
//    constexpr char SECOND_FILE[] = "snd.txt";
//    constexpr char THIRD_FILE[] = "third.txt";
//    constexpr int MATRIX_MAX = 10;
//    constexpr char SEPARATOR_COL = ',';
//    constexpr char SEPARATOR_ROW = '|';
//}
//
//using namespace ConstsFirst;
//
//typedef int Column[ConstsFirst::MATRIX_MAX];
//
//struct Row {
//    Column columns;
//};
//
//struct Matrix {
//    Row rows[ConstsFirst::MATRIX_MAX];
//    int rowCount;
//    int colCount;
//};
//
//unsigned charCountInFile(const char* FILE_NAME,char ch) {
//    std::ifstream ifs(FILE_NAME);
//    if (!ifs.is_open()) {
//        std::cout << "error from charCountInFile" << std::endl;
//        return 0;
//    }
//
//    unsigned count = 0;
//    while (true) {
//        char current = ifs.get();
//        if (ifs.eof()) {
//            break;
//        }
//        if (current == ch) {
//            count++;
//        }
//    }
//    return count;
//}
//
//unsigned charCountUntilChar(const char* FILE_NAME, char ch1, char ch2) {
//    std::ifstream ifs(FILE_NAME);
//    if (!ifs.is_open()) {
//        std::cout << "error from charCountUntilChar" << std::endl;
//        return 0;
//    }
//
//    unsigned count = 0;
//    while (true) {
//        char current = ifs.get();
//        if (ifs.eof()) {
//            break;
//        }
//        if (current == ch2) {
//            return count+1;
//            break;
//        }
//        if (current == ch1) {
//            count++;
//        }
//    }
//    return count+1;
//}
//
//int fromCharToInt(const char* num) {
//        return *num - '0';
//    }
//
//void fillMatrix(Matrix& matrix, int rowIndex, int colIndex, const char* num) {
//        matrix.rows[rowIndex].columns[colIndex] = fromCharToInt(num);
//    }
//
//Matrix readMatrix(std::ifstream& ifs) {
//    if (!ifs.is_open()) {
//        return;
//    }
//    Matrix matrix;
//        int rowIndex = 0;
//        
//        char line[ConstsFirst::MATRIX_MAX];
//        while (ifs.getline(line, ConstsFirst::MATRIX_MAX, ConstsFirst::SEPARATOR_ROW))
//        {
//            int colIndex = 0;
//            
//            std::stringstream rowStream(line);
//            char row[ConstsFirst::MATRIX_MAX];
//            while (rowStream.getline(row, ConstsFirst::MATRIX_MAX, ConstsFirst::SEPARATOR_COL)) {
//                
//    
//                fillMatrix(matrix, rowIndex, colIndex, row);
//                colIndex++;
//            }
//            
//            rowIndex++;
//            
//        }
//       matrix.rowCount = rowIndex;
//       matrix.colCount = charCountUntilChar(FIRST_FILE,SEPARATOR_COL,SEPARATOR_ROW);
//       
//       return matrix;
//}
//
//Matrix matrixMultiplication(const Matrix& matrix1, const Matrix& matrix2) {
//        Matrix result;
//        result.rowCount = matrix1.rowCount;
//        result.colCount = matrix2.colCount;
//        for (int i = 0;i < matrix1.rowCount;i++) {
//            for (int j = 0;j < matrix2.colCount;j++) {
//                result.rows[i].columns[j] = 0;
//                for (int k = 0;k < matrix2.rowCount;k++) {
//                    result.rows[i].columns[j] += matrix1.rows[i].columns[k] * matrix2.rows[k].columns[j];
//                }
//            }
//        }
//        return result;
//}
//
//void writeMatrixInFile(const Matrix& matrix, const char* THIRD_FILE) {
//    std::ofstream ofs(THIRD_FILE);
//    if (!ofs.is_open()) {
//        std::cout << "error from writing" << std::endl;
//        return;
//    }
//    for (int i = 0;i < matrix.rowCount-1;i++) {
//        for (int j = 0;j < matrix.colCount-1;j++) {
//            
//            ofs << matrix.rows[i].columns[j] << ',';
//        }
//        
//        ofs <<matrix.rows[i].columns[matrix.colCount-1]<<'|';
//    }
//    for (int j = 0;j < matrix.colCount-1;j++) {
//        ofs << matrix.rows[matrix.rowCount - 1].columns[j] << ',';
//    }
//    ofs<< matrix.rows[matrix.rowCount - 1].columns[matrix.colCount-1] << std::endl;
//}
//int main() {
//    std::ifstream ifs1(ConstsFirst::FIRST_FILE);
//        
//        Matrix matrix1;
//        matrix1=readMatrix(ifs1);
//    
//        std::ifstream ifs2(ConstsFirst::SECOND_FILE);
//        Matrix matrix2;
//        matrix2 = readMatrix(ifs2);
//
//        Matrix result = matrixMultiplication(matrix1, matrix2);
//        writeMatrixInFile(result, THIRD_FILE);
//
//}