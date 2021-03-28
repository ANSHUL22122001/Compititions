#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class question
{
public:
    bool cond=true;
    int solve(int arr[], int limit, int score)
    {
        int scores=0;
        for(int i=0;i<limit-1;i++){
            int fakeindex = i;
            for(int j=i+1;j<limit;j++){
                if(arr[fakeindex]>arr[j])
                    fakeindex=j;
            }
            scores = scores+(fakeindex-i)+1;
            reverse(arr+i,arr+fakeindex+1);
        }
        if(score == scores){
            return 1;
        }
        return 0;
    }
    void print(int *num, int n, int score)
    {
        int i;
        int arr[n];
        for ( i = 0 ; i < n ; i++){
            arr[i]=num[i];
        }
        int check = solve(arr, n, score);
        if(check && cond){
            cond=false;
            for ( i = 0 ; i < n ; i++)
                printf("%d ", num[i]);
        }

    }



};

void sampleCase()
{
    int i,j,limit,score,sum=-1;
    cin>>limit>>score;
    int arr[limit];
    for(int i=0;i<limit;i++) arr[i]=i+1;

    if(score < limit-1){
        cout<<"IMPOSSIBLE";
        return;
    }
    int check=accumulate(arr , arr+limit , sum);
    if(score > check){
        cout<<"IMPOSSIBLE";
        return;
    }
    question qe;
    while(true){
        random_shuffle(arr,arr+limit);
        qe.print(arr,limit,score);
        for ( i = 0 ; i < limit ; i++)
            printf("%d ", arr[i]);
            cout<<endl;
        if(!qe.cond){
            break;
        }
    }
    if(qe.cond){
        cout<<"IMPOSSIBLE";
    }
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
