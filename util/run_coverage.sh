#!/bin/bash

# Внешние параметры
# $1 - Путь к исполняемому файлу

# Переход в директорию $1
EXECUTEDIR=`dirname "$1"`
EXECUTEFILE=`basename "$1"`
echo -e "\e[1;35m Переход в директорию $EXECUTEDIR для запуска исполняемого файла $EXECUTEFILE\e[0m"
cd "$EXECUTEDIR"

# Очистка ранее сделанного покрытия
echo -e "\e[1;35m Очистка в директории $EXECUTEDIR файлов покрятия кода *.gcov \e[0m"
rm -f "*.gcov"

# Выполнение запуска параметра
echo -e "\e[1;35m Запуск в директории $EXECUTEDIR исполняемого файла $EXECUTEFILE с проверкой работы памяти \e[0m"
valgrind --leak-check=full --show-leak-kinds=all "$1"

# Проверка кода возврата исполняемого файла (если !=0 - покрытие не строится)
RetVal=$?
if [ $RetVal -ne 0 ]; then
    echo .
    echo -e "\e[1;41m ВНИМАНИЕ! Исполняемый файл $EXECUTEFILE завершил работу с ненулевым кодом возврата\e[0m"
    echo .
    exit
fi

# Формирование отчета построения покрытия для gcda-файлов
for gcda_file in $(find .. -name *.gcda); do
    echo -e "\e[1;35m Анализ файла покрытия $gcda_file \e[0m"
    gcov $gcda_file
    cat `basename "$gcda_file" .gcda`.gcov | grep --color=auto -C5 "#####"
done

echo "\e[1;32m Работа в директории $EXECUTEDIR с исполняемого файлом $EXECUTEFILE завершена \e[0m"
