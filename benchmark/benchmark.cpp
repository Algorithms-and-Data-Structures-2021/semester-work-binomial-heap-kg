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

BinomialHeap *readCSVReturnHeap(string &path) {
  BinomialHeap *heap = new BinomialHeap();

  fstream fin;
  fin.open(path, ios::in);
  vector<string> row;
  string temp;
  fin >> temp;
  istringstream ss(temp);
  string token;

  while (getline(ss, token, ',')) {
    cout << token << endl;
    heap = heap->insert(heap, stoi(token));
    heap->printHeap(heap);
    cout << endl;
  }
  return heap;
}

int main() {
  string p = "/insert/01/100.csv";
  const auto path_to_data_folder = string(kDatasetPath);
  string new_path = path_to_data_folder + p;
  cout << new_path << endl;

  auto *new_heap = readCSVReturnHeap(new_path);
  cout << "MAIN HEAP" << endl;
  new_heap->printHeap(new_heap);

  return 0;
}
