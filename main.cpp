

#include "src/meet.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
  string filename;
  cout << "Enter the filename: ";
  cin >> filename;

  ifstream file(filename);

  if (!file.is_open())
  {
    cout << "Error: Could not open file." << endl;
    return 1;
  }


  string line;
  getline(file, line);

  file.close();


  int count = 0;

  for (char c : line)
  {
    if (c == ',')
      count++;
  }
  count += 1;


  int* data = new(nothrow) int[count];

  if (data == nullptr)
  {
    cout << "Error: Memory allocation failed." << endl;
    return 1;
  }


  stringstream ss(line);
  string temp;
  int index = 0;

  while (getline(ss, temp, ','))
  {
    data[index++] = stoi(temp);
  }

  double median;

  if (count % 2 == 1)
  {
    median = data[count / 2];
  }
  else
  {
    median = (data[count / 2 - 1] + data[count / 2]) / 2.0;
  }

  cout << "The median of the dataset is " << median << "." << endl;


  delete[] data;

  return 0;
}