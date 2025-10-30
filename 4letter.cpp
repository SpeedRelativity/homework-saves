#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

const string dict_path = "dictionary.txt";


int main() {

    // read dict into a vector
    ifstream input(dict_path);
    vector<string> dict;

    string a,b,c,d;
    string word;

    while (input >> word) {dict.push_back(word);}
    srand(time(0)); // random seed

    vector<string> chosen;


    // pick 4 random words using rand time seed and put into a dict
    for (int k = 0; k < 4; k++) {
        int index = rand() % dict.size();
        chosen.push_back(dict[index]);
        cout << dict[index] << endl;
    }

    char g[16]; //grid
    
    int pos = 0;

    // copy letters into grid.
    for (int w = 0; w < 4; w++) {
        for (int i = 0; i < 4; i++) {
            g[pos++] = chosen[w][i];
        }
    }

    // shuffle grid randomly using rand()
    for (int i = 15; i > 0; i--) {
        int j = rand() % (i + 1);
        char tmp = g[i];
        g[i] = g[j];
        g[j] = tmp;
    }
    
    for (int i = 0; i < 16; i++) {
    cout << g[i] << (i % 4 == 3 ? '\n' : ' ');
    }


    // main loop, 3 attempts, ask for 4 guesses, check guess
    // if all guesses are correct win, otherwise show answer.
    for (int attempt = 1; attempt <= 3; attempt++){
        cout << "Attempt " << attempt << ":\n";
        int correct = 0;
        for (int i = 0; i < 4; i++){
            string guess;
            cin >> guess;
            for(string ans: chosen){
                if(guess == ans){
                    correct++;
                    break;
                }
            }
        }

        if(correct == 4){
            cout << "You win! \n";
            return 0;
        }
        else {
            cout << "Correct during attempt: " << correct;
        }
    }

    cout << "Out of attempts. words were: \n";
    for (string ans: chosen){
        cout << ans << "\n";
    }

    return 0;
}