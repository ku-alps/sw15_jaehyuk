//가장 가까운 두 점 line sweeping

#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int dist;

void swap(pair<int,int> *a, pair<int,int> *b){
    pair<int,int> *temp;
    temp = a;
    a = b;
    b = temp;
}

int partitionX(pair<int,int> list[], int left, int right){
    int pivot;
    int low, high;
    
    low = left;
    high = right + 1;
    pivot = list[left].first;
    
    do{
        do {
            low++;
        } while (low<=right && list[low].first<pivot);
        
        do {
            high--;
        } while (high>=left && list[high].first>pivot);
        
        if(low<high){
            swap(list[low].first, list[high].first);
        }
    } while (low<high);
    
    swap(list[left], list[high]);
    
    return high;
}

int partitionY(pair<int,int> list[], int left, int right){
    int pivot;
    int low, high;
    
    low = left;
    high = right + 1;
    pivot = list[left].second;
    
    do{
        do {
            low++;
        } while (low<=right && list[low].second<pivot);
        
        do {
            high--;
        } while (high>=left && list[high].second>pivot);
        
        if(low<high){
            swap(list[low].second, list[high].second);
        }
    } while (low<high);
    
    swap(list[left], list[high]);
    
    return high;
}

void quick_sortX(pair<int,int> list[], int left, int right){
    
    if(left<right){
        int q = partitionX(list, left, right);
        
        quick_sortX(list, left, q-1);
        quick_sortX(list, q+1, right);
    }
    
}
void quick_sortY(pair<int,int> list[], int left, int right){
    
    if(left<right){
        int q = partitionY(list, left, right);
        
        quick_sortY(list, left, q-1);
        quick_sortY(list, q+1, right);
    }
    
}
void CP(pair<int,int> arr[],set<pair<int,int>> point,int start,int n){
    start = 0;
    for(int i = 2; i<n; i++){
        pair<int,int> curpoint = arr[i];
        
        while(start<i){
            pair<int,int> tarpoint = arr[start];
            //x좌표 비교
            int x = curpoint.first - tarpoint.first;
            if(x*x>dist){
                point.erase(tarpoint);
                start++;
            }
            else
                break;
        }
        
        int tempdist = (int)sqrt((double)dist)+1;
    
        auto lower = point.lower_bound(make_pair(-100000,curpoint.second-tempdist));
        auto upper = point.upper_bound(make_pair(100000,curpoint.second+tempdist));
        for(auto it = lower; it!= upper; it++)
        {
            int d = pow(curpoint.second-it->first,2)+pow(curpoint.first-it->second,2);
            if(d<dist)
                dist = d;
        }
        point.insert(make_pair(curpoint.second,curpoint.first));
    }
    cout<<dist<<endl;
}
int main(){
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    //x좌표 sort
    quick_sortX(arr,0,n-1);
    /*
    for(int i = 0; i<n;i++){
        cout<<arr[i].first<<","<<arr[i].second<<endl;
    }
    */
    //dist갱신
    set<pair<int,int>> point;
    point.insert(make_pair(arr[0].second,arr[0].first));
    point.insert(make_pair(arr[1].second,arr[1].first));
    
    dist = pow(abs(arr[0].first-arr[1].first),2)+pow(abs(arr[0].second-arr[1].second),2);
    
    //n개의 점 거치면서 좌측 최대 6개 점 확인(증명)
    CP(arr,point,2,n);
    
}
