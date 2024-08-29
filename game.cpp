#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";

void functionOne() {
    cout << "     |        |     " << "\n";
    cout << "  " << space[0][0] << "  |   " << space[0][1] << "    |   " << space[0][2] << "   " << "\n";
    cout << "_____|________|_____" << "\n";
    cout << "     |        |     " << "\n";
    cout << "  " << space[1][0] << "  |   " << space[1][1] << "    |   " << space[1][2] << "   " << "\n";
    cout << "_____|________|_____" << "\n";
    cout << "     |        |     " << "\n";
    cout << "  " << space[2][0] << "  |   " << space[2][1] << "    |   " << space[2][2] << "   " << "\n";
    cout << "     |        |     " << "\n";
}

void functionTwo() {
    int digit;
    if (token == 'x') {
        cout << n1 << " please enter: ";
    } else if (token == '0') {
        cout << n2 << " please enter: ";
    }
    cin >> digit;

    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    if (digit < 1 || digit > 9 || space[row][column] == 'x' || space[row][column] == '0') {
        cout << "Invalid move! Try again." << endl;
        functionTwo();
    } else {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    }

    functionOne();
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return true;
}

int main() {
    cout << "Enter the name of the first player: ";
    cin >> n1;
    cout << "Enter the name of the second player: ";
    cin >> n2;

    cout << n1 << " is player 1, so they will play first!" << "\n";
    cout << n2 << " is player 2, so they will play second!" << "\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    functionOne();

    if (token == 'x' && tie == false) {
        cout << n2 << " Wins!!" << endl;
    } else if (token == '0' && tie == false) {
        cout << n1 << " Wins!!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}