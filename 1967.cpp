#include<iostream>
#include<cmath>
int main(){
    double n;
    std::cin>>n;
    std::cout<<1+ceil(sqrt((n-1.0)/3.0+0.25)-0.5)<<'\n';
}
