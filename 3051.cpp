//count of triangle
//
//cut the line by crossing one
//find out all case of triangles to be able to make
//except the cases that have same slope
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;

vector<int> line;
int cnt = 0;
bool isParal(int x1,int y1,int x2,int y2,int a1,int b1,int a2,int b2){
    if((x1==x2 && a1==a2) && a1 == x1){//correct
        if(max(y1,y2)<min(b1,b2)||max(b1,b2)<min(y1,y2)){
            return false;
        }
        else if(max(y1,y2)==min(b1,b2)||max(b1,b2)==min(y1,y2)){
            //line.push_back()
        }
        return true;
    }
    else if((x1==x2 && a1==a2) && a1 != x1){//parallel
        return false;
    }
    if(abs(y1-y2)/abs(x1-x2) == abs(b1-b2)/abs(a1-a2)){
        return true;
    }
    return false;
}
bool isCross(int x1,int y1,int x2,int y2,int a1,int b1,int a2,int b2){

}
int main(){
    cin>>N;
    
    int X1,Y1,X2,Y2;
    for(int i = 0; i<N; i++){
        cin>>X1>>Y1>>X2>>Y2;
        
        for(int j = 0; j<cnt; j++){
            
        }
        
    }
}