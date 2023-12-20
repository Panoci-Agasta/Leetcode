#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &img) {

  int length = img.size();
  int breadth = img[0].size();

  vector<vector<int>> newimg = img;

  vector<pair<int, int>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                                       {0, -1},  {1, -1}, {1, 0},  {1, 1}};

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < breadth; ++j) {
      int sum = img[i][j];
      int numberoftiles = 1;

      for (const auto &item : neighbours) {
        auto [disp_x, disp_y] = item;
        if (disp_x + i >= 0 && disp_y + j >= 0 && disp_x + i < length &&
            disp_y + j < breadth) {
          sum += img[disp_x + i][disp_y + j];
          numberoftiles++;
        }
      }
      newimg[i][j] = floor(sum / numberoftiles);
    }
  }

  return newimg;
}

int main() {
  vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};

  int length = img.size();
  int breadth = img[0].size();

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < breadth; j++) {
      cout << img[i][j] << " ";
    }
    cout << endl;
  }

  vector<vector<int>> smoothimg = imageSmoother(img);

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < breadth; j++) {
      cout << smoothimg[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
