#include "Test_Password/Test_Password.h"
#include <stdio.h>

int main()
{
    int result = test_password();
    if(result == -1)
        printf("Failed Tests!");
    else
        printf("Passed Tests!");
}
