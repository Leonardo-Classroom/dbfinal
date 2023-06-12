#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <vector>  
#include <map>  
#include <string>  
#include <filesystem>
//#include <experimental/filesystem>
  
using namespace std;
  
// 定義學生結構體  
struct Student {  

    string student_id;  
    string course_id;  
    string course_name;  
    
};  
  
// 分割每一行的資料  
vector<string> split(string &s, char delimiter) {  
    
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delimiter)) {  
        tokens.push_back(token);  
    }  

    return tokens;  
}  
  
// 讀取CSV檔案並存儲學生資訊  
vector<Student> read_students_from_csv(string &file_path) {  

    vector<Student> students;  
    ifstream file(file_path);  
    string line;  

    getline(file, line); // 跳過標題行  
    while (getline(file, line)) {  
        vector<string> tokens = split(line, ',');  
        Student student{tokens[0], tokens[1], tokens[2]};  
        students.push_back(student);  
    }  

    return students;  
}  
  
// 將學生資訊分割為數個blocks並寫入對應的CSV檔案  
void write_students_to_blocks(vector<Student> &students, string &folderPath, int blockSize) {  

    filesystem::create_directory(folderPath);  

    int num_blocks=students.size()/blockSize+(students.size()%blockSize!=0?1:0);  
    for (int i=0;i<num_blocks;i++) {  

        ofstream block_file(folderPath+"/block"+to_string(i+1)+".csv");  
        block_file<<"student_id,course_id,course_name\n";  

        int startIndex=blockSize*i;  
        int endIndex=min((size_t)startIndex+blockSize, students.size()); 
        for (int j=startIndex;j<endIndex;j++) {  
            block_file<<students[j].student_id<<","<<students[j].course_id<<","<< students[j].course_name<<"\n";  
        }  
    }  
}  

  
int main() {  

    string input_file_path="DB_students_tc_ansi.csv";  
    string blocks_folderPath="blocks";  
 
    int blockSize=100;  
  
    auto students=read_students_from_csv(input_file_path);  
    write_students_to_blocks(students, blocks_folderPath, blockSize);  

    return 0;  
}  
