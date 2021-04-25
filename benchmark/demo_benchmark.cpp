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
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

vector<string> makeHeap(string path){
  auto input_file = ifstream(path);
  vector<string> data;
  if (input_file) {
    std::string line;
    while (std::getline(input_file, line)){
      std::istringstream s(line);
      std::string field;
      while (std::getline(s, field, ',')) {
        data.push_back(field);
      }
    }
  }
  return data;
}

int main(int argc, char **argv) {

  vector<string> mas{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  vector<string> mas2{"100", "500", "1000", "5000", "750000", "1000000", "2500000", "5000000"};
  vector<string> mas3{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto output_file = ofstream(path);
  output_file.open(path + "/" + "result.csv", ios::out | ios::app);
  output_file << "file" << "," << "count" << "," << "number" << "," << "insert" << "," << "getMin" << "," << "removeHeap" << endl;
  for(int i =0; i < 8; i++){
    for(int j = 0; j < 10; j++){
      auto path_file = string(mas3.at(j) + "/" + mas2.at(i));
      for(int k = 0; k < 10; k++){
        auto data = makeHeap(path + path_file);
        itis::BinomialHeap *main_heap = new itis::BinomialHeap();
        auto size_ = data.size();

        const auto time_point_before = chrono::steady_clock::now();
        for(int i = 0; i < size_; i++){
          main_heap = main_heap->insert(main_heap, i);
        }
        const auto time_point_after = chrono::steady_clock::now();
        const auto time_diff = time_point_after - time_point_before;
        const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        const auto time_point_before2 = chrono::steady_clock::now();
        main_heap->getMin(main_heap);
        const auto time_point_after2 = chrono::steady_clock::now();
        const auto time_diff2 = time_point_after2 - time_point_before2;
        const long time_elapsed_ns2 = chrono::duration_cast<chrono::nanoseconds>(time_diff2).count();

        const auto time_point_before3 = chrono::steady_clock::now();
        main_heap->removeHeap(main_heap);
        const auto time_point_after3 = chrono::steady_clock::now();
        const auto time_diff3 = time_point_after3 - time_point_before3;
        const long time_elapsed_ns3 = chrono::duration_cast<chrono::nanoseconds>(time_diff3).count();

        output_file << mas3.at(j) << "," << mas2.at(i) << "," << mas.at(k) << "," << time_elapsed_ns << "," << time_elapsed_ns2 << "," << time_elapsed_ns3 << endl;
      }
    }
  }
  output_file.close();
  return 0;
}
