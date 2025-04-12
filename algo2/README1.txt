Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

To run the program:
    1) chmod +x r1.sh
        - to make sure the shell script has permission to execute.
    2) ./r1.sh
        - to run the shell script which compiles and runs the program.
        - compiles the code with g++ -o forest_fire forest_fire.cpp
    3) Because r1.sh uses input.txt for input, you can modify the input.txt file to test different inputs.

    4) If you want to enter input by hand you can run the program directly from the terminal using the following command: ./forest_fire < input.txt
        - if that doesn't work make sure the the file was compiled correctly by running the following command: g++ -o forest_fire forest_fire.cpp
        - also make sure the file has execute permissions by running the following command: chmod +x forest_fire

Input Format
    The program reads the following inputs:
    The first line represents the rows and columns, respectively.
    The rest of the lines are the grid with the values representing burned trees, healthy trees, and empty areas.
        3 3
        2 1 1
        1 1 0
        0 1 1

Expected Output
    4
