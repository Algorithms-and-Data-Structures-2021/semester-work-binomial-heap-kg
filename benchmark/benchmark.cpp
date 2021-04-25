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

  while (getline(ss, token, ',')) {
    numbers.push_back(stoi(token));
  }
  return numbers;
}

void demoWrite(string &data, string& path_to_results) {
  fstream fout;
  fout.open(path_to_results, ios::out | ios::app);
  fout << data << "\n";
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

  string path_to_results_main = string(kDatasetPath) + "/results.csv";
  cout << path_to_results_main << endl;
  string data_main{"hsjkaj,yua,132,23"};


  demoWrite(data_main, path_to_results_main);
  demoWrite(data_main, path_to_results_main);
  demoWrite(data_main, path_to_results_main);
  demoWrite(data_main, path_to_results_main);
  return 0;
}
