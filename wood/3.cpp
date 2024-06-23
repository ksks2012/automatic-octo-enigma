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
        int cur_pos[nb_games];
        int stun[nb_games];
        for (int i = 0; i < nb_games; i++) {
            string gpu;
            int reg_0;
            int reg_1;
            int reg_2;
            int reg_3;
            int reg_4;
            int reg_5;
            int reg_6;
            cin >> gpu >> reg_0 >> reg_1 >> reg_2 >> reg_3 >> reg_4 >> reg_5 >> reg_6; cin.ignore();
            cur_gpu[i] = gpu;
            cur_pos[i] = reg_0;
            stun[i] = reg_3;
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        int tmp[MOVE_SIZE] = {0};
        for(int i = 0; i < nb_games; i++) {
            // ignore when stun
            if(stun[i] > 0) {
                continue;
            }
            if(cur_pos[i] + 1 < GPU_SIZE && cur_gpu[i][cur_pos[i] + 1] == '#') {
                tmp[0]++;
            } else if(cur_pos[i] + 2 < GPU_SIZE && cur_gpu[i][cur_pos[i] + 2] == '#') {
                tmp[1]++;
            } else if(cur_pos[i] + 3 < GPU_SIZE && cur_gpu[i][cur_pos[i] + 3] == '#') {
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