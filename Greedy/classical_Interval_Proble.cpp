#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int greedy(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end(),
    [](vector<int> a, vector<int> b){
        return a[1] < b[1];
    });

    int count = 0;
    int lastEnd = -1;
    for(auto &inter : intervals){
        int start = inter[0];
        int end = inter[1];
        if(start >= lastEnd){
            count++;
            lastEnd = inter[1];
        }
    }

    return count;
}

int main(){
    int n; // Count of intervals
    cout<<"Enter size : ";
    cin>>n; //
    cout<<"Enter start and end time"<<endl;
    vector<vector<int>> intervals(n, vector<int>(2,0));
    for(auto& interval : intervals){
        int start;
        int end;
        cout<<"Start : ";
        cin>>start;
        cout<<"End : ";
        cin>>end;
        interval[0] = start;
        interval[1] = end;
    }
    // cout<<"Start : End"<<endl;
    // for(const auto& interval : intervals) cout<<interval[0]<<" : "<<interval[1]<<endl;
    cout<<greedy(intervals);
}
