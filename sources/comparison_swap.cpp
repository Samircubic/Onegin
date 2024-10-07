#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../headers/comparison_swap.h"

//----------------------------------------------------------------------

void sort_strings_in_ascending_order (onegin_t *onegin_data) //TODO stack to friday
{
    assert (onegin_data); //TODO assert

    for (int j = 0; j < onegin_data->number_lines; j++)
    {
        for (int i = 0; i < onegin_data->number_lines - j - 1; i++)
        {
            comparing_and_replacing_strings (onegin_data, i);
        }
    }
}

//----------------------------------------------------------------------

void comparing_and_replacing_strings (onegin_t *onegin_data, int comparable)
{
    assert (onegin_data);
    assert (onegin_data->pointers_to_lines);

    if (reverse_comparator (onegin_data->pointers_to_lines[comparable].pointers_to_lines_start, onegin_data->pointers_to_lines[comparable + 1].pointers_to_lines_start, onegin_data->pointers_to_lines[comparable].pointers_to_lines_end, onegin_data->pointers_to_lines[comparable + 1].pointers_to_lines_end) > 0 )
    {
        swap_pointers_line (onegin_data, comparable);
    }
}

//----------------------------------------------------------------------

void swap_pointers_line (onegin_t *onegin_data, int comparable) //TODO rename comparable
{
    char* temporary = 0;
    temporary = onegin_data->pointers_to_lines[comparable].pointers_to_lines_start;
    onegin_data->pointers_to_lines[comparable].pointers_to_lines_start = onegin_data->pointers_to_lines[comparable + 1].pointers_to_lines_start;
    onegin_data->pointers_to_lines[comparable + 1].pointers_to_lines_start = temporary;
}

//----------------------------------------------------------------------

int reverse_comparator (char *line_1_start, char *line_2_start, char *line_1_end, char *line_2_end)
{
    assert (line_1_start);
    assert (line_2_start);
    assert (line_1_end);
    assert (line_2_end);

    int i_1 = 0;
    int i_2 = 0;
    while (1)
    {
        // if (&line_1_end[i_1] == &line_1_start[0] && &line_2_end[i_2] == &line_2_start[0])
        // {
        //     return 0;
        // }
        // else if (&line_1_end[i_1] == &line_1_start[0])
        // {
        //     return -1;
        // }
        // else if (&line_2_end[i_2] == &line_2_start[0])
        // {
        //     return 1;
        // }
        if (line_1_end[i_1] == ' ' || line_1_end[i_1] == ',' ||  line_1_end[i_1] == '?' || line_1_end[i_1] == '!' || line_1_end[i_1] == '.' || line_1_end[i_1] == ':') //TODO libfunc
        {
            i_1--;
        }
        else if (line_2_end[i_2] == ' ' || line_2_end[i_2] == ',' ||  line_2_end[i_2] == '?' || line_2_end[i_2] == '!' || line_2_end[i_2] == '.' || line_2_end[i_2] == ':')
        {
            i_2--;
        }
        else
        {
            if (line_1_end[i_1] > line_2_end[i_2])
            {
                printf ("%s\n", line_1_start);
                printf ("%s\n", line_2_start);
                printf ("%d", i_1);
                printf ("%d", i_2);
                printf ("1");
                printf ("\n");
                return 1;
            }
            else if (line_1_end[i_1] < line_2_end[i_2])
            {
                printf ("%s\n", line_1_start);
                printf ("%s\n", line_2_start);
                printf ("%d", i_1);
                printf ("%d", i_2);
                printf ("-1");
                printf ("\n");
                return -1;
            }
            else if (line_1_end[i_1] == '\0' && line_2_end[i_2] == '\0')
            {
                printf ("%s\n", line_1_start);
                printf ("%s\n", line_2_start);
                printf ("%d", i_1);
                printf ("%d", i_2);
                printf ("0");
                printf ("\n");
                return 0;
            }

            i_1--;
            i_2--;
        }
    }

    return 0;
}

//----------------------------------------------------------------------
