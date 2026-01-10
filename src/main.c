 /*!
     \file main.c
     \author Фамилия И.О.
     \date 1 Января 2025
     \brief Файл-образец с описанием головной функций main()

     Примечание: Данный файл является шаблоном-образцом для редактирования
*/

#include "task.h"

/*!
    Головная функция (точка входа в программу)
*/
int main(void)
{
//
// Задача 1 (Вариант реализации функции для файла данных)
// Примечание: Дополнительные параметры (данные) могут быть заданы в самом входном файле
//
#ifdef TASK1
#ifdef SELFTEST
    //
    // Автоматизированное тестирование реализации функции
    //
    printf("\033[1;44mРЕЖИМ РАБОТЫ: Задача 1 (самотестирование)\033[0m\n");

/*!
    Макро-функция тестирования реализации функции func_task1()
    \param[in] test_name Имя теста (префикс)
    \param[in] input_file Локальный путь к входному имени файла
    \param[in] waiting_code Ожидаемый код завершения теста
*/
#define RUN_SELFTEST(test_name, input_file, waiting_code) \
    { \
    int return_code; \
    if((return_code = func_task1(input_file)) == waiting_code) \
    { \
	printf("> \033[1;33m"test_name"\033[0m - \033[1;42m УСПЕХ \033[0m "); \
	printf("(код возврата - 0x%08X)\n", waiting_code); \
    } \
    else \
    { \
	printf("> \033[1;33m"test_name"\033[0m - \033[1;41m ПРОВАЛ \033[0m "); \
	printf("(ожидаемый код возврата - 0x%08X, код возврата - 0x%08X)\n", waiting_code, return_code); \
	return TASK1_CODE_SELFTEST_ERROR; \
    } \
    }

    // Тест 1 : Отсутствующий входной файл
    RUN_SELFTEST("TEST1", "test_miss.txt", TASK1_CODE_NO_INPUT_FILE);
    // Тест 2 : Пустой входной файл (неверное число данных для обработки)
    RUN_SELFTEST("TEST2", "./test/task1/test1.txt", TASK1_CODE_INCORRECT_INPUT_FILE);
    // Тест 3 : Ошибочные данные в входном файле (неверное число данных для обработки)
    RUN_SELFTEST("TEST3", "./test/task1/test1.txt", TASK1_CODE_INCORRECT_INPUT_FILE);
    // Тест 4 : Конфигурация данных не может быть обработана
    RUN_SELFTEST("TEST4", "./test/task1/test2.txt", TASK1_CODE_INCORRECT_CONFIGURATION);

#undef RUN_SELFTEST

    // Завершение работы
    printf("\n\033[1;44mВЫПОЛНЕНО\033[0m\n");
    return TASK1_CODE_NO_ERROR;
#else
    //
    // Пользовательское взаимодействие (User Interface)
    //
    char filein[255] = { 0 };
    
    printf("\033[1;46mРЕЖИМ РАБОТЫ: Задача 1 (пользовательское взаимодействие)\033[0m\n");
    
    printf("Имя файла:\n");
    if(scanf("%s", filein) != 1)
    {
	ERR_LOGGING(TASK1_CODE_NO_INPUT_FILE, "Отсутствует входной файл %s", filein);
	return TASK1_CODE_NO_INPUT_FILE;
    }

    return func_task1(filein);
#endif // SELFTEST
#endif // TASK1

//
// Задача 2 (Вариант реализации функции с дополнительными пользовательскими параметрами)
//
#ifdef TASK2
#ifdef SELFTEST
    //
    // Автоматизированное тестирование реализации функции
    //
    printf("\033[1;44mРЕЖИМ РАБОТЫ: Задача 2 (самотестирование)\033[0m\n");

/*!
    Макро-функция тестирования реализации функции func_task2()
    \param[in] test_name Имя теста (префикс)
    \param[in] input_file Локальный путь к входному имени файла
    \param[in] x_value Значение искомой точки
    \param[in] N_value Значение искомого разбиения
    \param[in] waiting_code Ожидаемый код завершения теста
*/
#define RUN_SELFTEST(test_name, input_file, x_value, N_value, waiting_code) \
    { \
    int return_code; \
    if((return_code = func_task2(input_file, x_value, N_value)) == waiting_code) \
    { \
	printf("> \033[1;33m"test_name"\033[0m - \033[1;42m УСПЕХ \033[0m "); \
	printf("(код возврата - 0x%08X)\n", waiting_code); \
    } \
    else \
    { \
	printf("> \033[1;33m"test_name"\033[0m - \033[1;41m ПРОВАЛ \033[0m "); \
	printf("(ожидаемый код возврата - 0x%08X, код возврата - 0x%08X)\n", waiting_code, return_code); \
	return TASK2_CODE_SELFTEST_ERROR; \
    } \
    }

    // Тест 1 : Отсутствующий входной файл
    RUN_SELFTEST("TEST1", "test_miss.txt", 1.0, 1000, TASK2_CODE_NO_INPUT_FILE);
    // Тест 2 : Некорректные дополнительные данные
    RUN_SELFTEST("TEST2", "./test/task2/test1.txt", 1.0, -1, TASK2_CODE_INCORRECT_ADV_DATA);
    // Тест 3 : Пустой входной файл (неверное число данных для обработки)
    // RUN_SELFTEST("TEST3", "./test/task2/test1.txt", 1.9, 100500, TASK2_CODE_INCORRECT_INPUT_FILE);
    // Тест 4 : Ошибочные данные в входном файле (неверное число данных для обработки)
    // RUN_SELFTEST("TEST4", "./test/task2/test1.txt", 0.99, -100500, TASK2_CODE_INCORRECT_INPUT_FILE);
    // Тест 5 : Конфигурация данных не может быть обработана
    // RUN_SELFTEST("TEST5", "./test/task2/test2.txt", 1.0, 1, TASK2_CODE_INCORRECT_CONFIGURATION);

#undef RUN_SELFTEST

    // Завершение работы
    printf("\n\033[1;44mВЫПОЛНЕНО\033[0m\n");
    return TASK2_CODE_NO_ERROR;
#else
    //
    // Пользовательское взаимодействие (User Interface)
    //
    char filein[255] = {0};
    double x;
    int N;

    printf("\033[1;46mРЕЖИМ РАБОТЫ: Задача 2 (пользовательское взаимодействие)\033[0m\n");

    printf("Имя файла:\n");
    if(scanf("%s", filein) != 1)
    {
	ERR_LOGGING(TASK2_CODE_NO_INPUT_FILE, "Отсутствует входной файл %s", filein);
	return TASK2_CODE_NO_INPUT_FILE;
    }

    printf("Точка:\n");
    if(scanf("%lf", &x) != 1)
    {
	ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Некорректные входные данные для x");
	return TASK2_CODE_INCORRECT_ADV_DATA;
    }

    printf("Разбиение:\n");
    if(scanf("%d", &N) != 1)
    {
	ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Некорректные входные данные для N");
	return TASK2_CODE_INCORRECT_ADV_DATA;
    }

    return func_task2(filein, x, N);
#endif // SELFTEST
#endif // TASK2
}
