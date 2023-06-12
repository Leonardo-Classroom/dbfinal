#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"

using namespace std;

void mode1(vector<string> result){

    cout<<"mode 1: "<<endl;

    if(result.size()){
        cout<<"result:"<<endl;
        cout<<result[0]<<"> ";
        for(int i=1;i<result.size();i++){
			cout<<result[i]<<" ";
        }
        cout<<endl;
        cout<<"==============="<<endl;

        //Result[0] is StudentId, result[1]... are blocks, represent there is data in which block in result[0]
        //Go to these block to find information, and print out the classId
    }
}
