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
  vector<string> methods{"make_heap", "remove_heap", "extract_min"};
  vector<string> trials{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  vector<string> volumes{"100", "500", "1000", "5000", "750000", "1000000", "2500000", "5000000"};
  vector<string> sets{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

  const auto path_to_data_folder = string(kDatasetPath);
  cout << path_to_data_folder << endl;

  string path_to_results = string(kDatasetPath) + "/results.csv";
  cout << "path to results: " << path_to_results << endl;

  string path_to_csv;
  string measurement_results;
  for (string method: methods) {
    for (string set: sets) {
      for (string volume: volumes) {
        for (string trial: trials) {
          path_to_csv = path_to_data_folder + "/" + method + "/" + set + "/" + volume + ".csv";
          cout << "path to csv:  " << path_to_csv << " trial: " << trial << endl;

          auto vect = createVectorFromCSV(path_to_csv);

          auto begin_make = chrono::high_resolution_clock::now();
          auto *h = new BinomialHeap();
          h = h->makeHeap(h, vect);
          auto end_make = chrono::high_resolution_clock::now();
          auto elapsed_make = chrono::duration_cast<chrono::milliseconds>(end_make - begin_make);
          cout << elapsed_make.count() << endl;

          auto begin_extract = chrono::high_resolution_clock::now();
          h = h->extractMin(h);
          auto end_extract = chrono::high_resolution_clock::now();
          auto elapsed_extract = chrono::duration_cast<chrono::milliseconds>(end_extract - begin_extract);
          cout << elapsed_extract.count() << endl;

          auto begin_remove = chrono::high_resolution_clock::now();
          h = h->removeHeap(h);
          auto end_remove = chrono::high_resolution_clock::now();
          auto elapsed_remove = chrono::duration_cast<chrono::milliseconds>(end_remove - begin_remove);
          cout << elapsed_remove.count() << endl;

          measurement_results.clear();
          measurement_results = set + ',' + volume + ',' + trial + ',' + to_string(elapsed_make.count()) + ',' + to_string(elapsed_extract.count()) + ',' + to_string(elapsed_remove.count());

          demoWrite(measurement_results, path_to_results);
        }
      }
    }
  }
  return 0;
}
