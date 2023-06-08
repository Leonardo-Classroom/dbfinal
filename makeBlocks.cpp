#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <vector>  
#include <map>  
#include <string>  
#include <filesystem>  
  
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

  
int main() {  
    const string input_file_path = "DB_students_tc_utf8.csv";  
    const string blocks_folder_path = "blocks";  
    const string index_file_path = "balancedTreeIndex_student_id.csv";  
    const int block_size = 100;  
  
    auto students = read_students_from_csv(input_file_path);  
    write_students_to_blocks(students, blocks_folder_path, block_size);  

    return 0;  
}  
