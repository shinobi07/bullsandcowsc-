#include <iostream>
#include <time.h>
#include "lib.h"

using namespace std;

int main() {

  int answer, guess, tries;
  string decision = "y";

  while (decision == "y" || decision == "yes") { // this condition is made to decide if you want to play again

    srand(time(0)); // generate a different number every time the game starts all over again

    string input1; // to check if user inputs a number then convert it into integer tries variable
    string input2; // to check if user inputs a number then convert it into integer guess variable

    cout << endl;

    cout << "Let's play a game of Bulls and Cows. We will generate random number from 1000 to 9999 and your mission is to guess that number." << endl;
    cout << endl;

    cout << "The game is very simple. In your guessing number, if the matching digits are in their right positions, they are bulls; otherwise, they are cows." << endl;
    cout << endl;

    cout << "If you want to try the limit, the biggest possible number is 1999999999 (1 digit of 1 and 9 digits of 9). Otherwise, the program will run on an infinite loop!" << endl;
    cout << endl;

    cout << "LET THE GAME BEGIN!" << endl;
    cout << endl;

    answer = rand() % 9999 + 1000; // generate a random number from 1000 to 9999 every time you play

    int answer_arr[4]; // create an array and add the digits of the answer to the array

    for (int counter1 = 0; counter1 < len(answer); counter1++) {
      answer_arr[counter1] = splitting_digits(answer, len(answer) -counter1); // split digits from the random integer and add the digits into an array for comparision
    }

    cout << "How many tries do you want? ";
    getline(cin, input1);

    cout << endl;

    if (legitimate_number(input1) == false) { // check if user inputs a number or not
      cout << "You should have input an integer, not a string!" << endl;
      cout << endl;
    }

    else {

      tries = stoi(input1); // convert string into integer

      if (tries == 0)
        cout << "See you next time!" << endl;

      else {
        int elements = tries; // get the size for the user choices array

        string choices[tries]; // record all your guesses from start to finish

        while (tries > 0) {

          cout << tries << " turn(s) remaining." << endl;

          cout << "Give me your best shot! ";
          getline(cin, input2);

          cout << endl;

          choices[elements - tries] = input2; // put user input into array

          if (legitimate_number(input2) == false) { // check if user inputs a number or not
            cout << "You should have input an integer, not a string!" << endl;
            cout << endl;
          }

          else {
            guess = stoi(input2); // convert string into integer

            if (guess < -1999999999 || guess > 1999999999) { // prevent users from entering a number outside the limit range; don't know why it does not work??
              cout << "If you want to test the program, only input the numbers in the range between -1999999999 and 1999999999." << endl;
              cout << "If your input is a lot bigger or smaller than the limit ends, the program will run on an infinite loop!" << endl;
              cout << endl;
            }

            else if (len(guess) == 4 && guess >= 1000 && guess <= 9999) {

              int guess_arr[4]; // create an array and add the digits of user guess to the array

              for (int counter2 = 0; counter2 < len(guess); counter2++) {
                guess_arr[counter2] = splitting_digits(guess, len(guess) - counter2); // split digits from the guessing integer and add the digits into an array for comparision
              }

              int bulls = 0;
              int cows = 0;

              for (int counter3 = 0; counter3 < 4; counter3++) {
                if (answer_arr[counter3] == guess_arr[counter3]) // compare the value in each position
                  bulls++; // if equal, plus 1 for bull
                else
                  cows++; // if not equal, plus 1 for cow
              }

              if (bulls != 4) {
                cout << "Answer: " << bulls << " bull(s) and " << cows << " cow(s)." << endl;
                cout << endl;
              }

              else {
                cout << "Bingo! Your guessing is right." << endl;
                cout << " Congratulations!" << endl;
                cout << endl;
                break;
              }
            }

            else {
              cout << "Please give us a 4-digit integer and make it positive!" << endl;
              cout << "Make sure the integer you enter cannot exceed 1999999999 (1 digit of 1 and 9 digits of 9)." << endl;
              cout << endl;
            }

          }

          tries--; // minus 1 try to get to next turn

        }
        cout << "Answer is " << answer << endl;

        cout << endl;

        print_array(choices, elements); // print out the user guesses from start to finish

        cout << endl;

        cout << "Better luck next time!" << endl;

        cout << endl;
      }

    }

    cout << "Do you want to play again? y/n "; // asking to play again or not
    getline(cin, decision);
    cout << endl;
    cout << endl;

    if (decision == "n" || decision == "no") {
      cout << "Thank you for playing the game." << endl;
      cout << "I hope you have a great day today." << endl;
      cout << "Kiitos, moi moi!" << endl;
      cout << endl;
    }

    else {
      cout << "I assume that you wanna quit." << endl;
      cout << "Thank you for playing the game." << endl;
      cout << "I hope you have a great day today." << endl;
      cout << "Kiitos, moi moi!" << endl;
      cout << endl;
    }

  }

  return 0;

}
