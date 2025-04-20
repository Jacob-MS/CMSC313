
Author: Jacob Shamer
Course: CMSC 313
Time Slot: 10:00AM MON/WED

Purpose:
A c++ and c program to create and solve Matrix Arithmetic
Matrix interactions include: 
matrix additition, matrix subtraction, scalar matrix multiplication, matrix multiplication, and matrix transposition


Files:
matrix.cpp - houses a Matrix class which holds all the functions necessary for matrix aritmetic
matrix.c - 


Build Instructions:
IDE: VS Code

matrix.cpp:

g++ matrix.cpp -o matrixtestcpp
./matrixtestcpp.exe

matrix.c:

gcc -std=c99 -m32 matrix.c -o matrixtestc
./matrixtestc.exe

Additional Information:
When I try to compile matrix.c I get no error messages with the program,
but I think maybe I'm missing something to properly compile and I don't really know how to fix it
I think the program should work but I'm unable to test, can't figure out why the default parameters are causing issues during compilation,
since they should be getting replaced anyway
