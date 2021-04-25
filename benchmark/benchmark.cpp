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

vector<int> createVectorFromCSV(string &path) {
  fstream fin;
  fin.open(path, ios::in);

  string temp;
  fin >> temp;
  istringstream ss(temp);

  string token;
  vector<int> numbers;

  while (getline(ss, token, ','))
    numbers.push_back(stoi(token));

  return numbers;
}

int main() {
  string p = "/insert/01/100.csv";
  const auto path_to_data_folder = string(kDatasetPath);
  string new_path = path_to_data_folder + p;
  cout << new_path << endl;

  vector<int> vec = createVectorFromCSV(new_path);

  for (int n: vec) {
    cout << n << ' ';
  }
  cout << vec.size() << " <-- size";

  return 0;
}
