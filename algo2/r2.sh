#/bin/bash

#Program name "plan_route.cpp"
#Author: R. Nishikawa
#This file is the script file that accompanies the "plan_route.cpp" program.
#Prepare for execution in normal mode (not gdb mode).

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile the source file plan_route.cpp and make an executable file"
g++ -o plan_route plan_route.cpp

#give the program permission to execute
chmod +x plan_route

#run the program for all 10 test cases
echo "Run the program plan_route with test cases and output to terminal"

echo "running test case 1"
./plan_route < input2.txt
echo "done"

echo "This bash script will now terminate."
