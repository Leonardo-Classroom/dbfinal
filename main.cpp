#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"
#include "mode1.cpp"
#include "mode2.cpp"
#include "mode3.cpp"

using namespace std;

// 定義學生結構體  
struct Student {  
    string studentID;  
    string courseID;  
    string courseName;  
};

vector<string> split(const string& s, char delimiter) {  
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delimiter)) {  
        tokens.push_back(token);  
    }  
    return tokens;  
}

int main(int argc, char const *argv[]){ 

    // RedBlackTree *rbt = new RedBlackTree();

    // vector<string> data[11];
    // data[0].push_back("1");
    // data[0].push_back("999");
    // data[0].push_back("8888");

    // data[1].push_back("2");
    // data[1].push_back("2234");
    // data[1].push_back("2dfs");

    // data[2].push_back("3");
    // data[2].push_back("3sdf");
    // data[2].push_back("3324");

    // data[3].push_back("4");
    // data[3].push_back("4sdff");
    // data[3].push_back("4dsfsf");

    // data[4].push_back("5");
    // data[4].push_back("5sdf");
    // data[4].push_back("5sdf");

    // data[5].push_back("6");
    // data[5].push_back("6sdf");
    // data[5].push_back("6erw");

    // data[6].push_back("7");
    // data[6].push_back("7erw");
    // data[6].push_back("7wrwer");

    // data[7].push_back("8");
    // data[7].push_back("8wrwer");
    // data[7].push_back("8werwer");

    // data[8].push_back("9");
    // data[8].push_back("9werwr");
    // data[8].push_back("9werr");

    // data[9].push_back("10");
    // data[9].push_back("999");
    // data[9].push_back("888");

    // data[10].push_back("10");
    // data[10].push_back("111");
    // data[10].push_back("222");


    // rbt->insert(data[0]);
    // rbt->insert(data[1]);
    // rbt->insert(data[2]);
    // rbt->insert(data[3]);
    // rbt->insert(data[4]);
    // rbt->insert(data[5]);
    // rbt->insert(data[6]);
    // rbt->insert(data[7]);
    // rbt->insert(data[8]);
    // rbt->insert(data[9]);
    // rbt->insert(data[10]);

    // rbt->find("10");

    // cout<<endl;
    // rbt->inorder();

    // system("chcp 65001");

    RedBlackTree *indexStudentID = new RedBlackTree();
    RedBlackTree *indexCourseID = new RedBlackTree();
    RedBlackTree *indexCourseName = new RedBlackTree();
 
    ifstream file("DB_students_tc_ansi.csv");  
    string line;  
    getline(file, line); // 跳過標題行  
    int block=0;
    int i=0;
    while (getline(file, line)) {  

        i++;
        block=i/100+1;

        if(i%4654==1){
            system("cls");
            cout<<"indexing "<<i/4654+1<<"%"<<endl;
        }

        vector<string> tokens = split(line, ',');  
        Student student{tokens[0], tokens[1], tokens[2]};  

        vector<string> blockStudentID;
        blockStudentID.push_back(student.studentID);
        blockStudentID.push_back(to_string(block));
        indexStudentID->insert(blockStudentID);

        vector<string> blockCourseID;
        blockCourseID.push_back(student.courseID);
        blockCourseID.push_back(to_string(block));
        indexCourseID->insert(blockCourseID);

        vector<string> blockCourseName;
        blockCourseName.push_back(student.courseName);
        blockCourseName.push_back(to_string(block));
        indexCourseName->insert(blockCourseName);

        // indexCourseName->inorder();
        // system("pause");
        
    }  

    system("cls");
    cout<<"DONE!!"<<endl;
    system("pause");

    
    string mode;
    while(true){
        vector<string> result;

        system("cls");
        cout<<"==============="<<endl;
        cout<<" 1) studentID"<<endl;
        cout<<" 2) courseID"<<endl;
        cout<<" 3) courseName"<<endl;
        cout<<" 4) exit"<<endl;
        cout<<"==============="<<endl;
        cout<<"mode> ";
        cin>>mode;
        if(mode=="1"){
            string studentID;
            cout<<"studentID> ";
            cin>>studentID;
            result=indexStudentID->find(studentID);

            mode1(result);

        }else if(mode=="2"){
            string courseID;
            cout<<"courseID> ";
            cin>>courseID;
            result=indexCourseID->find(courseID);

            mode2(result);

        }else if(mode=="3"){
            string courseName;
            cout<<"courseName> ";
            cin>>courseName;
            

            vector<string> test;
            test=indexCourseName->findKeyword(courseName);
            for(int x=0;x<test.size();x++){
                cout<<test[x]<<" ";
            }
            cout<<endl;
            system("pause");


            result=indexCourseName->find(courseName);

            mode3(result);

        }else if(mode=="4"){
            break;
        }

        cout<<endl;
        system("pause");
    }
    

    
    return 0;
}
