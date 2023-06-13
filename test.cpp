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

    return 0;
}
