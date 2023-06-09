#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"

using namespace std;

vector<string> sssplit(const string& s, char delim) {  
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delim)) {  
        tokens.push_back(token);  
    }  
    return tokens;  
}

void mode1(vector<string> result){

    cout<<"mode 1: "<<endl; 

    if(result.size()){ 
        cout<<"result:"<<endl;
        cout<<result[0]<<"> "; //print the input of studentId
        for(int i=1;i<result.size();i++){
			cout<<result[i]<<" "; //print all of information (class id) which have been found
        }
        cout<<endl;
        cout<<"==============="<<endl;
		
        //Result[0] is StudentId, result[1]... are blocks, represent there is data in which block in result[0]
        //Go to these block to find information, and print out the classId
        
        int count=0;
        bool Start=false;

        for(int i=1; i<result.size(); i++)
        {
            string block_str="block"+result[i]+".csv";
            ifstream file("blocks/"+block_str);
            string line;
            getline(file, line);
            while(getline(file, line)){
                vector<string> tokens=sssplit(line, ',');
                if(tokens[0] == result[0]){
                    if(!Start){
                        cout<<"student_ID\n ["<<tokens[0]<<"]"<<endl;
                        Start=true;
                        cout<<"\nblock_Num\tcourse_ID\tcourse_Name\n"<<endl;
                    }
                    cout<<"[block "<< result[i]<<"]"<<"\t"<<tokens[1]<<"\t\t"<< tokens[2]<< endl;
                }
            }
        }
        cout<<"==============="<<endl;
    }
}
