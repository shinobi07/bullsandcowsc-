#include <iostream>

using namespace std;

int pow(int number, int exponent) {
  if (exponent == 1)
    return number;

  else {
    int result = 1;

    for (int i = 1; i <= exponent; i++) {
      result *= number; // it will multiply itself for "exponent" times
    }

    return result;
  }
}

int splitting_digits(int number, int position) { // position starts at 1 counting from the end of the number
  int result = number / pow(10, position - 1) % 10;
  return result;
}

int len(int number) { // finding number of digits
  int number_of_digits = 0;

  if (number >= 0) {
    for (int i = 0; number > 0; i++) {
      number /= 10; // we count how many times the number can be divided by 10
      number_of_digits++;
    }
  }

  return number_of_digits;
}

bool legitimate_number(string input) { // check if user input is a number
  for (int a = 0; a < input.length(); a++) {
    if (!isdigit(input[a])) {
      return false;
    }
  }
  return true;
}

void print_array(string user_input[], int guesses) { // print out the user guesses from start to finish
  cout << "Here are your guesses:" << endl;
  for (int i = 0; i < guesses; i++) {
    cout << user_input[i] << endl;
  }
}
