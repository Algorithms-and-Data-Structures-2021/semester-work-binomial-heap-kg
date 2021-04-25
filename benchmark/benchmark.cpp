#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

void readCSV(string &path) {
  fstream fin;
  fin.open(path, ios::in);
  vector<string> row;
  string temp;
  fin >> temp;
  istringstream ss(temp);
  string token;

  while (getline(ss, token, ',')) {
    cout << token << endl;
  }
}

int main() {
  string p = "/insert/01/100.csv";
  const auto path_to_data_folder = string(kDatasetPath);
  string new_path = path_to_data_folder + p;
  cout << new_path << endl;

  readCSV(new_path);

  return 0;
}
