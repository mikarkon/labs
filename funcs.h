//
// Created by mikarkon on 11.09.22.
//

#ifndef LAB1_FUNCS_H
#define LAB1_FUNCS_H
#include "struct.h"
#include <iostream>

int addElement(matrix &mx, int value, int row, int column);
int getElement(matrix &mx, int row, int column);
void input(matrix &mx, std::istream  &in);
void output(matrix &mx);
void clearMx(matrix &mx);
void createMx(matrix &mx);
void printArray(int *arr, int len);
#endif //LAB1_FUNCS_H
