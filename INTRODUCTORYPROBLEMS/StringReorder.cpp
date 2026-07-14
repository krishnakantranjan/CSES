#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;

    map<char, int>mp;

    for(char ch : s){
        mp[ch]++;
    }

    
}