//
// Created by mikarkon on 11.09.22.
//
#include <iostream>
#include "struct.h"

void checkInput(std::istream &in)
{
    if (in.eof())
        throw std::invalid_argument("EOF");
    if (in.bad())
        throw std::invalid_argument("bad");
}

int getDigit(std::istream &in)
{
    int a;
    while(true)
    {
        in >> a;
        checkInput(in);
        if(in.good())
            return a;
        if(in.fail())
        {
            in.clear();
            if(&in == &std::cin)
            std::cout<<"Try again\n";
        }

    }
}

int aboveZero(std::istream &in)
{
    int a = -1;
    while(a < 0)
    {
        a = getDigit(in);
        if(a < 0)
            std::cout << "Try again\n";
    }
    return a;
}

void printArray(int *arr, int len)
{
    for(int i = 0; i < len; i++)
        std::cout<< arr[i] << "   ";
    std::cout << std::endl;
}
void createMx(matrix &mx)
{
    int x = mx.aRows * mx.aCols;
    mx.columnIndex = new int[x];
    mx.value = new int[x];
    mx.rowIndex = new int[mx.aRows + 1];//mx.aRows + 1
    std::fill_n(mx.rowIndex, mx.aRows+1, 0);
    std::fill_n(mx.columnIndex, x, 0);
}

void clearMx(matrix &mx)
{
    delete[] mx.rowIndex;
    delete[] mx.columnIndex;
    delete[] mx.value;
}

int addElement(matrix &mx, int value, int row, int column)
{
    int i, j;
    for (i = mx.rowIndex[row]; i < mx.rowIndex[row + 1]; i++)
        if (mx.columnIndex[i] == column)
        {
            if (value)
            {
                mx.value[i] = value;
                return 1;
            }

            for (j = i; j < (mx.rowIndex[mx.aRows] - 1); j++)
            {
                mx.value[j] = mx.value[j + 1];
                mx.columnIndex[j] = mx.columnIndex[j + 1];
            }
            for (j = row + 1; j < (mx.aRows + 1); j++)
                mx.rowIndex[j]--;
            return 1;
        }
    if(!value)
        return 1;
    for(j = mx.rowIndex[mx.aRows]; j > i; j--)
    {
        mx.value[j] = mx.value[j - 1];
        mx.columnIndex[j] = mx.columnIndex[j - 1];
    }
    int f = 0;
    while(i > 0 && mx.columnIndex[i - 1] > column && (mx.rowIndex[row + 1] - mx.rowIndex[row] - f) > 0)
    {
        mx.value[i] = mx.value[i - 1];
        mx.columnIndex[i] = mx.columnIndex[i - 1];
        i--; f++;
    }
    mx.value[i] = value;
    mx.columnIndex[i] = column;
    for(j = row + 1; j < (mx.aRows + 1); j++)
        mx.rowIndex[j]++;
    return 0;
}

void input(matrix &mx, std::istream &in)
{
    std::cout << "enter amount of rows" << std::endl;
    mx.aRows = 0;
    mx.aRows = aboveZero(in);

    std::cout << "enter amount of columns" << std::endl;
    mx.aCols = 0;
    mx.aCols = aboveZero(in);

    int x = mx.aRows * mx.aCols;
    createMx(mx);

    int k = 0;
    std::cout << "enter amount of nonzero elements" << std::endl;
    k = aboveZero(in);
    while(k > x)
    {
        std::cout << "Try again\n";
        k = aboveZero(in);
    }
    for(int i = 0; i < k; i++)
    {
        int value, column, row;
        std::cout << "enter value row column" << std::endl;
        value = getDigit(in);
        row = getDigit(in);
        while(row < 0 || row >= mx.aRows)
        {
            std::cout << "enter row again\n";
            row = getDigit(in);
        }
        column = getDigit(in);
        while(column < 0 || column >= mx.aCols)
        {
            std::cout << "enter column again\n";
            column = getDigit(in);
        }
        int f = addElement(mx, value, row, column);
        if(f == 1)
            i--;
    }
}

int getElement(matrix &mx, int row, int column)
{
    for (int k = mx.rowIndex[row]; k < mx.rowIndex[row + 1]; k++)
        if (column == mx.columnIndex[k])
            return mx.value[k];

    return 0;
}

void output(matrix &mx)
{
    for(int i = 0; i < mx.aRows; i++)
    {
        for(int j = 0; j < mx.aCols; j++)
            std::cout << getElement(mx, i, j) << "   ";
        std::cout << std::endl;
    }
}

