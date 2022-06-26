#include <iostream>
#include <array>
//using namespace std;

void array_print(int* array, int size){
    for (int i = 0; i < size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << "\n" << std::endl;
}

int* insertion_sort(int array[], int size){
  for (int i = 1; i < size; i++){
      int current_value = array[i];
      int j = i - 1;
      while (j >= 0 && array[j] > current_value){
        array[j+1] = array[j];
        j--;
      }
      array[j+1] = current_value;
  }

  return array;
}

int main()
{
  int array_size = 10;
  int number_list[array_size] = {11, 5, 20, 14, 39, 8, 130, 79, 12, 37};
  std::cout << "This example shows the minimum example of insertion sorting.\n";
  std::cout << "------------------------------\n";
  std::cout << "This is the input array. \n";
  // original input array
  array_print(number_list, array_size);
  // sorted array
  int *new_list = insertion_sort(number_list, array_size);
  std::cout << "This is the sorted array. \n";
  array_print(new_list, array_size);

  return 0;
}