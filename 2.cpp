/*
    Jumping base on last race
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
        string cur_gpu;
        int cur_reg;
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
            cur_gpu = gpu;
            cur_reg = reg_0;
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cerr << "gpu" << " " << cur_gpu << endl;
        cerr << "cur_reg" << " " << cur_reg << endl;
        cerr << "cur_gpu[cur_reg + 1]" << " " << cur_gpu[cur_reg + 1] << endl;
        cerr << "cur_gpu[cur_reg + 2]" << " " << cur_gpu[cur_reg + 2] << endl;
        cerr << "cur_gpu[cur_reg + 3]" << " " << cur_gpu[cur_reg + 3] << endl;
        if(cur_reg + 1 < cur_gpu.size() && cur_gpu[cur_reg + 1] == '#') {
            cout << "UP" << endl;
        } else if(cur_reg + 2 < cur_gpu.size() && cur_gpu[cur_reg + 2] == '#') {
            cout << "LEFT" << endl;
        } else if(cur_reg + 3 < cur_gpu.size() && cur_gpu[cur_reg + 3] == '#') {
            cout << "DOWN" << endl;
        } else {
            cout << "RIGHT" << endl;
        }
    }
}