#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>  
  
using namespace std;

// 將CSV檔案讀取為一個二維向量  
vector<vector<string>> readCSV(const string& filePath) {  
    vector<vector<string>> data;  
    ifstream file(filePath);  
    string line;  
  
    while (getline(file, line)) {  
        vector<string> row;  
        istringstream ss(line);  
        string cell;  
  
        while (getline(ss, cell, ',')) {  
            row.push_back(cell);  
        }  
  
        data.push_back(row);  
    }  
  
    return data;  
}  
  
// 在索引中查找學號並返回相應的block編號  
vector<int> findBlocks(const vector<vector<string>>& index, const string& student_id) {  
    vector<int> blocks;  
  
    for (const auto& row : index) {  
        if (row[0] == student_id) {  
            for (size_t i = 1; i < row.size(); ++i) {  
                blocks.push_back(stoi(row[i]));  
            }  
            break;  
        }  
    }  
  
    return blocks;  
}  
  
// 在指定的block檔案中查找學號並打印資料  
void printStudentData(const string& blockFile, const string& student_id) {  

    cout<<"--------------------------------"<<endl;
    auto data = readCSV(blockFile);  
  
    cout << blockFile << ":\n";  
    for (const auto& row : data) {  
        if (row[0] == student_id) {  
            cout << row[0] << ',' << row[1] << ',' << row[2] << '\n';  
        }  
    }  
}  
  
int main() {  
    string student_id;  
    cout << "請輸入學號: ";  
    cin >> student_id;  
  
    auto index = readCSV("balancedTreeIndex_student_id.csv");  
    auto blocks = findBlocks(index, student_id);  
  
    cout << "student_id,course_id,course_name\n";  
    for (int block : blocks) {  
        string blockFile = "blocks/block" + to_string(block) + ".csv";  
        printStudentData(blockFile, student_id);  
    }  
  
    return 0;  
}  
