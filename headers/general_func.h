#ifndef GENERAL_FUNC
#define GENERAL_FUNC                      //проверка на активацию

const int INPUT_FILE_NAME = 1;      //номер имени файла для ввода в argv
const int OUTPUT_FILE_NAME = 2;     //номер имени файла для вывода в argv

const char TOXIC_VALUE = 9;         //ядовитая переменная
char* TOXIC_POINTER = 0;            //ядовитый указатель

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
функция производит выделение памяти под структуру основных данных
*/
onegin_t*   ctor_onegin                     ();

/*
функция открывает файл и возвращает указатель на открытый файл
*/
FILE*       open_file                       (const char *file_name_input, const char *opening_mode);

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
освобождает всю используемую память в программе
*/
void        freedom_of_memory               (onegin_t *data);

#endif      //GENERAL_FUNC
