#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;



long long init(vector<long long> &arr, vector<long long> &tree, int node, int start,int end){
    if(start == end){//리프이면
        return tree[node] = arr[start];
    }
    else{
        return tree[node] = init(arr,tree,node*2,start,(start+end)/2)
        +init(arr,tree,node*2+1,(start+end)/2+1,end);
    }
}
long long sum(vector<long long>&tree, int node, int start, int end, int left,int right){
    if(left>end||right<start)  //전체 노드 구간 밖의 구간
        return 0;
    
    if(left<=start && end<=right)   //전체 노드 구간이 해당 구간에 속할때
        return tree[node];
    
    return sum(tree,node*2,start,(end+start)/2,left,right)  //왼쪽 자식 오른쪽 자식 재탐색
    + sum(tree, node*2+1,(start+end)/2+1, end,left,right);
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index<start || index > end) //범위 밖의 인덱스
        return;
    
    tree[node] = tree[node] +diff;  //범위 안에 들면 일단 더해주기 (diff - 변동 값)
    
    if(start != end){   //리프가 아니면 반복
        update(tree,node*2,start,(start+end)/2,index,diff);
        update(tree,node*2+1,(start+end)/2+1,end,index,diff);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<long long> arr(n);
    int height = (int)ceil(log2(n));
    int tree_size= (pow(2,height+1));
    vector<long long> tree(tree_size);
    //트리 크기 정하는 부분 (4*n)
    
    int input;
    int a;
    
    m+=k;
    for(long long i = 0; i<n; i++){
        cin>>input;
        arr[i] = input;
    }
    init(arr,tree,1,0,n-1); //arr배열 원소로 트리 생성
    while(m--){
        cin>>a;
        if(a == 1){//b번째수를 c로
            int b;
            long long c;
            cin>>b>>c;
            b = b-1; //배열 인덱스이므로 -1
            long long diff = c-arr[b]; //b번째 수와 c와의 차이
            arr[b] = c; //b번째 수를 c로
            update(tree, 1, 0, n-1, b, diff); //거치는 모든 노드에 대해 차이만큼 더하기
        }
        else if(a == 2)//b번째수부터c번째수까지의 합
        {
            int b,c;
            cin>>b>>c;
            cout<<sum(tree,1,0,n-1,b-1,c-1)<<endl;
        }
    }
}
