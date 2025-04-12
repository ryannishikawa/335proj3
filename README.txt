Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

Algorithm 1: The Spread of Fire in a Forest
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


Algorithm 2: Delivery Route Planning
To run the program:
    1) chmod +x r2.sh
        - to make sure the shell script has permission to execute.
    2) ./r2.sh
        - to run the shell script which compiles and runs the program.
        - compiles the code with g++ -o plan_route plan_route.cpp
    3) Because r2.sh uses input2.txt for input, you can modify the input2.txt file to test different inputs.

    4) If you want to enter input by hand you can run the program directly from the terminal using the following command: ./plan_route < input2.txt
        - if that doesn't work make sure the the file was compiled correctly by running the following command: g++ -o plan_route plan_route.cpp
        - also make sure the file has execute permissions by running the following command: chmod +x plan_route

Input Format
    The program reads the following inputs:
        routes = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
        src = 0
        dst = 2
        k = 1

        or 

        routes = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
        src = 0
        dst = 2
        k = 1
        routes = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
        src = 0
        dst = 2
        k = 0

Expected Output
    Input:
    routes = [
      [ 0, 1, 100 ],
      [ 1, 2, 100 ],
      [ 0, 2, 500 ]
    ]
    src = 0
    dst = 2
    k = 1

    Output:
    cheapest route = 200


    Input:
    routes = [
      [ 0, 1, 100 ],
      [ 1, 2, 100 ],
      [ 0, 2, 500 ]
    ]
    src = 0
    dst = 2
    k = 0

    Output:
    cheapest route = 500
