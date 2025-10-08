#include<bits/stdc++.h>
using namespace std;
class Solution{
    struct compare{
        bool operator()(pair<char,int>a, pair<char,int>b){
            // a->previous one b->new one
            if(a.first!=b.first) return a.first>b.first;
            return a.second<b.second;
        }
    };
    int main(){
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
    }
};