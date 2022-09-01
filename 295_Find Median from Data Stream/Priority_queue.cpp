#include <iostream>
#include <queue>
using namespace std;

class MedinFinder{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int n){
        maxHeap.push(n);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian(){
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top()+minHeap.top())/2.0;
    }
};

int main(){
    MedinFinder m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() <<endl;
    m.addNum(1);
    cout << m.findMedian() <<endl;

}