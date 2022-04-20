#include <iostream>
#include <array>
//using namespace std;

void array_print(int array[], int size){
    for (int i = 0; i < size; i++){
        std::cout << array[i] << std::endl;
    }
}

int main()
{
  int array_size = 10;
  int number_list[array_size] = {11, 5, 20, 14, 39, 8, 130, 79, 12, 37};
  std::cout << "This example shows the minimum example of insertion sorting.";
  // original input array
  array_print(number_list, array_size);
  return 0;
}