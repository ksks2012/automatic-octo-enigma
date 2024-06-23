/*
    Move with Game 1, 3
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define MOVE_SIZE 4
#define REG_SIZE 7

#define FIRST_PRIORITY 4
#define SECOND_PRIORITY 3
#define THIRD_PRIORITY 2
#define FOURTH_PRIORITY 1

string MOVE[MOVE_SIZE] = {"UP", "LEFT", "DOWN", "RIGHT"};
unordered_map<char, int> MOVE_MAP = {
    {'U', 0},
    {'L', 1},
    {'D', 2},
    {'R', 3}
};

void game_one(string cur_gpu, int reg[], int tmp[]) {
    // ignore when stun
    if(reg[3] > 0) {
        return;
    }
    if(reg[0] + 1 < cur_gpu.size() && cur_gpu[reg[0] + 1] == '#') {
        tmp[0] += FIRST_PRIORITY;
        tmp[1] += SECOND_PRIORITY;
        tmp[2] += THIRD_PRIORITY;
        tmp[3] += FOURTH_PRIORITY;
    } else if(reg[0] + 2 < cur_gpu.size() && cur_gpu[reg[0] + 2] == '#') {
        tmp[1] += FIRST_PRIORITY;
        tmp[2] += SECOND_PRIORITY;
        tmp[3] += THIRD_PRIORITY;
    } else if(reg[0] + 3 < cur_gpu.size() && cur_gpu[reg[0] + 3] == '#') {
        tmp[2] += FIRST_PRIORITY;
        tmp[3] += SECOND_PRIORITY;
    } else {
        tmp[3] += FIRST_PRIORITY;
    }
}

void game_two() {

}

void game_three(string cur_gpu, int reg[], int tmp[]) {
    
}

void game_four() {

}

int main()
{
    int player_idx;
    cin >> player_idx; cin.ignore();
    int nb_games;
    cin >> nb_games; cin.ignore();

    // game loop
    while (1) {
        for (int i = 0; i < 3; i++) {
            string score_info;
            getline(cin, score_info);
        }

        string cur_gpu[nb_games];
        int reg[nb_games][REG_SIZE];
        for (int i = 0; i < nb_games; i++) {
            cin >> cur_gpu[i];
            for(int j = 0; j < REG_SIZE; j++) {
                cin >> reg[i][j];
            }
            cin.ignore();
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        int tmp[MOVE_SIZE] = {0};

        // game_one(cur_gpu[0], reg[0], tmp);
        // game_two(cur_gpu[1], reg[1], tmp);
        game_three(cur_gpu[2], reg[2], tmp);
        // game_four(cur_gpu[3], reg[3], tmp);

        for(int i = 0; i < MOVE_SIZE; i++) {
            if(tmp[i] != 0) {
                cout << MOVE[i] << endl;
                break;
            }
        }
    }
}