Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

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
