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

  string path_to_csv;
  for (string method: methods) {
    for (string set: sets) {
      for (string volume: volumes) {
        for (string trial: trials) {
          path_to_csv = path_to_data_folder + "/" + method + "/" + set + "/" + volume + ".csv";
          cout << "path to csv:  " << path_to_csv << endl;
        }
      }
    }
  }

//  string p = "/insert/01/100.csv";
//  const auto path_to_data_folder = string(kDatasetPath);
//  string new_path = path_to_data_folder + p;
//  cout << new_path << endl;


//  vector<int> vec = createVectorFromCSV(new_path);
//
//  for (int n: vec) {
//    cout << n << ' ';
//  }
//  cout << vec.size() << " <-- size";
//
//  string path_to_results_main = string(kDatasetPath) + "/results.csv";
//  cout << path_to_results_main << endl;
//  string data_main{"hsjkaj,yua,132,23"};


//  demoWrite(data_main, path_to_results_main);
//  demoWrite(data_main, path_to_results_main);
//  demoWrite(data_main, path_to_results_main);
//  demoWrite(data_main, path_to_results_main);
  return 0;
}
