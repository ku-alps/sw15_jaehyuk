#include<bits/stdc++.h>

#define XMAX 10000000
#define YMAX 10000000

using namespace std;

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};

struct bac{
    int x,y,d;
    int dx,dy;
    int cnt;
    int flag;
};
struct obj{
    int t;
    short b1;
    short b2;
};
bool cmp(obj& o1, obj& o2){
    if(o1.t<o2.t)
        return true;
    return false;
}

bac arr[5001];
obj vec2[10000001];
int kx = 0;
int maxcnt = 0;
int mintime = 10000000;


int meet(int idx1, int idx2){
    bac b1 = arr[idx1];
    bac b2 = arr[idx2];
    int d1 = max(abs(b1.x-b2.x), abs(b1.y-b2.y));
    int d2 = max(abs(b1.x+b1.dx-b2.x-b2.dx),
                    abs(b1.y+b1.dy-b2.y-b2.dy));

    if ( d2 >= d1 || d1%(d1-d2) != 0 ) 
        return -1;
        
    int t = d1 / (d1-d2);
    if ( b1.x + t*b1.dx == b2.x + t*b2.dx &&
        b1.y + t*b1.dy == b2.y + t*b2.dy ) {
        obj temp;
        temp.b1 = idx1;
        temp.b2 = idx2;
        temp.t = t;
        vec2[kx] = temp;
        kx++;
    }
    return -1;
}


int slope(bac b){
    int d = 0;
    if(b.d == 1||b.d == 5)
        d = -1;
    else if(b.d == 3|| b.d == 7)
        d = 1;
    else if(b.d == 2 || b.d == 6)
        d = 2;
    else
        d = 0;
    return d;
}
pair<int,int> findPoint(bac b1,bac b2){
    int d1 = slope(b1);
    int d2 = slope(b2);
    int x,y;
    int bias1 = b1.y-b2.x*d1;
    int bias2 = b2.y-b2.x*d2;

    if(d1 == 2){
        x = b1.x;
        y = x*d2+bias2;
    }
    else if(d2 == 2){
        x = b2.x;
        y = x*d1+bias1;
    }
    else if(d1 == 0){
        y = b1.y;
        x = (b2.y-bias2)/d2;
    }
    else if(d2 == 0){
        y = b2.y;
        x = (b1.y-bias1)/d1;
    }
    else{
        if(double(bias2-bias1)/double(d1-d2)-(bias2-bias1)/(d1-d2)==0){
            x = (bias2-bias1)/(d1-d2);
            if(double(d1*bias2-d2*bias1)/double(d1-d2)-(d1*bias2-d2*bias1)/(d1-d2)==0){
                y = (d1*bias2-d2*bias1)/(d1-d2);
            }
            else{
                //X
                x = XMAX;
                y = YMAX;
            }
        }
        else{
            //X
            x = XMAX;
            y = YMAX;
        }
    }
    return make_pair(x,y);
}

