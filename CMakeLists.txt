#
# Шаблон CMake-инструкций для автоматизированной сборки заданий
# ВНИМАНИЕ: ПРИ ИСПОЛЬЗОВАНИИ ДАННОГО ШАБЛОНА НЕОБХОДИМО ПРОВЕСТИ АДАПТАЦИЮ
#

# Примечание по формированию проекта:
#
# - Список доступных генераторов проекта (символом * указан генератор по умолчанию)
# $ cmake -G
#
# - Сборка с генератором по умолчанию в директорию out из директории расположения CMakeLists.txt
# (по умолчанию в CMake для ОС Linux используется генератор - "Unix Makefiles", ОС Windows - "MinGW Makefiles")
# $ cmake -B out .
#
# - Сборка с генереатором для IDE Visual Studio 2022 для ОС Windows в директорию out из директории расположения CMakeLists.txt
# $ cmake -G "Visual Studio 17 2022" -B out .
#
# Примечание по сборке проекта:
# 
# - Автоматизированная сборка всех подпроектов проекта в директории out с использованием выбранного ранее генератора
# $ cmake --build out
#
# - Автоматизированная сборка выделенного подпроекта проекта в директории out с использованием выбранного ранее генератора
#  (наименование подпроекта должно совпадать с заданным TARGET первым параметром в add_executable())
# $ cmake --build out --target sequence_task1_selftest


# Минимальная версия CMake для исполнения данного скрипта
cmake_minimum_required(VERSION 3.10)

# Наименование проекта sequence с указанием использования в проекте исходных тектов на языке С
# Примечание: Некоторые IDE подразумевает наименование Решения (Solution)
project(sequence C)

# Указание рекомендуемых флагов компиляции (для адаптации программы в компьютерном классе)
# Примечание: Актуально для ОС Linux компилятора gcc
if(NOT MSVC)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wformat-security \
    -Wmissing-format-attribute -Wformat=1 -Wno-long-long -Wcast-align -Winline -Werror \
    -pedantic -pedantic-errors -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes \
    -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement \
    -Wbad-function-cast -Wnested-externs -Wunused -Wuninitialized -fPIC")
endif()

# Предварительное опредление переменных наименований подпроектов
# Причемание: для каждой задачи формируется два подпроекта:
# 1) для пользовательского взаимодействия
# 2) для автоматизированного тестирования
set(APPNAME_TASK1 ${PROJECT_NAME}_task1)
set(APPNAME_TASK1_SELFTEST ${PROJECT_NAME}_task1_selftest)
set(APPNAME_TASK2 ${PROJECT_NAME}_task2)
set(APPNAME_TASK2_SELFTEST ${PROJECT_NAME}_task2_selftest)

# Указание поддиректории bin в качестве основной директории для выходных файлов
# с указанием невозможности автоматического использования поддиреткорий (последовательность символов $<0:>)
set(OUTPUT_BIN_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/$<0:>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/$<0:>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/$<0:>)

# Указание отладочной сборки
set(CMAKE_BUILD_TYPE Debug)

