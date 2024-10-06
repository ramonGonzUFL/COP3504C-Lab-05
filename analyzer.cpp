#include "./StringData.h"
#include <iostream>
#include <string>
#include <vector>

// Finds the index of an element in an array, or returns -1
// Has an O(n) time complexity
int linear_search(std::vector<std::string> container, std::string element) {
  for (int i = 0; i < container.size(); i++)
    if (container[i] == element)
      return i;

  return -1;
}

// Finds the index of an element in an array, or returns -1
// Has an O(log(n)) time complexity
int binary_search(std::vector<std::string> container, std::string element) {
  int lower = 0;
  int upper = container.size();

  while (lower < upper) {
    int center = ((lower + upper) / 2);

    if (container[center] < element)
      lower = center + 1;
    else if (container[center] > element)
      upper = center - 1;
    else
      return center;
  }

  if (container[lower] == element)
    return lower;

  return -1;
}

int main() {
  std::vector<std::string> dataset = getStringData();

  long long time = 0;

  // Search for NOT_HERE
  std::cout << "Searching for 'NOT_HERE'\n";
  std::cout << "  Linear\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << linear_search(dataset, "NOT_HERE") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n";

  std::cout << "  Binary\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << binary_search(dataset, "NOT_HERE") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n\n";

  // Search for middle case
  std::cout << "Searching for 'mzzzz'\n";
  std::cout << "  Linear\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << linear_search(dataset, "mzzzz") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n";

  std::cout << "  Binary\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << binary_search(dataset, "mzzzz") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n\n";

  // Search for first case
  std::cout << "Searching for 'aaaaa'\n";
  std::cout << "  Linear\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << linear_search(dataset, "aaaaa") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n";

  std::cout << "  Binary\n";
  time = systemTimeNanoseconds();
  std::cout << "    Result: " << binary_search(dataset, "aaaaa") << "\n";
  std::cout << "    Time: " << (systemTimeNanoseconds() - time) << "ns\n\n\n";
}
