#include <iostream>
#include "dialog.h"
#include "LemBer.h"

int main()
{
    LemBer f(0, -1);
    int rc = 1;
    while(rc)
    {
        try
        {
            dialog::dialog(msgs, msgsAmount, rc);
            if(!rc)
                break;
            dialog::funcArr[rc](f);
        }
        catch (const std::runtime_error &ex)
        {
            std::cout << ex.what() << std::endl;
            break;
        }
    }
    return 0;
}
