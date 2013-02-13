#include <stdio.h>
#include "files.h"

int main()
{

    FILE *file1 = fopen("file1.txt", "r");
    FILE *file2 = fopen("file2.txt", "r");
    FILE *file3 = fopen("file3.txt", "w");

    filesProcessing(file1, file2, file3);

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}
