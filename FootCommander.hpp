//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_FOOTCOMMANDER_HPP
#define UNTITLED5_FOOTCOMMANDER_HPP


#include "Soldier.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include <iostream>
#include <math.h>

class FootCommander : public FootSoldier {
public:
    // int health_points;
    // int damage_per_activity;
public:
    FootCommander(int playerNum) : FootSoldier(playerNum, 20, 150) {
        std::cout << "Foot Commander built for player:" << playerNum << std::endl;
    };

    void full_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                     std::pair<int, int> placeOfSoldier)  // need to check how use override keyword
    {
        std::cout << "perform FootCommander full_action" << std::endl;
        int &x = placeOfSoldier.first;
        int &y = placeOfSoldier.second;
        board[x][y]->basic_action(board, PlayerToAttack, placeOfSoldier);
    //commander attacked, now his soldiers:
        std::cout << "-= Perform FootSoldierS basic full_action by commander order =-" << std::endl;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j] != this && board[i][j]->playerNum != PlayerToAttack) { // if soldier isn't belong to enemy and isn't the commander himself
                    if (board[i][j] = dynamic_cast<FootSoldier *>(board[i][j])) {
                        std::cout << "FootSoldier at: " << i << "," << j
                                  << " performing basic full_action by commander order" << std::endl;
                        std::pair<int, int> loc = {i, j};
                        board[i][j]->basic_action(board, PlayerToAttack, loc);
                    }
                }
            }
        }
    }

};


#endif //UNTITLED5_FOOTCOMMANDER_HPP
