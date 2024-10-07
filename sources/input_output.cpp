#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../headers/input_output.h"

//----------------------------------------------------------------------

void read_text (onegin_t *onegin_data, const char *file_name_input)
{
    assert (onegin_data); //TODO assert file_name_input

    onegin_data->file_input = open_file (file_name_input, READ); //TODO READ_B "rb"
    assert (onegin_data->file_input);

    measuring_file_len (onegin_data, onegin_data->file_input);

    read_and_check (onegin_data, onegin_data->file_input);

    fclose (onegin_data->file_input);
}

//----------------------------------------------------------------------

void measuring_file_len (onegin_t *onegin_data, FILE *file)
{
    assert (onegin_data);
    assert (file);

    struct stat stat_onegin = {};
    int check_fstat = fstat (fileno (file), &stat_onegin); //TODO fseek and seek - read
    assert (check_fstat != -1);

    onegin_data->len = (int) stat_onegin.st_size;
}

//----------------------------------------------------------------------

void read_and_check (onegin_t *onegin_data, FILE *file)
{
    assert (onegin_data);
    assert (file);

    onegin_data->text = (char*) calloc ((unsigned int) (onegin_data->len + 1), sizeof (char));
    assert (onegin_data->text);

    int check_len = (int) fread (onegin_data->text, sizeof (char), (size_t) onegin_data->len, file);
    onegin_data->text[onegin_data->len] = '\0';

    if (check_len != onegin_data->len)
    {
        printf ("ERROR\n mismatch between file length and elements read\n");
    }
}

//----------------------------------------------------------------------

void output_text_in_file (onegin_t *onegin_data, const char *file_name_output)
{
    assert (onegin_data);
    assert (onegin_data->pointers_to_lines);

    onegin_data->file_output = open_file (file_name_output, WRITE);
    assert (onegin_data->file_output);

    for (int i = 0; i < onegin_data->number_lines; i++)
    {
        fprintf (onegin_data->file_output ,"%s\n", onegin_data->pointers_to_lines[i].pointers_to_lines_start);
    }

    fclose(onegin_data->file_output);
}

//----------------------------------------------------------------------
