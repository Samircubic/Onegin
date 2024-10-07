#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../headers/general_func.h"

//----------------------------------------------------------------------

onegin_t* ctor_onegin ()
{
    onegin_t *onegin_data = (onegin_t*) calloc (creating_one_strust, sizeof (onegin_t)); //TODO rename caps - creating_one_strust
    assert (onegin_data);

    return onegin_data;
}

//----------------------------------------------------------------------

void creating_pointers (onegin_t *onegin_data)
{
    assert (onegin_data); //TODO assert onegin_data->text

    measuring_the_number_lines (onegin_data);

    creation_pointers_onegin (onegin_data);
}

//----------------------------------------------------------------------

void measuring_the_number_lines (onegin_t *onegin_data)
{
    assert (onegin_data);
    assert (onegin_data->text);

    for (int i = 0; i < onegin_data->len; i++)
    {
        if (onegin_data->text[i] == '\n')
        {
            onegin_data->number_lines += 1;
        }
    }
}

//----------------------------------------------------------------------

void creation_pointers_onegin (onegin_t *onegin_data)
{
    assert (onegin_data);
    assert (onegin_data->text);

    onegin_data->pointers_to_lines = (pointers_start_end_t*) calloc ((unsigned int) onegin_data->number_lines, sizeof (pointers_start_end_t));
    assert (onegin_data->pointers_to_lines);

    int j = 0;
    int line_number = 0;
    for (int i = 0; i < onegin_data->len - 1; i++)
    {
        if (onegin_data->text[i] == '\r')
        {
            if (onegin_data->text[i - 1] != ' ' && onegin_data->text[i - 1] != '\r' && onegin_data->text[i - 1] != '\0') //FIXME
            {
                onegin_data->pointers_to_lines[line_number].pointers_to_lines_start = &onegin_data->text[i - j];
                onegin_data->pointers_to_lines[line_number].pointers_to_lines_end   = &onegin_data->text[i - 1];
                line_number++;
                j = -2; //TODO const func skip_symbols()
            }
            else
            {
                onegin_data->number_lines--;
            }
        }
        j++;
    }

    resetting_transfers (onegin_data); //TODO вынести в другое место
}

//----------------------------------------------------------------------

void resetting_transfers (onegin_t *onegin_data)        //проблема с последней пустой строкой решилась через \0
{
    for (int i = 0; i < onegin_data->len; i++)
    {
        if (onegin_data->text[i] == '\r' || onegin_data->text[i] == '\n')
        {
            onegin_data->text[i] = '\0';
        }
    }
}

//----------------------------------------------------------------------

FILE* open_file (const char *file_name_input, const char *opening_mode)
{
    assert (file_name_input); //TODO assert

    FILE *file = fopen (file_name_input, opening_mode);
    assert (file);

    return file;
}

//----------------------------------------------------------------------

void freedom_of_memory (onegin_t *onegin_data)
{
    assert (onegin_data);
    assert (onegin_data->text);
    assert (onegin_data->pointers_to_lines);

    for (int i = 0; i < onegin_data->len; i++)
    {
        onegin_data->text[i] = TOXIC_VALUE;
    }

    for (int i = 0; i < onegin_data->number_lines; i++)
    {
        onegin_data->pointers_to_lines[i].pointers_to_lines_start = TOXIC_POINTER;
    }

    free (onegin_data->text);
    free (onegin_data->pointers_to_lines);
    free (onegin_data);
}

//----------------------------------------------------------------------


// запуск через make
