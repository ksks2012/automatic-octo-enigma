/*
    Move with 2 -> 4 -> 1, 3
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

void game_one(string cur_gpu, int reg[], int move_weight[]) {
    // ignore when stun
    if(reg[3] > 0) {
        return;
    }
    if(reg[0] + 1 < cur_gpu.size() && cur_gpu[reg[0] + 1] == '#') {
        move_weight[0] += FIRST_PRIORITY;
        move_weight[1] += SECOND_PRIORITY;
        move_weight[2] += THIRD_PRIORITY;
        move_weight[3] += FOURTH_PRIORITY;
    } else if(reg[0] + 2 < cur_gpu.size() && cur_gpu[reg[0] + 2] == '#') {
        move_weight[1] += FIRST_PRIORITY;
        move_weight[2] += SECOND_PRIORITY;
        move_weight[3] += THIRD_PRIORITY;
    } else if(reg[0] + 3 < cur_gpu.size() && cur_gpu[reg[0] + 3] == '#') {
        move_weight[2] += FIRST_PRIORITY;
        move_weight[3] += SECOND_PRIORITY;
    } else {
        move_weight[3] += FIRST_PRIORITY;
    }
}

void game_two(string cur_gpu, int reg[], int move_weight[]) {
    // x coordinate movement
    if(abs(reg[0]) > abs(reg[1])) {
        if(reg[0] > 0)
            move_weight[1] += FIRST_PRIORITY;
        else
            move_weight[3] += FIRST_PRIORITY;
    } else {
        if(reg[1] > 0)
            move_weight[0] += FIRST_PRIORITY;
        else
            move_weight[2] += FIRST_PRIORITY;
    }
}

bool check_game_two(string cur_gpu, int reg[]) {  
    int player_one = abs(reg[0]) + abs(reg[1]);
    int player_two = abs(reg[2]) + abs(reg[3]);
    int player_three = abs(reg[4]) + abs(reg[5]);
    if(player_one >= player_two && player_one >= player_three && cur_gpu.size() == 1){
        return true;
    }

    return false;
}

void game_three(string cur_gpu, int reg[], int move_weight[]) {
    int risk = reg[3];
    if(risk < 0) {
        return;
    }

    // risk 4, 3 -> step 1
    // risk 2 -> step 2, 1
    // risk 1 -> step 3, 2, 1
    // risk 0 -> step 4, 3, 2, 1
    if(risk >= 3) {
        move_weight[MOVE_MAP[cur_gpu[0]]] += FIRST_PRIORITY;
    } else if(risk >= 2) {
        move_weight[MOVE_MAP[cur_gpu[0]]] += SECOND_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[1]]] += FIRST_PRIORITY;
    } else if(risk >= 1) {
        move_weight[MOVE_MAP[cur_gpu[0]]] += THIRD_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[1]]] += SECOND_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[2]]] += FIRST_PRIORITY;
    } else {
        move_weight[MOVE_MAP[cur_gpu[0]]] += FOURTH_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[1]]] += THIRD_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[2]]] += SECOND_PRIORITY;
        move_weight[MOVE_MAP[cur_gpu[3]]] += FIRST_PRIORITY;
    }

    // just move by increment of risk
    // for(int i = 0; i < cur_gpu.size(); i++) {
    //     for(int j = 0; j < MOVE_SIZE; j++) {
    //         if(cur_gpu[i] == MOVE[j][0]) {
    //             move_weight[j] += FIRST_PRIORITY - i;
    //         }
    //     }
    // }
    cerr << "== GAME THREE ==" << endl;
    cerr << cur_gpu << endl;
    for(int i = 0; i < MOVE_SIZE; i++) {
        cerr << move_weight[i] << endl;
    }
}

void game_four(string cur_gpu, int reg[], int move_weight[], int turn) {
    move_weight[MOVE_MAP[cur_gpu[0]]] += FIRST_PRIORITY;
}

bool check_game_four(string cur_gpu, int reg[]) {
    int player_one = reg[0] + reg[3];
    int player_two = reg[1] + reg[4] + 1;
    int player_three = reg[2] + reg[5] + 1;
    
    int remain = cur_gpu.size();
    // potential score
    int pot_two = (reg[4] + remain - 1 + reg[4]) * remain / 2;
    int pot_three = (reg[5] + remain - 1 + reg[5]) * remain / 2;

    cerr << "check_game_four" << endl;
    cerr << "remain, reg[4], reg[5]: " << remain << " " << reg[4] << " " << reg[5] << endl;
    cerr << "pot_two: " << pot_two << endl;
    cerr << "pot_three: " << pot_three << endl;

    if(player_one <= player_two + pot_two && player_one <= player_three + pot_three) {
        return true;
    }
    // if(reg[0] <= reg[1] || reg[0] <= reg[2]) {
    //     return true;
    // }
    // if(reg[3] <= reg[4] && reg[3] <= reg[5]) {
    //     return true;
    // }
    return false;
}

int main()
{
    int player_idx;
    cin >> player_idx; cin.ignore();
    int nb_games;
    cin >> nb_games; cin.ignore();

    int turn = 0;
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

        int move_weight[MOVE_SIZE] = {0};

        // game_two(cur_gpu[1], reg[1], move_weight);

        // min point + (release + combo)

        if(check_game_two(cur_gpu[3], reg[3])) {
            cerr << " Strategy 1" << endl;
            game_two(cur_gpu[1], reg[1], move_weight);
        } else if(check_game_four(cur_gpu[3], reg[3])) {
            cerr << " Strategy 2" << endl;
            game_four(cur_gpu[3], reg[3], move_weight, turn);
        } else {
            cerr << " Strategy 3" << endl;
            game_one(cur_gpu[0], reg[0], move_weight);
            game_three(cur_gpu[2], reg[2], move_weight);
        }

        cout << MOVE[max_element(move_weight, move_weight + MOVE_SIZE) - move_weight] << endl;
        turn++;


        if(cur_gpu[1].size() == 1) {
            cerr << "cur_gpu[1]:" << endl;
            cerr << reg[1][0] << " " << reg[1][1] << endl;
            cerr << reg[1][2] << " " << reg[1][3] << endl;
            cerr << reg[1][4] << " " << reg[1][5] << endl;
        }
        // cerr << turn << endl;
        // cerr << cur_gpu[3] << endl;
        // // reset counter of game_four
        // if(cur_gpu[3].size() == 1) {
        //     turn = 0;
        // }
    }
}