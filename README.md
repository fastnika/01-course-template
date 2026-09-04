*Песочница для образовательного программирования 1ого курса* 

<details>
<summary>Демонстрация лога сборки template (с вызовом при сборке valgrind для selftest и построением покрытия кода)</summary>

```bash
$ ./build.sh
[build.sh] Запуск работы скрипта: ./build.sh
[build.sh] Директория построения out отсутствует
[build.sh] Формирование проекта в out
-- The C compiler identification is GNU 12.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/fastnika/01-course-template/out
[build.sh] Запуск построения проекта в out
[  8%] Building C object CMakeFiles/sequence_task1.dir/src/main.c.o
[ 16%] Building C object CMakeFiles/sequence_task1.dir/src/task1.c.o
[ 25%] Linking C executable bin/sequence_task1
[ 25%] Built target sequence_task1
[ 33%] Building C object CMakeFiles/sequence_task1_selftest.dir/src/main.c.o
[ 41%] Building C object CMakeFiles/sequence_task1_selftest.dir/src/task1.c.o
[ 50%] Linking C executable bin/sequence_task1_selftest
[run_coverage.sh] Запуск работы скрипта: /home/fastnika/01-course-template/util/run_coverage.sh
[run_coverage.sh] Параметр скрипта: /home/fastnika/01-course-template/out/bin/sequence_task1_selftest
[run_coverage.sh] Переход в директорию /home/fastnika/01-course-template/out/bin
[run_coverage.sh] Очистка в директории /home/fastnika/01-course-template/out/bin файлов покрытия кода *.gcov
[run_coverage.sh] Очистка в директории /home/fastnika/01-course-template/out файлов покрытия кода *.gcda
[run_coverage.sh] Запуск в директории /home/fastnika/01-course-template/out/bin исполняемого файла sequence_task1_selftest с проверкой работы памяти
==6962== Memcheck, a memory error detector
==6962== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==6962== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==6962== Command: /home/fastnika/01-course-template/out/bin/sequence_task1_selftest
==6962==
РЕЖИМ РАБОТЫ: Задача 1 (самотестирование)


Error:  Ошибка открытия файла test_miss.txt
Code:   0x00001001
File:   /home/fastnika/01-course-template/src/task1.c
Line:   27

> TEST1 -  УСПЕХ  (код возврата - 0x00001001)
> TEST2 -  ПРОВАЛ  (ожидаемый код возврата - 0x00001004, код возврата - 0x00000000)
==6962==
==6962== HEAP SUMMARY:
==6962==     in use at exit: 472 bytes in 1 blocks
==6962==   total heap usage: 9 allocs, 8 frees, 11,293 bytes allocated
==6962==
==6962== 472 bytes in 1 blocks are still reachable in loss record 1 of 1
==6962==    at 0x48417B4: malloc (vg_replace_malloc.c:381)
==6962==    by 0x48DA1FA: __fopen_internal (iofopen.c:65)
==6962==    by 0x10979A: func_task1 (task1.c:24)
==6962==    by 0x1093D4: main (main.c:53)
==6962==
==6962== LEAK SUMMARY:
==6962==    definitely lost: 0 bytes in 0 blocks
==6962==    indirectly lost: 0 bytes in 0 blocks
==6962==      possibly lost: 0 bytes in 0 blocks
==6962==    still reachable: 472 bytes in 1 blocks
==6962==         suppressed: 0 bytes in 0 blocks
==6962==
==6962== For lists of detected and suppressed errors, rerun with: -s
==6962== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


[run_coverage.sh] ВНИМАНИЕ! Исполняемый файл sequence_task1_selftest завершил работу с ненулевым кодом возврата

[ 50%] Built target sequence_task1_selftest
[ 58%] Building C object CMakeFiles/sequence_task2.dir/src/main.c.o
[ 66%] Building C object CMakeFiles/sequence_task2.dir/src/task2.c.o
[ 75%] Linking C executable bin/sequence_task2
[ 75%] Built target sequence_task2
[ 83%] Building C object CMakeFiles/sequence_task2_selftest.dir/src/main.c.o
[ 91%] Building C object CMakeFiles/sequence_task2_selftest.dir/src/task2.c.o
[100%] Linking C executable bin/sequence_task2_selftest
[run_coverage.sh] Запуск работы скрипта: /home/fastnika/01-course-template/util/run_coverage.sh
[run_coverage.sh] Параметр скрипта: /home/fastnika/01-course-template/out/bin/sequence_task2_selftest
[run_coverage.sh] Переход в директорию /home/fastnika/01-course-template/out/bin
[run_coverage.sh] Очистка в директории /home/fastnika/01-course-template/out/bin файлов покрытия кода *.gcov
[run_coverage.sh] Очистка в директории /home/fastnika/01-course-template/out файлов покрытия кода *.gcda
[run_coverage.sh] Запуск в директории /home/fastnika/01-course-template/out/bin исполняемого файла sequence_task2_selftest с проверкой работы памяти
==7017== Memcheck, a memory error detector
==7017== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==7017== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==7017== Command: /home/fastnika/01-course-template/out/bin/sequence_task2_selftest
==7017==
РЕЖИМ РАБОТЫ: Задача 2 (самотестирование)


Error:  Ошибка открытия файла test_miss.txt
Code:   0x00002001
File:   /home/fastnika/01-course-template/src/task2.c
Line:   43

> TEST1 -  УСПЕХ  (код возврата - 0x00002001)


Error:  Значение N (-1) некорректно
Code:   0x00002003
File:   /home/fastnika/01-course-template/src/task2.c
Line:   36

> TEST2 -  УСПЕХ  (код возврата - 0x00002003)

ВЫПОЛНЕНО
==7017==
==7017== HEAP SUMMARY:
==7017==     in use at exit: 0 bytes in 0 blocks
==7017==   total heap usage: 8 allocs, 8 frees, 10,821 bytes allocated
==7017==
==7017== All heap blocks were freed -- no leaks are possible
==7017==
==7017== For lists of detected and suppressed errors, rerun with: -s
==7017== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[run_coverage.sh] Анализ файла покрытия ../CMakeFiles/sequence_task2_selftest.dir/src/task2.c.gcda
File '/home/fastnika/01-course-template/src/task2.c'
Lines executed:71.43% of 14
Creating 'task2.c.gcov'

Lines executed:71.43% of 14
        -:   25:    //
        -:   26:    // Предварительная проверка работы с файлом
        -:   27:    //
        2:   28:    if(fabs(x) < DBL_EPSILON)
        -:   29:    {
    #####:   30:        ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Значение x (%g) некорректно", x);
    #####:   31:        return TASK2_CODE_INCORRECT_ADV_DATA;
        -:   32:    }
        -:   33:
        2:   34:    if(N <= 0)
        -:   35:    {
        1:   36:        ERR_LOGGING(TASK2_CODE_INCORRECT_ADV_DATA, "Значение N (%d) некорректно", N);
--
        -:   57:
        -:   58:    //
        -:   59:    // Завершение работы
        -:   60:    //
        -:   61:
    #####:   62:    fclose(fin);
        -:   63:
    #####:   64:    return TASK2_CODE_NO_ERROR;
        -:   65:}
[run_coverage.sh] Анализ файла покрытия ../CMakeFiles/sequence_task2_selftest.dir/src/main.c.gcda
File '/home/fastnika/01-course-template/src/main.c'
Lines executed:100.00% of 6
Creating 'main.c.gcov'

Lines executed:100.00% of 6
[run_coverage.sh] Работа в директории /home/fastnika/01-course-template/out/bin для исполняемого файла sequence_task2_selftest завершена
[100%] Built target sequence_task2_selftest
[build.sh] Работа завершена

$
```

</details>

<details>
<summary>Демонстрация отладки с использованием GDB для sequence_task1_selftest (после построения template с использованием cmake)</summary>

Список команд: https://fastnika.ru/distr/commands.pdf

![GIF 09 02 2025 17-14-19](https://github.com/user-attachments/assets/62b19d63-af90-4b9c-9b0a-345d936ce98a)

</details>

> [!CAUTION]
> 1. При взаимодействии с репозиторем создавать собственную ветку для работы.
> 2. В качестве названия ветки использовать фамилию.
> 3. Запрещается использовать ветку main для промежуточных изменений.
> 4. Формировать промежуточные изменения с размещением кода в соотв. поддиректории директории release.
> 5. При проведении финализации изменений - формировать pull request в ветку main.


