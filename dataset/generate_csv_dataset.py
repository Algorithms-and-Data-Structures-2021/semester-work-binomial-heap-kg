import random
import csv
import os


names_of_sets = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10']
methods = ['insert', 'extract_min', 'get_min']
number_of_elements_list = [100,  500, 1000, 5000, 750000, 1000000, 2500000, 5000000]
border = 10 ** 9

path_to_dataset = os.path.join(os.getcwd(), "data")
for method in methods:
    path_to_method = os.path.join(path_to_dataset, method)
    os.mkdir(path_to_method)

    for set in names_of_sets:
        path_to_set = os.path.join(path_to_method, set)
        os.mkdir(path_to_set)

        for number_of_elements in number_of_elements_list:
            path_to_file = os.path.join(path_to_set, str(number_of_elements) + '.csv')
            print(path_to_file)
            data = []
            data.clear()

            for i in range(number_of_elements):
                data.append(random.randint(0, border))

            print('data after', data)
            file = open(path_to_file, "w")

            with file:
                writer = csv.writer(file)
                writer.writerow(data)


# import argparse
#
# DEFAULT_DESCRIPTION = 'CSV dataset generator script demo.'
# DEFAULT_SAMPLES = 100
#
#
# def parse_args():
#     """
#     Парсинг аргументов командной строки (CLI).
#     :return интерфейс для работы с аргументами.
#
#     Больше информации на https://docs.python.org/3.7/howto/argparse.html
#     """
#     parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)
#
#     parser.add_argument('output',
#                         type=str,
#                         help='output CSV file, e.g. data/output.csv')
#
#     parser.add_argument('--samples',
#                         type=int,
#                         default=DEFAULT_SAMPLES,
#                         help='number of samples to generate (default: {})'.format(DEFAULT_SAMPLES))
#
#     return parser.parse_args()
#
#
# if __name__ == '__main__':
#     args = parse_args()
#
#     # валидация аргументов
#     if args.samples < 0:
#         raise ValueError('Number of samples must be greater than 0.')
#
#     # запись данных в файл
#     with open(args.output, 'w') as file:
#         for i in range(args.samples - 1):
#             file.write('{},'.format(i))
#         file.write(str(args.samples - 1))
