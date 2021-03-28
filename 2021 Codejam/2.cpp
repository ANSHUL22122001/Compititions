#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void sampleCase()
{
    int X,Y,score=0;
    string test,newtest="";
    cin>>X>>Y>>test;
    for(int i=1;i<test.length();i++){
        if(test[i-1] == '?' && test[i] != '?'){
            int j=i-1;
            for(;j>=0;j--){
                test[j]=test[j+1];
                if(test[j-1] != '?') break;
            }
        }
    }
    for(int i=0;i<test.length()-1;i++){
        if(test[i+1] == '?' && test[i] != '?'){
            int j=i+1;
            for(;j<test.length();j++){
                test[j]=test[j-1];
                if(test[j+1] != '?') break;
            }
        }
    }
    for(int i=0;i<test.length()-1;i++){
        if(test[i] == 'C' && test[i+1] == 'J') score=score+X;
        else if(test[i]=='J' && test[i+1]=='C') score=score+Y;
    }
    cout<<score;

}
int main()
{
    int i,testCase;
    cin>>testCase;
    for(i=0;i<testCase;i++){
        cout<<"Case #"<<i+1<<": ";
        sampleCase();
        cout<<endl;
    }
    return 0;
}

