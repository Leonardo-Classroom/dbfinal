#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <vector>  
#include <map>  
#include <string>  
#include <filesystem>  

#include <fstream>  
#include <vector>  

  
using namespace std;
  
// 定義學生結構體  
struct Student {  
    string student_id;  
    string course_id;  
    string course_name;  
};  
  
// 分割每一行的資料  
vector<string> split(const string& s, char delimiter) {  
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delimiter)) {  
        tokens.push_back(token);  
    }  
    return tokens;  
}  
  
// 讀取CSV檔案並存儲學生資訊  
vector<Student> read_students_from_csv(const string& file_path) {  
    vector<Student> students;  
    ifstream file(file_path);  
    string line;  
    getline(file, line); // 跳過標題行  
    while (getline(file, line)) {  
        auto tokens = split(line, ',');  
        Student student{tokens[0], tokens[1], tokens[2]};  
        students.push_back(student);  
    }  
    return students;  
}  
  
// 將學生資訊分割為數個blocks並寫入對應的CSV檔案  
void write_students_to_blocks(const vector<Student>& students, const string& folder_path, int block_size) {  
    filesystem::create_directory(folder_path);  
    size_t num_blocks = students.size() / block_size + (students.size() % block_size != 0 ? 1 : 0);  
    for (size_t i = 0; i < num_blocks; ++i) {  
        ofstream block_file(folder_path + "/block" + to_string(i + 1) + ".csv");  
        block_file << "student_id,course_id,course_name\n";  
        size_t start_index = i * block_size;  
        size_t end_index = min(start_index + block_size, students.size());  
        for (size_t j = start_index; j < end_index; ++j) {  
            const Student& student = students[j];  
            block_file << student.student_id << "," << student.course_id << "," << student.course_name << "\n";  
        }  
    }  
}  
  
// 建立B+樹索引  
void create_balanced_tree_index(const vector<Student>& students, const string& index_file_path, int block_size) {  
    map<string, vector<int>> index_map;  // 創建一個映射表，用於存儲學號和所在塊數的關係
    for (size_t i = 0; i < students.size(); ++i) {  // 遍歷所有學生
        int block_number = i / block_size + 1;  // 計算該學生所在的塊數
        index_map[students[i].student_id].push_back(block_number);  // 將該學生的學號和所在塊數添加到映射表中
    }  
  
    ofstream index_file(index_file_path);  // 創建一個文件流，用於寫入索引文件
    index_file << "student_id,block_numbers\n";  
    for (const auto& [student_id, block_numbers] : index_map) {  // 遍歷所有映射表中的鍵值對
        index_file << student_id;  
        for (int block_number : block_numbers) {  // 遍歷該學生所在的所有塊數
            index_file << "," << block_number;  // 將塊數寫入文件中，並用逗號隔開
        }  
        index_file << "\n";  
    }  
}  

void create_bplus_tree_index(const vector<Student>& students, const string& index_file_path, int block_size){
    
}

 
  
// void create_balanced_tree_index(const std::vector<Student>& students, const std::string& index_file_path, int block_size) {  
//     btree_map<std::string, std::vector<int>> index_map;  // Create a btree_map to store the relationship between student IDs and block numbers.  
//     for (size_t i = 0; i < students.size(); ++i) {  // Iterate through all students.  
//         int block_number = i / block_size + 1;  // Calculate the block number the student is in.  
//         index_map[students[i].student_id].push_back(block_number);  // Add the student's ID and block number to the btree_map.  
//     }  
  
//     std::ofstream index_file(index_file_path);  // Create a file stream to write the index file.  
//     index_file << "student_id,block_numbers\n";  
//     for (const auto& [student_id, block_numbers] : index_map) {  // Iterate through all key-value pairs in the btree_map.  
//         index_file << student_id;  
//         for (int block_number : block_numbers) {  // Iterate through all block numbers the student is in.  
//             index_file << "," << block_number;  // Write the block number to the file, separated by commas.  
//         }  
//         index_file << "\n";  
//     }  
// }  

  
int main() {  
    const string input_file_path = "DB_students_tc_utf8.csv";  
    const string blocks_folder_path = "blocks";  
    const string index_file_path = "balancedTreeIndex_student_id.csv";  
    const int block_size = 100;  
  
    auto students = read_students_from_csv(input_file_path);  
    write_students_to_blocks(students, blocks_folder_path, block_size);  
    create_balanced_tree_index(students, index_file_path, block_size);  
  
    return 0;  
}  
