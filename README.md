# Binomial heap

В этом проекте реализуется структура [Binomial heap](https://en.wikipedia.org/wiki/Binomial_heap), представляющая собой связный список биномиальных деревьев.
Такая структура данных используется при реализации [priority queue](https://en.wikipedia.org/wiki/Priority_queue#:~:text=In%20computer%20science%2C%20a%20priority,an%20element%20with%20low%20priority.).

Внутри проекта вы можете выполнить следущие операции:
- `insert` - обеспечивает вставку одного элемента в кучу. Теоретическая сложность - `O(Log n)`;
- `makeHeap` - на основе многократного повторения операции _insert_ создаёт кучу из вектора чисел;
- `exctractMin` - удалят из кучи наименьший элемент. Теоретическая сложность - `O(log n)`;
- `removeHeap` - стрирает кучу, многократно вызывая _extractMin_; 
- `printHeap` - печатает кучу в виде _12 degree: 3_, где 12 - значение узла, 3 - количество детей узла; 

## Команда "Girls' Power"

| Фамилия Имя      | Вклад (%) | Прозвище          |
| :---             |   ---:    |  ---:             |
| Корнеева Варвара | 50        |  _боссеса первая_ |
| Гордеева Елена   | 50        |  _боссеса вторая_ |


**Девиз команды**
> _Только вперёд!_

## Структура проекта

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

_Постарайтесь написать инструкцию так, чтобы незнакомый с проектом человек смог самостоятельно всё запустить._

### Пример (Windows)

#### Сборка проекта

_Опишите процесс сборки проекта._

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-binomial-heap-kg
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-template

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):
1. Откройте вашу среду разработки.
2. В директории dataset найдите файл _generate_csv_dataset.py_ и запустите его, например, с помощью правой кнопки мыши 
   (проверьте, чтобы у вас был настроен интерпетатор python). После этого в директории `dataset/data` начнётся генерация тестовых данных.
   
Данные будут организованы следующим образом:
```shell
dataset/data/
  insert/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  getMin/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ...
```

По названию директории `/dataset/data/insert` и т.п. можно понять, что здесь хранятся наборы данных для контрольных тестов по
**вставке** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

**Примечание**. Во избежание "захламления" репозитория большим объёмом данных рекомендуется указать ссылку на архив с
набором данных, который при необходимости можно скачать по ссылке. Наборы данных должны находиться в папке семестровой
работы на [Google Drive](https://drive.google.com/drive/folders/17-qridbMXFnz3E-6UjOj0WD1H0jWtpz3?usp=sharing).

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `random_search_benchmark` | поиск элементов по случайному индексу   | _время_         |
| `add_benchmark`           | добавление элементов в структуру данных | _время, память_ |
| ...                       | ...                                     | ...             |

##### Примеры запуска

```shell
./benchmark <input> <output> --trials 50
```

- `<input>` - входной файл с набором данных в формате CSV;
- `<output>` - выходной файл с результатами контрольного теста;
- `--trials` - количество прогонов на наборе данных и т.д.

Добавление 10000 случайных элементов в структуру данных (повторить операцию 50 раз и вычислить среднее время работы и
потребляемую память):

```
./add_benchmark.exe ../dataset/data/add/10000.csv metrics.txt --trials 50
``` 

где `<input> = ../dataset/data/add/10000.csv` и `<output> = metrics.txt`.

**Примечание**. Файл с метриками не обязателен, можете выводить данные в стандартный поток вывода (т.е. консоль).

## Источники

1. https://en.wikipedia.org/wiki/Binomial_heap
2. https://habr.com/ru/post/135232/
3. https://neerc.ifmo.ru/wiki/index.php?title=Биномиальная_куча
4. http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap20.htm