void isCross(short idx1, short idx2){
    bac b1 = arr[idx1];
    bac b2 = arr[idx2];
    //opposite dir
    if(abs(b1.d-b2.d) == 4){
        if(b1.d == 2 || b1.d == 6){
            if(b1.d == 2 && b1.y>b2.y)
                return;
            if(b1.d == 6 && b1.y<b2.y)
                return;
            if(b1.x == b2.x){
                if((b1.y+b2.y)%2 == 1){
                    return;
                }
                else{
                    obj temp;
                    temp.b1 = idx1;
                    temp.b2 = idx2;
                    temp.t = abs(b1.y-(b1.y+b2.y)/2);
                    vec2[kx] = temp;
                    kx++;
                }
            }
            else{
                return;
            }
        }
        if(b1.d == 4 || b1.d == 8){
            if(b1.d == 4 && b1.x>b2.x)
                return;
            if(b1.d == 8 && b1.x<b2.x)
                return;
            if(b1.y == b2.y){
                if((b1.x+b2.x)%2 == 1){
                    return;
                }
                else{
                    obj temp;
                    temp.b1 = idx1;
                    temp.b2 = idx2;
                    temp.t = abs(b1.x-(b1.x+b2.x)/2);
                    vec2[kx] = temp;
                    kx++;
                }
            }
            else{
                return;
            }
        }
        if(b1.d == 3|| b1.d == 7){
            if(b1.x == b2.x || b1.y== b2.y){
                return;
            }
            if(double((b1.y-b2.y))/double((b1.x-b2.x))==1){
                if(b1.d == 3 && b1.y>b2.y)
                    return;
                if(b1.d == 7 && b1.y<b2.y)
                    return;
                if(double(b1.y+b2.y)/2 == (b1.y+b2.y)/2){
                    obj temp;
                    temp.b1 = idx1;
                    temp.b2 = idx2;
                    temp.t = abs(b1.y-(b1.y+b2.y)/2);
                    vec2[kx] = temp;
                    kx++;
                }
                else{
                    return;
                }
            }
            else{
                return;
            }
        }

        if(b1.d == 1|| b1.d == 5){
            if(b1.x == b2.x || b1.y== b2.y){
                return;
            }
            if(double((b1.y-b2.y))/double((b1.x-b2.x))==-1){
                if(b1.d == 1 && b1.y>b2.y)
                    return;
                if(b1.d == 5 && b1.y<b2.y)
                    return;
                if(double(b1.y+b2.y)/2 == (b1.y+b2.y)/2){
                    obj temp;
                    temp.b1 = idx1;
                    temp.b2 = idx2;
                    temp.t = abs(b1.y-(b1.y+b2.y)/2);
                    vec2[kx] = temp;
                    kx++;
                }
                else{
                    return;
                }
            }
            else{
                return;
            }
        }
    }
    else{
        pair<int,int> pnt = findPoint(b1,b2);
        if(pnt.first == XMAX || pnt.second == YMAX)return;
        if(((b1.d == 3 || b1.d== 4)|| b1.d == 5) && b1.x>pnt.first){
            return;
        }
        if(((b1.d == 1 || b1.d == 8) || b1.d == 7) && b1.x < pnt.first){
            return;
        }
        if(((b2.d == 3 || b2.d== 4)|| b2.d == 5) && b2.x>pnt.first){
            return;
        }
        if(((b2.d == 1 || b2.d == 8) || b2.d == 7) && b2.x < pnt.first){
            return;
        }
        if(((b1.d == 1||b1.d == 2)|| b1.d == 3) && b1.y>pnt.second){
            return;
        }
        if(((b1.d == 5||b1.d == 6)|| b1.d == 7) && b1.y<pnt.second){
            return;
        }
        if(((b2.d == 1||b2.d == 2)|| b2.d == 3) && b2.y>pnt.second){
            return;
        }
        if(((b2.d == 5||b2.d == 6)|| b2.d == 7) && b2.y<pnt.second){
            return;
        }
        int dist1 = 0;
        int dist2 = 0;
        if(b1.d == 2|| b1.d == 6){
            dist1 = abs(pnt.second - b1.y);
        }
        else{
            dist1 = abs(pnt.first - b1.x);
        }
        if(b2.d == 2|| b2.d == 6){
            dist2 = abs(pnt.second - b2.y);
        }
        else{
            dist2 = abs(pnt.first - b2.x);
        }
        if(dist1 == dist2){
            //pos p = pos(pnt.first,pnt.second,dist1);
            obj temp;
            temp.b1 = idx1;
            temp.b2 = idx2;
            temp.t = dist1;
            vec2[kx] = temp;
            kx++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i<5000; i++){
        arr[i].cnt = 0;
        arr[i].flag = -1;
    }
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        int X,Y,D;
        cin>>X>>Y>>D;
        arr[i].x = X;
        arr[i].y = Y;
        arr[i].dx = dx[D-1];
        arr[i].dy = dy[D-1];
        arr[i].d = D;
    }
    for(short i = 0; i<N; i++){
        for(short j = 0; j<N; j++){
            if(arr[i].d == arr[j].d) 
                continue;
            meet(i,j);
        }
    }
    int mx = 0;
    int mdx = 20000001;

    sort(vec2,vec2+kx,cmp);
    
    for(int i = 0; i<kx; i++){
        int k = i;
        int tmx = 0;
        while(vec2[k].t == vec2[i].t){
            if(arr[vec2[k].b1].flag != vec2[k].t){
                arr[vec2[k].b1].flag = vec2[k].t;
                arr[vec2[k].b1].cnt = 0;    
            }
            if(arr[vec2[k].b2].flag != vec2[k].t){
                arr[vec2[k].b2].flag = vec2[k].t;
                arr[vec2[k].b2].cnt = 0;    
            }
            arr[vec2[k].b1].cnt++;
            arr[vec2[k].b2].cnt++;
            tmx = max(tmx,max(arr[vec2[k].b1].cnt,arr[vec2[k].b2].cnt));
            k++;
        }
        if(mx<tmx){
            mx = tmx;
            mdx = vec2[i].t;
        }
        else if(mx == tmx){
            mdx = min(vec2[i].t,mdx);
        }
        i = k-1;
    }
    cout<<mx<<'\n'<<mdx<<'\n';
}