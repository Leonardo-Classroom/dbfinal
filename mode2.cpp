#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"

using namespace std;

vector<string> ssplit(const string& s, char delimiter) {  
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delimiter)) {  
        tokens.push_back(token);  
    }  
    return tokens;  
}

void mode2(vector<string> result){

    cout<<"mode 2:"<<endl;

    if(result.size()){
        cout<<"result:"<<endl;
        cout<<result[0]<<"> ";
        for(int i=1;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        cout<<"---------------------->"<<endl;

        //寫這邊，result[0]是課號，result[1]...是block，代表在result[0]哪些block中有資料
        //去這些block中找資料，把該課號的課名跟學生都印出來

        // int isDataExist=0;
        // string courseId;


        int count=0;
        bool isStart=false;

        for(int i=1; i<result.size(); i++)
        {
            // if(courseId==result[0] && !isDataExist)
                // cout<<
            // cout<<"block"+result[i]+":-------"<<endl;

            string block_str="block"+result[i]+".csv";
            ifstream file("blocks/"+block_str);
            string line;
            getline(file, line);
            while(getline(file, line)){
                vector<string> tokens=ssplit(line, ',');
                // if don't use ssplit
                // string token;
                // istringstream tokenstream(line);
                // while(getline(tokenstream, token, ',')){
                //     tokens.push_back(token);
                //     // cout<<token<<", ";
                //     // system("pause");
                // }

                if(tokens[1] == result[0]){

                    if(!isStart){
                        cout<<"course_ID\tcourse_Name\n ["<<tokens[1]<<"] \t"<<tokens[2]<<endl;
                        isStart=true;
                        cout<<"\nstudent_ID\tblock_Num\n"<<endl;
                    }

                    // isDataExist = 1;
                    cout<<tokens[0]<<"\t[block "+result[i]+"]"<<endl;
                    // courseId = token[1];
                }
                // system("pause");
            }
            // system("pause");
        }

    }
}