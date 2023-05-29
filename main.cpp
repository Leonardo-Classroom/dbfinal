#include <iostream>  
#include <vector>  
#include <fstream>  
#include <sstream>  
#include <map>  
#include <algorithm>  
#include "balanced_tree.h"  
  
using namespace std;  
  
// 分割資料成不同的block  
void split_data(const string& input_file, int block_size) {  
    ifstream file(input_file);  
    string line;  
    int block_count = 0;  
    int line_count = 0;  
    ofstream output;  
  
    while (getline(file, line)) {  
        if (line_count % block_size == 0) {  
            if (output.is_open()) {  
                output.close();  
            }  
            block_count++;  
            output.open("block" + to_string(block_count) + ".csv");  
        }  
        output << line << endl;  
        line_count++;  
    }  
  
    if (output.is_open()) {  
        output.close();  
    }  
}  
  
// 讀取分割後的block  
vector<vector<string>> read_block(const string& block_file) {  
    vector<vector<string>> data;  
    ifstream file(block_file);  
    string line;  
  
    while (getline(file, line)) {  
        stringstream ss(line);  
        string token;  
        vector<string> row;  
  
        while (getline(ss, token, ',')) {  
            row.push_back(token);  
        }  
        data.push_back(row);  
    }  
    return data;  
}  
  
// 建立Balanced Tree索引  
BalancedTreeIndex build_index(const string& input_file) {  
    BalancedTreeIndex index;  
    ifstream file(input_file);  
    string line;  
  
    while (getline(file, line)) {  
        stringstream ss(line);  
        string token;  
        vector<string> row;  
  
        while (getline(ss, token, ',')) {  
            row.push_back(token);  
        }  
        index.insert(row[1], row[0]);  
    }  
    return index;  
}  
  
int main() {  
    // 讀取原始資料檔案(DB_students.csv)  
    string input_file = "DB_students_tc_utf8.csv";  
    int block_size = 100;  
  
    // 將資料分割成不同的block，並將這些block存儲到不同的檔案  
    split_data(input_file, block_size);  
  
    // 建立Balanced Tree索引  
    BalancedTreeIndex index = build_index(input_file);  
  
    // 提供查詢功能  
    string query;  
    cout << "請輸入查詢學號或課號: ";  
    cin >> query;  
  
    vector<string> results = index.search(query);  
    for (const string& result : results) {  
        cout << "查詢結果: " << result << endl;  
    }  
  
    return 0;  
}  
