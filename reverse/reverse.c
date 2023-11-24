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
        printf("usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {   fclose(input);
        printf("cannot open input file\n");
        return 2;
    }
    // Read header
    // TODO #3
    WAVHEADER HEADER;
    fread(&HEADER, sizeof(WAVHEADER), 1, input);


    // Use check_format to ensure WAV format
    // TODO #4
    check_format(HEADER);
    if (check_format(HEADER) == 1)
    {
        fclose(input);
        return 3;
    }


    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {   fclose(input);
        fclose(output);
        printf("output file is not in the correct format\n");
        return 3;
    }
    // Write header to file
    // TODO #6
    fwrite(&HEADER, sizeof(WAVHEADER), 1, output);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(HEADER);
    // Write reversed audio to file
    // TODO #8
    int headerposition = ftell(input);
    fseek(input, block_size, SEEK_END);

    BYTE buffer[block_size];

   while ((ftell(input) - block_size) > headerposition)
   {
        fseek(input, -2 * block_size, SEEK_CUR);
        fread(&buffer, block_size, 1, input);
        fwrite(&buffer, block_size, 1, output);
   }

 
    fclose(input);
    fclose(output);
}










int check_format(WAVHEADER header)
{
    char WAVE[] = {'W', 'A', 'V', 'E'};
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != WAVE[i])
        {
            printf("file is not a wav file\n");

            return 1;
        }
    }
    // TODO #4

    return 0;
}

int get_block_size(WAVHEADER header)
{
    int blocksize = (header.numChannels) * (header.bitsPerSample / 8);
    // TODO #7 number of channels multiplied by bytes per sample.

    return blocksize;
}
