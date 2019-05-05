//히스토그램에서 가장 큰 직사각형
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

void init(vector<int> &arr,vector<int> &tree, int node,int start,int end){
    if(start == end){
        tree[node] = start; //리프에 인덱스 저장
    }
    else{
        init(arr,tree,node*2,start,(start+end)/2);
        init(arr,tree,node*2+1,(start+end)/2+1,end);
        
        //부모 노드는 자식 노드(인덱스 값) 중에 높이가 작은 사각형의 인덱스 가짐
        if(arr[tree[node*2]]<=arr[tree[node*2+1]])
            tree[node] = tree[node*2];
        else
            tree[node] = tree[node*2+1];
    }
}
int update(vector<int> &arr, vector<int> & tree,int node,int start,int end,int i, int j){
    //i,j는 갱신하려는 구간
    if(i>end || j<start)
        return -1;
    //i와 j사이에 start,end
    if(i<=start && end<=j)
        return tree[node];
    
    int m1 = update(arr,tree,2*node,start,(start+end)/2,i,j);
    int m2 = update(arr,tree,2*node+1,(start+end)/2+1,end,i,j);
    
    if(m1 == -1){   //좌측 탐색 구간에 없음
        return m2;
    }else if(m2 == -1){ //우측 탐색 구간에 없음
        return m1;
    }
    else {  //탐색 구간에 속함
        if(arr[m1] <= arr[m2])
            return m1;
        else
            return m2;
    }
}
long long largest(vector<int> &arr, vector<int> &tree,int start,int end){
    int n = (int)arr.size();
    
    int m = update(arr,tree,1,0,n-1,start,end);
    //가장작은 사각형의 높이 (인덱스)
    
    long long area = (long long)(end-start+1)*(long long)arr[m];
    
    //가장 작은 사각형 왼쪽에 있는 사각형
    if(start<=m-1){
        long long temp = largest(arr,tree,start,m-1);
        if(area<temp){
            area = temp;
        }
    }
    //가장 작은 사각형 오른쪽에 있는 사각형
    if(m+1<=end){
        long long temp = largest(arr,tree,m+1,end);
        if(area<temp){
            area = temp;
        }
    }
    return area;
}

int main(){
    
    int n = 1;
    int temp = 0;
    
    while(true){

        cin>>n;
        if(n == 0)
            break;
        
        vector<int> arr(n);
        
        for(int i = 0; i<n;i++){
            cin>>temp;
            arr[i] = temp;
        }
        int height = ceil(log2(n));
        int treesize = pow(2,height+1)-1; 
        
        vector<int> tree(treesize);
        
        init(arr,tree,1,0,n-1);
        //cout<<height<<endl;
        cout<<largest(arr,tree, 0, n-1)<<endl;
    }
}
