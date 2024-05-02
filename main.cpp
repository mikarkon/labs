#include <iostream>
#include "funcs.h"
#include "forRes.h"

int main() {

    matrix mx;
    mx.value = nullptr;
    mx.rowIndex = nullptr;
    mx.columnIndex = nullptr;
    matrix res;
    try
    {
        input(mx, std::cin);
        output(mx);
        std::cout << std::endl;
        std::cout << "\nrow index array" << std::endl;
        printArray(mx.rowIndex, mx.aRows + 1);
        std::cout << "column index array" << std::endl;
        printArray(mx.columnIndex, mx.rowIndex[mx.aRows]);
        std::cout << "values" << std::endl;
        printArray(mx.value, mx.rowIndex[mx.aRows]);
        std::cout << std::endl;
        formRes(res, mx);
        output(res);
        clearMx(mx);
        clearMx(res);
    }
    catch (const std::exception &msg)
    {
        clearMx(mx);
        std::cout << msg.what() << std::endl;
    }
    return 0;
}
