#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "../headers/main.h"

//----------------------------------------------------------------------

int main (int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf ("Invalid input, check the input format\n");
        return 0;
    }

    onegin_t *onegin_data = ctor_onegin ();                         // dtor

    const char *file_name_input  = argv[INPUT_FILE_NAME];                 // извлечение имени нужного нам файла(для чтения) в структуру данных
    const char *file_name_output = argv[OUTPUT_FILE_NAME];                // извлечение имени нужного нам файла(для вывода) в структуру данных

    read_text (onegin_data, file_name_input); //TODO rename
    assert (onegin_data->text);

    creating_pointers (onegin_data);

    sort_strings_in_ascending_order (onegin_data);

    output_text_in_file (onegin_data, file_name_output);

    freedom_of_memory (onegin_data);

    return 0;
}

//----------------------------------------------------------------------
