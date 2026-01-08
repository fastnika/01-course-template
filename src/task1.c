/*!
    \file task1.c
    \author Фамилия И.О.
    \date 1 Января 2025
    \brief Файл-образец с описанием функции для реализации Задачи 1

    Примечание: Данный файл является шаблоном-образцом для редактирования
*/

#include "task.h"

/*!
     Функция решения Задачи 1
     \param[in] filename Наименование входного файла для обработки
     \return Результат выполнения операции (в соответствии с описанными кодами возврата)
*/
int func_task1(const char* filename)
{
    FILE *fin = NULL;   // указатель на файл данных

    //
    // Предварительная проверка работы с файлом
    //
    fin = fopen(filename, "r");
    if(!fin)
    {
	ERR_LOGGING(TASK1_CODE_NO_INPUT_FILE, "Error opening file %s", filename);
	return TASK1_CODE_NO_INPUT_FILE;
    }

    //
    // Алгоритм обработки данных
    //


    //
    // Завершение работы
    //
    return TASK1_CODE_NO_ERROR;
}