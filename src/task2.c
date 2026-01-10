/*!
    \file task2.c
    \author Фамилия И.О.
    \date 1 Января 2025
    \brief Файл-образец с описанием функции для реализации Задачи 2

    Примечание: Данный файл является шаблоном-образцом для редактирования
*/

#include "task.h"
#include <float.h>
#include <math.h>

/*!
    Функция решения Задачи 2
    \param[in] filename Наименование входного файла для обработки
    \param[in] x_value Значение искомой точки
    \param[in] N_value Значение искомой точности считывания
    \return Результат выполнения операции (в соответствии с описанными кодами возврата)
*/
int func_task2(const char* filename, double x, int N)
{
    FILE *fin = NULL; // указатель на файл данных
    
    //
    // Предварительная проверка работы с файлом
    //
    if(fabs(x) < DBL_EPSILON)
    {
	ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Значение x (%g) некорректно", x);
	return TASK2_CODE_INCORRECT_ADV_DATA;
    }
    
    if(N <= 0)
    {
	ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Значение N (%d) некорректно", N);
	return TASK2_CODE_INCORRECT_ADV_DATA;
    }

    fin = fopen(filename, "r");
    if(!fin)
    {
	ERR_LOGGING(TASK2_CODE_NO_INPUT_FILE, "Ошибка открытия файла %s", filename);
	return TASK2_CODE_NO_INPUT_FILE;
    }


    //
    // Проверка допустимости работы данных
    //


    //
    // Алгоритм обработки данных
    //


    //
    // Завершение работы
    //

    fclose(fin);

    return TASK2_CODE_NO_ERROR;
}
