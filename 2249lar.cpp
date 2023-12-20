// Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents
// the center (xi, yi) and radius ri of the ith circle drawn on a grid, return
// the number of lattice points that are present inside at least one circle.
//

#include <climits>
#include <cmath>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int countLatticePoints(vector<vector<int>> &circles) {
  set<pair<int, int>> point_inside = {};

  int minx = INT_MAX;
  int miny = INT_MAX;
  int maxx = INT_MIN;
  int maxy = INT_MIN;

  for (int i = 0; i < circles.size(); i++) {
    if (circles[i][0] - circles[i][2] < minx) {
      minx = circles[i][0] - circles[i][2];
    }
    if (circles[i][0] + circles[i][2] > maxx) {
      maxx = circles[i][0] + circles[i][2];
    }
    if (circles[i][1] - circles[i][2] < miny) {
      miny = circles[i][1] - circles[i][2];
    
    if (circles[i][1] + circles[i][2] > maxy) {
      maxy = circles[i][1] + circles[i][2];
    }
  }

  // for (vector<int> &circle : circles) {
  //   if (circle[0] - circle[2] < minx) {
  //     minx = circle[0] - circle[2];
  //   }
  //   if (circle[0] + circle[2] > maxx) {
  //     maxx = circle[0] + circle[2];
  //   }
  //   if (circle[1] - circle[2] < miny) {
  //     miny = circle[1] - circle[2];
  //   }
  //   if (circle[1] + circle[2] < maxy) {
  //     maxy = circle[1] + circle[2];
  //   }
  // }

  for (int i = minx; i <= maxx; i++) {
    for (int j = miny; j <= maxy; j++) {
      for (auto &circle : circles) {
        int value =
            pow(i - circle[0], 2) + pow(j - circle[1], 2) - pow(circle[2], 2);
        if (value <= 0) {
          point_inside.insert(make_pair(i, j));
        }
      }
    }
  }
  return point_inside.size();
}

int main() {

  vector<vector<int>> circles = {{2, 2, 2}, {3, 4, 1}}; // can also use {2,2,1}

  cout << countLatticePoints(circles) << endl;

  return 0;
}
