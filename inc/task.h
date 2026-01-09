/*!
    \file task.h
    \author Фамилия И.О.
    \date 1 Января 2025
    \brief Заголовочный файл-образец с описанием прототипов реализуемых функций

    Данный файл содержит в себе описание прототипов реализуемых функций,
    которые демонстрируют решение следующих задач:
    - Задача 1: Здесь приводится описание Задачи 1
    - Задача 2: Здесь приводится описание Задачи 2

    Примечание: Данный файл является шаблоном-образцом для редактирования
*/

// Указание директивой препроцессора однократного подключения
#pragma once

#include <stdio.h>

#ifdef __linux__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"
#endif
/*!
    Макро-функция обработчик форматированного логгирования ошибок
    \param[in] code Код ошибки
    \param[in] ... Пояснение ошибки (может быть форматированным сообщением с аргументами)
*/
#define ERR_LOGGING(code,...) \
    fprintf(stderr, "\n\033[1;41m\n"); \
    fprintf(stderr, "Error:\t" __VA_ARGS__ ); \
    fprintf(stderr, \
	"\nCode:\t0x%08X\n" \
	"File:\t%s\n" \
	"Line:\t%d\033[0m\n", \
	code, \
	__FILE__,__LINE__ \
    ); \
    fprintf(stderr, "\033[0m\n");

#ifdef __linux__
#pragma GCC diagnostic pop
#endif

//
// Задача 1
//
#ifdef TASK1
/*!
    \defgroup TASK1_GROUP Группа идентификаторов Задачи 1
    @{
*/

/*!
    \brief Код ошибки: Успешное завершение работы программы
*/
#define TASK1_CODE_NO_ERROR			0x0
/*!
    \brief Код ошибки: Самотестирование завершено некорректно
*/
#define TASK1_CODE_SELFTEST_ERROR		0x1
/*!
    \brief Код ошибки: Отсутствует входной файл для обработки (или задан пользователем некорректно)
*/
#define TASK1_CODE_NO_INPUT_FILE		0x1001
/*!
    \brief Код ошибки: Отсутствует выходной файл для обработки (или задан пользователем некорректно)
*/
#define TASK1_CODE_NO_OUTPUT_FILE		0x1002
/*!
    \brief Код ошибки: Ошибочные дополнительные входные данные (запрашиваемые в дополнение ко входному файлу)
*/
#define TASK1_CODE_INCORRECT_ADV_DATA		0x1003
/*!
    \brief Код ошибки: Ошибочные входные данные файла для обработки (файл пуст или данные некорректны)
*/
#define TASK1_CODE_INCORRECT_INPUT_FILE		0x1004
/*!
    \brief Код ошибки: Неприменимые данные для обработки (по входящим данным не может быть проведено вычисление)
*/
#define TASK1_CODE_INCORRECT_CONFIGURATION	0x1005
/*!
    \brief Код ошибки: Ошибка при проведении  вычислений (в процессе выполнения)
*/
#define TASK1_CODE_INCORRECT_CALCULATION	0x1006
/*!
    \brief Код ошибки: Ошибка при проведении выделения памяти
*/
#define TASK1_CODE_INCORRECT_MEM_ALLOCATION	0x1007

/*!
    Функция решения задачи 1
    \param[in] filename Наименование входного файла для обработки
    \return Результат выполнения операции (в соответствии с описанными кодами возврата)
*/
int func_task1(const char* filename);

/*! @} */

#endif // TASK1


//
// Задача 2
//
#ifdef TASK2
/*!
    \defgroup TASK2_GROUP Группа идентификаторов Задачи 2
    @{
*/

/*!
    \brief Код ошибки: Успешное завершение работы программы
*/
#define TASK2_CODE_NO_ERROR			0x0
/*!
    \brief Код ошибки: Самотестирование завершено некорректно
*/
#define TASK2_CODE_SELFTEST_ERROR		0x1
/*!
    \brief Код ошибки: Отсутствует входной файл для обработки (или задан пользователем некорректно)
*/
#define TASK2_CODE_NO_INPUT_FILE		0x2001
/*!
    \brief Код ошибки: Отсутствует выходной файл для обработки (или задан пользователем некорректно)
*/
#define TASK2_CODE_NO_OUTPUT_FILE		0x2002
/*!
    \brief Код ошибки: Ошибочные дополнительные входные данные (запрашиваемые в дополнение ко входному файлу)
*/
#define TASK2_CODE_INCORRECT_ADV_DATA		0x2003
/*!
    \brief Код ошибки: Ошибочные входные данные файла для обработки (файл пуст или данные некорректны)
*/
#define TASK2_CODE_INCORRECT_INPUT_FILE		0x2004
/*!
    \brief Код ошибки: Неприменимые данные для обработки (по входящим данным не может быть проведено вычисление)
*/
#define TASK2_CODE_INCORRECT_CONFIGURATION	0x2005
/*!
    \brief Код ошибки: Ошибка при проведении  вычислений (в процессе выполнения)
*/
#define TASK2_CODE_INCORRECT_CALCULATION	0x2006
/*!
    \brief Код ошибки: Ошибка при проведении выделения памяти
*/
#define TASK2_CODE_INCORRECT_MEM_ALLOCATION	0x2007

/*!
    Функция решения Задачи 2
    \param[in] filename Наименование входного файла для обработки
    \param[in] x_value Значение искомой точки
    \param[in] N_value Значение искомой точности считывания
    \return Результат выполнения операции (в соответствии с описанными кодами возврата)
*/
int func_task2(const char* filename, double x, int N);

/*! @} */

#endif // TASK2