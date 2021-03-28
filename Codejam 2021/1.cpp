
#include<iostream>
#include <algorithm>
using namespace std;
void sampleCase()
{
    int i,j,limit,fakeindex,score=0,arr[limit];
    cin>>limit;

    for(int i=0;i<limit;i++) cin>>arr[i];

    for(i=0;i<limit-1;i++){
        int fakeindex = i;
        for(j=i+1;j<limit;j++){
            if(arr[fakeindex]>arr[j])
                fakeindex=j;
        }
        score = score+(fakeindex-i)+1;
        reverse(arr+i,arr+fakeindex+1);
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
