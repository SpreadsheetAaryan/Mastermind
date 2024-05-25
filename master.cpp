#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum color { red, blue, yellow, purple, white, orange };

class Code {
    public:
        Code();
        void generateCode();
        vector<color> getCode() const;
        string codeToString();

    private:
        vector<color> code;

};

Code::Code() {
    code.resize(4);
}

vector<color> Code::getCode() const {
    return code;
}

string Code::codeToString() {
    string s;
    for (int i = 0; i < code.size(); i++) {
        switch (code[i]) {
            case red:
                s.push_back('r');
                break;
            case blue:
                s.push_back('b');
                break;
            case yellow:
                s.push_back('y');
                break;
            case purple:
                s.push_back('p');
                break;
            case white:
                s.push_back('w');
                break;
            case orange:
                s.push_back('o');
                break;
        }
    }
    return s;
}

void Code::generateCode() {
    vector<color> tmp;
    srand(static_cast<unsigned>(time(0)));
    while (tmp.size() < 4) {
        color c = static_cast<color>(rand() % 6);
        if (find(tmp.begin(), tmp.end(), c) == tmp.end()) {
            tmp.push_back(c);
        }
    }
    code = tmp;
}

class Player {
    public:
        Player() : current_guess("") {}
        Player(const Code& c);
        void makeGuess();
        vector<color> getCurrentGuess();
        vector<int> feedback(vector<color> code);

    private:
        string current_guess;
        vector<color> correct;
};

Player::Player(const Code& c) {
    correct = c.getCode();
    current_guess = " ";
}

void Player::makeGuess() {
    cout << "Make your guess! Make sure there are no spaces, and you only type the first letter of each color! Example: rwby" << endl;
    cout << "" << endl;
    cin >> current_guess;
}

vector<color> Player::getCurrentGuess() {
    vector<color> guess;
    for (int i = 0; i < current_guess.size(); i++) {
        switch (current_guess[i]) {
            case 'r':
                guess.push_back(red);
                break;
            case 'b':
                guess.push_back(blue);
                break;
            case 'y':
                guess.push_back(yellow);
                break;
            case 'p':
                guess.push_back(purple);
                break;
            case 'w':
                guess.push_back(white);
                break;
            case 'o':
                guess.push_back(orange);
                break;
        }
    }
    return guess;
}

vector<int> Player::feedback(vector<color> code) {
    vector<int> result(2, 0);
    for (int i = 0; i < 4; i++) {
        if (correct[i] == code[i]) {
            result[0]++;
            result[1]++;
            continue;
        } else {
            for (int j = 0; j < 4; j++) {
                if (code[j] == correct[i]) {
                    result[1]++;
                    break;
                }
            }
        }
    }
    return result;
}


int main() {
    cout << "Welcome to MasterMind! You will be guessing the code from the computer. The 6 different colors are red(r), blue(b), yellow(y), purple(p), white(w), and orange(o)." << endl;
    cout << endl;

    // Generate a code
    Code c = Code();
    c.generateCode();

    bool guessed = false;

    Player player = Player(c);

    cout << "The code has been generated. Make your first guess!" << endl;
    cout << endl;

    // Game loop
    int count = 0;
    while (!guessed) {
        if (count == 6) {
            cout << "You have reached the maximum number of guesses! The correct code was " << c.codeToString() << endl;
            break;
        }

        player.makeGuess();
        vector<color> guess = player.getCurrentGuess();
        vector<int> result = player.feedback(guess);

        if (result[0] == 4) {
            cout << "You got it right!" << endl;
            break;
        }

        cout << "You got " << result[0] << " colors in the right position and " << result[1] << " total colors that were apart of the code!" << endl;

        count++;
    }

    return 0;
}