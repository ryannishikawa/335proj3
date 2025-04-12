// Names: 
// Anthony Le | antlecsuf@csu.fullerton.edu
// Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
// Dylan Tran | dylanht341@csu.fullerton.edu
// Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

//*********************************************************************************************************************************
//Program name: "forest_fire".  This program solves the Spread of Fire in a Forest Problem. Copyright (C)*
//2025                                                                                                                            *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License       *
//version 3 as published by the Free Software Foundation.                                                                         *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied              *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.          *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                                *
//*********************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author names: Dylan Tran, Anthony Le
//  Author emails: dylanht341@csu.fullerton.edu, antlecsuf@csu.fullerton.edu
//  Course ID: CPSC335
//
//Program information
//  Program name: forest_fire
//  Due date+time: April 11, 2025 11:59 PM
//  Date of last update: April 11, 2025
//  Programming language(s): C++
//  Files in this program: r1.sh, forest_fire.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: done
//
//References for this program
//   lectures, slides, cppreference.com
//
//Purpose
//  Solves the Spread of Fire in a Forest Problem.
//
//This file
//   File name: forest_fire.cpp
//   Language: C++
//   Compile: g++ -o forest_fire forest_fire.cpp
//
//References for this file
//   cppreference.com
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//
//
//===== Begin code area ================================================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

// Directions for spaces around a coordinate
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minDaysToBurn(vector<vector<int>>& forest) {
    // If forest is empty, return -1
    if (forest.empty() || forest[0].empty()) {
        return -1;
    }

    int rows = forest.size();
    int cols = forest[0].size();
    queue<pair<int, int>> queue;    // Queue to store burned trees
    int healthyTrees = 0;           // Count of healthy trees
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (forest[i][j] == 2) {        // Push burned tree location to queue
                queue.push({i, j});
            }
            if (forest[i][j] == 1) {        // Count healthy trees
                healthyTrees++;
            }
        }
    }

    // If there are no burned trees, return -1
    if (queue.empty()) {
        return -1;
    }

    int days = 0;           // Count of days passed
    int burnedTrees = 0;    // Count of burned trees

    while (!queue.empty()) {
        int size = queue.size();

        // For each tree burning on this day
        for (int i = 0; i < size; ++i) {
            auto [x, y] = queue.front();
            queue.pop();

            // Check positions around burned tree location
            for (const auto& [dx, dy] : dirs) {
                int newX = x + dx;
                int newY = y + dy;

                // If it's within the grid's bounds and a healthy tree
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && forest[newX][newY] == 1) {
                    forest[newX][newY] = 2;         // Burn healthy tree
                    queue.push({newX, newY});       // Push to queue to check around it the next day
                    burnedTrees++;                  // Increment burned tree count
                }
            }
        }
        // If trees were burned, increment day count
        if (!queue.empty()) {
            days++;
        }
    }

    // If trees burned does not match original count of healthy trees, return -1
    if (burnedTrees != healthyTrees) {
        return -1;
    }

    return days;
}

int main() {
    ifstream infile("input.txt");
    
    if (!infile) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }
    
    int rows, cols;
    infile >> rows >> cols;
    
    vector<vector<int>> forest(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> forest[i][j];
        }
    }

    cout << minDaysToBurn(forest) << endl;

    return 0;
}
