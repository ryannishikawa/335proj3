// Names: 
// Anthony Le | antlecsuf@csu.fullerton.edu
// Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
// Dylan Tran | dylanht341@csu.fullerton.edu
// Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

//****************************************************************************************************************************
//Program name: "plan_route".  This program calculate the cheapest route from src to dst with at most k stopovers. Copyright (C)           *                                     *
//2025                                                                                                                       *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.                                                                    *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
//****************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author names: Ryan Nishikawa
//  Author emails: ryannishikawa48@csu.fullerton.edu
//  Course ID: CPSC335
//
//Program information
//  Program name: plan_route
//  Due date+time: March 26, 2025 11:59 PM
//  Date of last update: March 25, 2025
//  Programming language(s): C++
//  Files in this program: r2.sh, plan_route.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: done
//
//References for this program
//   lectures, slides
//
//Purpose
//  solve the Array pattern and substrings Problem
//
//This file
//   File name: plan_route.cpp
//   Language: C++
//   Compile: g++ -o target plan_route.cpp
//
//References for this file
//   
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//
//
//===== Begin code area ================================================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <queue>

using namespace std;

int handle_line(const string& line) {
    string val = "";
    for (auto& c : line) {
        if (isdigit(c)) { val += c; }
    }
    return stoi(val);
}

vector<vector<int>> handle_line2(const string& line) {
    vector<vector<int>> res;
    vector<int> row;
    string val = "";
    for (auto& c : line) {
        if (isdigit(c)) { val += c; }
        else if (c == ',' && !val.empty()) { row.push_back(stoi(val)); val.clear(); }
        else if (c == ']' && !val.empty() && !row.empty()) { 
            row.push_back(stoi(val)); 
            val.clear(); 
            res.push_back(row); 
            row.clear(); 
        }
    }
    return res;
}

void print_2Darr (const vector<vector<int>>& arr) {
    cout << "[\n";
    for (int i = 0; i < arr.size(); i++) {
        vector<int> row = arr[i];
        cout << "  [ ";
        for (int j = 0; j < row.size(); j++) { 
            cout << row[j];
            if (j < row.size() - 1) { cout << ", "; }
        }
        cout << " ]";
        if (i < arr.size() - 1) { cout << ","; }
        cout << endl;
    }
    cout << "]" << endl;
}

int plan_route(const vector<vector<int>>& routes, const int& src, const int& dst, const int& k) {
    int where = src;
    int stops = k;
    int cost = 0;
    int min_cost = -1;
    int j = 0;
    for (int i = 0; i < routes.size(); i++) {
        if (routes[i][0] == where) {
            where = routes[i][1];
            cost += routes[i][2];
            j = i + 1;
        }
        if (where == dst && stops >= 0) { 
            if (min_cost == -1) { min_cost = cost; }
            else { min_cost = min(min_cost, cost); }
        }
        else {
            stops--;
            if (stops < 0) { 
                where = src;
                cost = 0;
                stops = k;
                i = j;
             }
        }
    }
    return min_cost;
}

int main() {
    string src_s, dst_s, k_s, routes_s;

    //get input from input2.txt
    cout << "~to run this code with different input, edit \"input2.txt\"\n\n";
    ifstream input("input2.txt");
    if (input.is_open()) {
        //algo start
        while (getline(input, routes_s) && getline(input, src_s) && getline(input, dst_s) && getline(input, k_s)) {
            vector<vector<int>> routes = handle_line2(routes_s); //get data from lines
            int src = handle_line(src_s);
            int dst = handle_line(dst_s);
            int k = handle_line(k_s);

            cout << "\n\nInput: \n";
            cout << "routes = ";
            print_2Darr(routes);
            cout << "src = " << src << endl;
            cout << "dst = " << dst << endl;
            cout << "k = " << k << endl;

            cout << "\nOutput: \n";

            int min_cost = plan_route(routes, src, dst, k); //call function to get output
            cout << "cheapest route = " << min_cost << endl;
        }
        input.close();
    } else { cerr << "Unable to open file" << endl; }

    return 0;
}