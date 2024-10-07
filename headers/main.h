#ifndef MAIN_H
#define MAIN_H                      //проверка на активацию

const int INPUT_FILE_NAME = 1;      //номер имени файла для ввода в argv
const int OUTPUT_FILE_NAME = 2;     //номер имени файла для вывода в argv

const int creating_one_strust = 1;  //создание одной структуры в одном элементе массива

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
функция производит все операции связанные с вводом данных
открытие, считывание длинны, создание стека памяти для текста и передает сам текст из файла в массив
*/
void        read_text                       (onegin_t *data, const char *file_name_input);

/*
функция производит выделение памяти под структуру основных данных
*/
onegin_t*   ctor_onegin                     ();

/*
функция открывает файл и возвращает указатель на открытый файл
*/
FILE*       open_file                       (const char *file_name_input, const char *opening_mode);

/*
функция измеряет длинну файла на который указывает переданый указатель
*/
void        measuring_file_len              (onegin_t *data, FILE *file);

/*
функция производит непосредственное считыание данных из файла и проверяет коректность считывания
*/
void        read_and_check                  (onegin_t *data, FILE *file);

/*
функция пустем простых манипуляций создает массив указатель на отдельные строчки
*/
void        creating_pointers               (onegin_t *data);

/*
функция определяет количество строчек в файле
*/
void        measuring_the_number_lines      (onegin_t *data);

/*
непосредственно создает указатели
*/
void        creation_pointers_onegin        (onegin_t *data);

/*
все элементы связанные с переходом на новую строчку заменятются \0
*/
void        resetting_transfers             (onegin_t *onegin_data);

/*
функция отвечает за вывод отсортированного текста в файл
*/
void        output_text_in_file             (onegin_t *data, const char *file_name_output);

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

/*
освобождает всю используемую память в программе
*/
void        freedom_of_memory               (onegin_t *data);

#endif      //MAIN_H
