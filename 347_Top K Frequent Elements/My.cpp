#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool SortbyVal(pair<int,int>& a, pair<int,int>& b){
    return a.second>b.second;
}

void topKFrequent(vector<int>& nums, int k){
    map<int,int> mp;
    for(auto n:nums){
        mp[n]++;
    }

    vector<pair<int,int>> v;
    map<int,int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), SortbyVal);

    vector<int> ans(k);
    for(int i=0; i<k; i++){
        ans[i] = v[i].first;
        cout<<v[i].first<<endl;
    }
}

int main(){
    vector<int> nums = {1,1,1,2,2,2,3};
    int k=2;
    topKFrequent(nums, k);

}