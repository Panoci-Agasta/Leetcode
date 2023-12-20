#include<bits/stdc++.h>

using namespace std;


int timetaken(vector<int> pointa, vector<int> pointb){
        int ylen = abs(pointa[1]-pointb[1]);
        int xlen = abs(pointa[0]-pointb[0]);
        return max(xlen,ylen);
    }
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int totaltime = 0;
    for(int i = 0; i < points.size() -1 ; i++){
        int time = timetaken(points[i],points[i+1]);
        totaltime += timetaken(points[i],points[i+1]);
    }
    return totaltime;
}

int main(){
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    cout << minTimeToVisitAllPoints(points) << endl;

    return 0;
}