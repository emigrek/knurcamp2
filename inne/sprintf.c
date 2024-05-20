#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char* buffer = malloc(1024);

    sprintf(buffer, "%s = %d", "1", 2);
    
    printf("%s\n", buffer);

    free(buffer);
    return 0;
}