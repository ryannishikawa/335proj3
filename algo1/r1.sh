#/bin/bash

# Names: 
# Anthony Le | antlecsuf@csu.fullerton.edu
# Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
# Dylan Tran | dylanht341@csu.fullerton.edu
# Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

#Program name "forest_fire.cpp"
#Author: D. Tran, Anthony Le
#This file is the script file that accompanies the "forest_fire.cpp" program.
#Prepare for execution in normal mode (not gdb mode).

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile the source file forest_fire.cpp and make an executable file"
g++ -o forest_fire forest_fire.cpp

#give the program permission to execute
chmod +x forest_fire

#run the program
echo "Running the program 'forest_fire' with input from input.txt"
./forest_fire < input.txt

echo -e "\nThis bash script will now terminate."