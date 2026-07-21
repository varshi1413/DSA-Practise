#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int k=n;
    for(int i=1;i<=n;i++){
        int q=i;
        for(int j=1;j<=n;j++){
            if(j<k){
                cout<<" ";
            }
            else if(j>=k){
                cout<<q;
                q--;
            }
        }
        k--;
        cout<<endl;
    }
}