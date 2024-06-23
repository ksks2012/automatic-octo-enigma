/*
    Jumping with majority rule
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

#define GPU_SIZE 30
#define MOVE_SIZE 4
#define REG_SIZE 7

string MOVE[MOVE_SIZE] = {"UP", "LEFT", "DOWN", "RIGHT"};

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
        for(int i = 0; i < nb_games; i++) {
            // ignore when stun
            if(reg[i][3] > 0) {
                continue;
            }
            if(reg[i][0] + 1 < GPU_SIZE && cur_gpu[i][reg[i][0] + 1] == '#') {
                tmp[0]++;
            } else if(reg[i][0] + 2 < GPU_SIZE && cur_gpu[i][reg[i][0] + 2] == '#') {
                tmp[1]++;
            } else if(reg[i][0] + 3 < GPU_SIZE && cur_gpu[i][reg[i][0] + 3] == '#') {
                tmp[2]++;
            } else {
                tmp[3]++;
            }
        }

        for(int i = 0; i < MOVE_SIZE; i++) {
            if(tmp[i] != 0) {
                cout << MOVE[i] << endl;
                break;
            }
        }
    }
}