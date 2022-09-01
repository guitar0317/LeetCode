#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool Solution1(vector<vector<int>>& room){
    for(int i=0; i<room.size(); i++){
        for(int j=i+1; j<room.size(); j++){
            if((room[i][0]>=room[j][0] && room[i][0]<room[j][1]) || 
            (room[j][0]>=room[i][0] && room[j][0]<room[i][1]))
                return false;
        }
    }
    return true;
}


bool Solution2(vector<vector<int>>& room){
    sort(room.begin(), room.end(), [](const vector<int>& a, const vector<int>& b){return a[0]<b[0];});
    for(int i=1;i<room.size(); i++){
        if(room[i][0] < room[i-1][1]){
            return false;
        }
    }

    return true;
}


int main(){
    vector<vector<int>> room = 
    {{5,10},{0,30},{15,20}};
    //{{7,10},{2,4}};

    cout << Solution1(room) << endl;
    cout << "---------" << endl;
     cout << Solution2(room) << endl;
}