#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

constexpr int movedelta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

string CellString(State state) {
  switch (state) {
  case State::kObstacle:
    return "⛰️   ";
  case State::kPath:
    return "🚗   ";
  case State::kStart:
    return "🚦   ";
  case State::kFinish:
    return "🏁   ";
  default:
    return " 0   ";
  }
}

vector<State> ParseLine(string line) {
  vector<State> parsed_vector = {};
  istringstream sline(line);
  int n;
  char c;
  while (sline >> n >> c && c == ',') {
    if (n == 0) {
      parsed_vector.push_back(State::kEmpty);
    } else {
      parsed_vector.push_back(State::kObstacle);
    }
  }
  return parsed_vector;
}

vector<vector<State>> ReadBoardFile(string path) {
  vector<vector<State>> board = {};
  ifstream board_file;
  board_file.open(path);
  if (board_file) {
    string line;
    while (getline(board_file, line)) {
      board.push_back(ParseLine(line));
    }
  }
  return board;
}

void PrintBoard(vector<vector<State>> board) {
  for (vector<State> row : board) {
    for (State state : row) {
      cout << CellString(state);
    }
    cout << "\n";
  }
}

bool Compare(vector<int> node_a, vector<int> node_b) {
  int f1 = node_a[2] + node_a[3];
  int f2 = node_b[2] + node_b[3];
  return f1 > f2;
}

bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  int nRows = grid.size();
  int nCols = grid[0].size();
  return (x >= 0 && y >= 0 && x < nRows && y < nCols &&
          grid[x][y] == State::kEmpty);
}

void CellSort(vector<vector<int>> *v) { sort(v->begin(), v->end(), Compare); }

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open,
               vector<vector<State>> &grid) {
  vector<int> node = {x, y, g, h};
  open.push_back(node);
  grid[x][y] = State::kClosed;
}

int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

void ExpandNeighbours(const vector<int> &current, vector<vector<int>> &open,
                      vector<vector<State>> &grid, const int goal[2]) {
  int current_x = current[0];
  int current_y = current[1];
  int current_g = current[2];

  for (int i = 0; i < 4; i++) {
    int x = current_x + movedelta[i][0];
    int y = current_y + movedelta[i][1];
    bool validCell = CheckValidCell(x, y, grid);
    if (validCell) {
      int g = current_g + 1;
      int h = Heuristic(x, y, goal[0], goal[1]);
      AddToOpen(x, y, g, h, open, grid);
    }
  }
}

vector<vector<State>> Search(vector<vector<State>> grid, int start[2],
                             int goal[2]) {
  vector<vector<int>> open = {};
  int x = start[0];
  int y = start[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  AddToOpen(x, y, g, h, open, grid);
  while (open.size() > 0) {
    CellSort(&open);
    vector<int> current = open.back();
    open.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;
    if (x == goal[0] && y == goal[1]) {
      grid[start[0]][start[1]] = State::kStart;
      grid[goal[0]][goal[1]] = State::kFinish;
      return grid;
    }
    ExpandNeighbours(current, open, grid, goal);
  }
  cout << "No path found!"
       << "\n";
  return vector<vector<State>>{};
}

int main() {
  vector<vector<State>> board = ReadBoardFile("1.board");
  int start[2] = {0, 0};
  int goal[2] = {4, 5};
  vector<vector<State>> solution = Search(board, start, goal);
  PrintBoard(solution);
}