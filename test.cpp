#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    
    string s="你好";
    string s2="你好123";

    cout<<(s<s2)<<endl;
    cout<<(s2<s)<<endl;
    cout<<(s==s2)<<endl;

    cout<<s<<endl;
    cout<<s2<<endl;


    if (s2.find(s) != string::npos) {
        cout<<"Found"<<endl;
    } 
    int sort_num[10]={12,34,543,123,645,123,6435,3,0,1000};
    for(int i=0;i<10-1;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            if(sort_num[j]>sort_num[j+1])
            {
                int temp;
                temp = sort_num[j];
                sort_num[j] = sort_num[j+1];
                sort_num[j+1]=temp;
            }
        }
    }

    for(int i=0;i<10;i++)
    {
        cout<<sort_num[i]<<" ";
    }
    return 0;
}