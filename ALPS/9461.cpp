//파도반 수열

#include <iostream>

using namespace std;

long long arr[101] = {0};

int main() {
    int t;
    cin>>t;
    int n;
    for(int i = 0; i<100; i++)
    {
        switch(i)
        {
            case 0:
                arr[0] = 1;
                break;
            case 1:
                arr[1] = 1;
                break;
            case 2:
                arr[2] = 1;
                break;
            case 3:
                arr[3] = 2;
                break;
            case 4:
                arr[4] = 2;
        }
        if(i-5>=0)
        {
            arr[i] = arr[i-1] + arr[i-5];
        }
    }
    
    for(int i = 0; i<t;i++){
        cin>>n;
        cout<<arr[n-1]<<endl;
    }
}
