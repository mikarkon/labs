#include <iostream>
#include "element.h"
#include "dialog.h"
int main()
{
    table tbl;
    while(true)
    {
        try {
            int rc = 1;
            while (rc) {
                dialog::dialog(msgs, msgsAmount, rc);
                if (!rc)
                    break;
                dialog::funcArr[rc](tbl, std::cout);
            }
            if (!rc)
                break;
        }
        catch (const std::invalid_argument &ex) {
            std::cout << ex.what() << std::endl;
            break;
        }
        catch (const std::exception &ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}
