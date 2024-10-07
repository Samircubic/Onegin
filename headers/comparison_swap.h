#ifndef COMPARISON_SWAP
#define COMPARISON_SWAP                      //проверка на активацию

typedef struct pointers_start_end
{
    char *pointers_to_lines_start;
    char *pointers_to_lines_end;
} pointers_start_end_t;

typedef struct onegin
{
    char *text;                                     //< буфер в котором храниться весь считаный текст
    pointers_start_end_t *pointers_to_lines;        //< указатели на отдельные строчки онегина
    int   number_lines;                             //< количество строчек в онегине
    int   len;                                      //< длинна в количествах символов
    FILE *file_input;                               //< указатель на файл считывания
    FILE *file_output;                              //< указатель на файл вывода
} onegin_t;

//----------------------------------------------------------------------

/*
непосредствено производит сортировку строчек
*/
void        sort_strings_in_ascending_order (onegin_t *data);

/*
производит сравнивание двух переданых строчек
*/
void        comparing_and_replacing_strings (onegin_t *data, int comparable);

/*
производит swap двух переданных указателей на стровки
*/
void        swap_pointers_line              (onegin_t *onegin_data, int comparable);

/*
сравнение букв в двух переданых строчках в боратном порядке
*/
int         reverse_comparator              (char *line_1_start, char *line_2_start, char *line_1_end, char *line_2_end);

#endif      //COMPARISON_SWAP
