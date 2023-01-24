#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    // check if the file is valid
    FILE *inFile = fopen(argv[1], "r");
    if (inFile == NULL)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    // varialbles
    BYTE Buffer[512];
    char filename[8];
    int fileCounter = 0;
    FILE *img = NULL;

    while (fread(Buffer, 512, sizeof(char),  inFile) == 1)
    {
        // check the start of a photo
        if (Buffer[0] == 0xff && Buffer[1] == 0xd8 && Buffer[2] == 0xff && (Buffer[3] & 0xf0) == 0xe0)
        {
            if (!(fileCounter == 0))
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", fileCounter);
            img = fopen(filename, "w");
            fileCounter++;
        }
        // check if JPG has been found , write to file
        if (!(fileCounter == 0))
        {
            fwrite(Buffer, 512, sizeof(char), img);
        }
    }
    fclose(img);
    fclose(inFile);
    return 0;
}