# Указание поддиректории src от места расположения СMakeLists.txt в качестве директории с исходными текстами (*.c)
set(INPUT_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Указание поддиректории inc от места расположения СMakeLists.txt в качестве директории с заголовочными файлами (*.h)
set(INPUT_INC_DIR ${CMAKE_SOURCE_DIR}/inc)

# Указание поддиректории util от места расположения СMakeLists.txt в качестве директории дополнительным инструментарием (*.sh)
set(INPUT_UTIL_DIR ${CMAKE_SOURCE_DIR}/util)

# Указание исходных тектов проектов Задачи 1
set(INPUT_TASK1_SOURCE
    ${INPUT_SRC_DIR}/main.c
    ${INPUT_SRC_DIR}/task1.c
)

# Указание исходных тектов проектов Задачи 2
set(INPUT_TASK2_SOURCE
    ${INPUT_SRC_DIR}/main.c
    ${INPUT_SRC_DIR}/task2.c
)

# Указание для всех подпроектов директории с заголовочными файлами для исходных текстов
include_directories(${INPUT_INC_DIR})

# Указание для Выходных исполняемых файлов для каждого из подпроектов (в соотв. с заданным ранее именем подпроекта)
# относящихся исходных текстов программы
# Примечание: Исходя из предположения, что для каждой задачи используется 2 подпроекта, исходные тексты могут повторяться
add_executable(${APPNAME_TASK1} ${INPUT_TASK1_SOURCE})
add_executable(${APPNAME_TASK1_SELFTEST} ${INPUT_TASK1_SOURCE})
add_executable(${APPNAME_TASK2} ${INPUT_TASK2_SOURCE})
add_executable(${APPNAME_TASK2_SELFTEST} ${INPUT_TASK2_SOURCE})

# Указание используемых предопределенных макропеременных для каждого из указанных подпроектов
# Примечание: Указание "-DTASK1" эквивалентно указанию в исходном коде "#define TASK1" для всего подпроекта
target_compile_definitions(${APPNAME_TASK1} PRIVATE -DTASK1)
target_compile_definitions(${APPNAME_TASK1_SELFTEST} PRIVATE -DTASK1 -DSELFTEST)
target_compile_definitions(${APPNAME_TASK2} PRIVATE -DTASK2)
target_compile_definitions(${APPNAME_TASK2_SELFTEST} PRIVATE -DTASK2 -DSELFTEST)

if(NOT MSVC)
# Дополнительное указание библиотеки автоматизированного покрытия для компилятора gcc в режиме отладки при проведении самотестирования
target_compile_options(${APPNAME_TASK1_SELFTEST} PRIVATE -g --coverage)
target_compile_options(${APPNAME_TASK2_SELFTEST} PRIVATE -g --coverage)
target_link_libraries(${APPNAME_TASK1_SELFTEST} PRIVATE gcov)
target_link_libraries(${APPNAME_TASK2_SELFTEST} PRIVATE gcov)
# Дополнительное указание математической библиотеки для компилятора gcc
#target_link_libraries(${APPNAME_TASK1} PRIVATE m)
#target_link_libraries(${APPNAME_TASK1_SELFTEST} PRIVATE m)
#target_link_libraries(${APPNAME_TASK2} PRIVATE m)
#target_link_libraries(${APPNAME_TASK2_SELFTEST} PRIVATE m)
else()
# Указание для ОС Windows возможности использования unsafe functions
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
# Для ОС Windows покрытие возможно выполнить с использованием компилятора Clang
# Примерная механика действий приведена в https://ps-group.github.io/cxx/coverage_gcc
endif()

# Указание директории для копирования исходного теста
# из искомой поддиректории ${PROJECT_SOURCE_DIR} (месторасположения CMakeLists.txt)
# в директорию выходного исполняемого файла ${OUTPUT_BIN_DIR} (месторасположение задано выше)
# Примечание: директория task1 - тесты задачи 1, task2 - тесты задачи 2, etc.
add_custom_command(TARGET ${APPNAME_TASK1_SELFTEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/test/task1 ${OUTPUT_BIN_DIR}/test/task1)
add_custom_command(TARGET ${APPNAME_TASK2_SELFTEST} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/test/task2 ${OUTPUT_BIN_DIR}/test/task2)

if(MSVC)
# Автоматизированный запуск каждого проекта для ОС Windows
else()
# Автоматизированный запуск встроенной утилиты покрытия gcov для selftest каждого проекта для ОС Linux
add_custom_command(TARGET ${APPNAME_TASK1_SELFTEST}
    POST_BUILD
    COMMAND /bin/sh ${INPUT_UTIL_DIR}/run_coverage.sh ${OUTPUT_BIN_DIR}/${APPNAME_TASK1_SELFTEST}
)
add_custom_command(TARGET ${APPNAME_TASK2_SELFTEST}
    POST_BUILD
    COMMAND /bin/sh ${INPUT_UTIL_DIR}/run_coverage.sh ${OUTPUT_BIN_DIR}/${APPNAME_TASK2_SELFTEST}
)
endif()
