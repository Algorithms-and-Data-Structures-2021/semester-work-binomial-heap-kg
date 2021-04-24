#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

itis::BinomialHeap* makeHeap(string path){
  auto input_file = ifstream(path);
  auto *heap = new itis::BinomialHeap();
  if (input_file) {
//    vector<string> data;
//    auto *heap = new itis::BinomialHeap();
    std::string line;
//    int i = 0;
    while (std::getline(input_file, line)){
  //      cout << line << endl;
      std::istringstream s(line);
      std::string field;
      while (std::getline(s, field, ',')) {
        heap = heap->insert(heap, stoi(field));
//        data.push_back(field);
//        cout << field << endl;
  //        cout << data[i] << endl;
//        i++;
      }
    }
  }
//  heap->printHeap(heap);
  return heap;
}

int main(int argc, char **argv) {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы

  // Можете передать путь до входного/выходного файла в качестве аргумента,
  // т.е. не обязательно использовать kDatasetPath и прочие константы

  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  // Tip 2: для перевода строки в число можете использовать функцию stoi (string to integer)

  // можете использовать функционал класса stringstream для обработки строки
  auto ss = stringstream("0 1 2");  // передаете строку (входной аргумент или строку из файла) и обрабатываете ее

  int number = 0;
  ss >> number;  // number = 0
  ss >> number;  // number = 1
  ss >> number;  // number = 2

  vector<string> mas{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  vector<string> mas2{"100", "500", "1000", "5000", "750000", "1000000", "2500000", "5000000"};
  vector<string> mas3{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto output_file = ofstream(path);
//  ofstream output_file;
  output_file.open(path + "/" + "result.csv", ios::out | ios::app);
  output_file << "file" << "," << "count" << "," << "number" << "," << "insert" << "," << "get_min" << "," << "extract_min" << endl;
  for(int i =0; i < 8; i++){
    for(int j = 0; j < 10; j++){
      auto path_file = string(mas3.at(j) + "/" + mas2.at(i));
//      cout << path_file << endl;
//      auto heap = makeHeap(path + path_file);
      for(int k = 0; k < 10; k++){
//        auto input_file = ifstream(path + part_file);

        const auto time_point_before = chrono::steady_clock::now();
        auto heap = makeHeap(path + path_file);
        const auto time_point_after = chrono::steady_clock::now();
        const auto time_diff = time_point_after - time_point_before;
        const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
//        cout << time_elapsed_ns << endl;

        const auto time_point_before2 = chrono::steady_clock::now();
        heap->getMin(heap);
        const auto time_point_after2 = chrono::steady_clock::now();
        const auto time_diff2 = time_point_after2 - time_point_before2;
        const long time_elapsed_ns2 = chrono::duration_cast<chrono::nanoseconds>(time_diff2).count();

//        const auto time_point_before3 = chrono::steady_clock::now();
//        heap->extractMin(heap);
//        const auto time_point_after3 = chrono::steady_clock::now();
//        const auto time_diff3 = time_point_after3 - time_point_before3;
//        const long time_elapsed_ns3 = chrono::duration_cast<chrono::nanoseconds>(time_diff3).count();

        output_file << mas3.at(j) << "," << mas2.at(i) << "," << mas.at(k) << "," << time_elapsed_ns << "," << time_elapsed_ns2 << endl;
      }
    }
  }

//  makeHeap(path + "/insert/01/100.csv");

//  auto input_file = ifstream(path + "/insert/01/100.csv");
//
//  if (input_file) {
//    // чтение и обработка набора данных ...
//    vector<string> data;
//    std::string line;
//    int i = 0;
//    while (std::getline(input_file, line)){
////      cout << line << endl;
//      std::istringstream s(line);
//      std::string field;
//      while (std::getline(s, field, ',')) {
//        data.push_back(field);
//        cout << field << endl;
////        cout << data[i] << endl;
//        i++;
//      }
//    }
//  }

  // Контрольный тест: операции добавления, удаления, поиска и пр. над структурой данных

  // Tip 3: время работы программы (или участка кода) можно осуществить
  // как изнутри программы (std::chrono), так и сторонними утилитами

  const auto time_point_before = chrono::high_resolution_clock::now();

  // здесь находится участок кода, время которого необходимо замерить

  const auto time_point_after = chrono::high_resolution_clock::now();

  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;
//  const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

//  cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

  return 0;
}
