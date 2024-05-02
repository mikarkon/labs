//
// Created by mikarkon on 12.09.22.
//
#include "struct.h"
#include "funcs.h"

int sumOfNumbers(int x)
{
    int res = 0;
    while(x)
    {
        res = res + x%10;
        x = x/10;
    }
    return res;
}
void formRes(matrix &res, matrix &mx)
{
    res.aRows = mx.aRows;
    res.aCols = mx.aCols;
    createMx(res);
    for (int i = 0; i < mx.aRows; i++)
    {
        if (mx.rowIndex[i] != mx.rowIndex[i + 1])
        {
            for (int j = 0; j < mx.aCols; j++)
            {
                int el = getElement(mx, i, j);
                if (sumOfNumbers(el) == sumOfNumbers(mx.value[(mx.rowIndex[i + 1] - 1)]))
                    addElement(res, el, i, j);
            }
        }
    }
}