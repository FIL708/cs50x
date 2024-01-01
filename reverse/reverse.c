#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *inputName = argv[1];
    FILE *input = fopen(inputName, "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", inputName);
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER inputHeader;
    fread(&inputHeader, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    int isFromatRight = check_format(inputHeader);
    if (isFromatRight != 0)
    {
        printf("Wrong format!\n");
        return 3;
    }
    // Open output file for writing
    // TODO #5
    char *outputName = argv[2];
    FILE *output = fopen(outputName, "w");
    if (output == NULL)
    {
        fclose(output);
        fclose(input);
        printf("Could not create %s.\n", outputName);
        return 5;
    }
    // Write header to file
    // TODO #6
    fwrite(&inputHeader, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blockSize = get_block_size(inputHeader);

    // Write reversed audio to file
    // TODO #8
    BYTE block[blockSize];

    fseek(input, blockSize, SEEK_END);
    while (ftell(input) - blockSize > sizeof(WAVHEADER))
    {
        fseek(input, 0 - blockSize * 2, SEEK_CUR);
        fread(block, blockSize, 1, input);
        fwrite(block, blockSize, 1, output);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char signature[4] = {'W', 'A', 'V', 'E'};

    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != signature[i])
        {
            return 1;
        }
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.bitsPerSample * header.numChannels / 8;
}
