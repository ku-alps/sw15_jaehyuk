#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    //int num[10] = {6,2,5,5,4,5,6,3,7,6};
    //1,4,5,7,9
    //2, , ,3,
    vector<int> arr;
    int N;
    cin>>N;
    int temp = N;
    if(temp%2 == 1){
        arr.push_back(7);
        temp -= 3;
    }
    while(temp>=2){
        arr.push_back(1);
        temp = temp - 2;
    }
    
    for(int i = 0; i<(int)arr.size(); i++){
        cout<<arr[i];
    }
}
