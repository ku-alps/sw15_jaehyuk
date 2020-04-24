#include<iostream>

using namespace std;

int _max[3];
int _min[3];
int temp_max[3];
int temp_min[3];

int main(){
    int n;
    cin>>n;
    
    int num;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin>>num;
            
            if(i == 0){
                _min[j] = num;
                _max[j] = num;
            }
            else{
                switch(j){
                    case 0:
                        temp_min[j] = num+min(_min[j],_min[j+1]);
                        temp_max[j] = num+max(_max[j],_max[j+1]);
                        break;
                    case 2:
                        temp_min[j] = num+min(_min[j],_min[j-1]);
                        temp_max[j] = num+max(_max[j],_max[j-1]);
                        
                        for(int k = 0;k<3;k++){
                            _max[k] = temp_max[k];
                            _min[k] = temp_min[k];
                        }
                        break;
                    default:
                        temp_min[j] = num+min(min(_min[j-1],_min[j]),_min[j+1]);
                        temp_max[j] = num+max(max(_max[j-1],_max[j]),_max[j+1]);
                        break;
                }
            }
        }
    }
    cout<<max(_max[0],max(_max[1],_max[2]))<<" "<<
        min(_min[0],min(_min[1],_min[2]))<<endl;
}
