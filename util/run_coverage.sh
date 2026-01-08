#!/bin/bash

# Внешние параметры
# $1 - Путь к исполняемому файлу

# Переход в директорию $1
EXECUTEDIR=`dirname "$1"`
cd "$EXECUTEDIR"

# Очистка ранее сделанного покрытия
rm -f "*.gcov"

# Выполнение запуска параметра
valgrind "$1"

# Проверка кода возврата исполняемого файла (если !=0 - покрытие не строится)
RetVal=$?
if [ $RetVal -ne 0 ]; then
    echo "\nATTENTION! APPLICATION RETURN CODE != 0\n"
    exit
fi

# Формирование отчета построения покрытия для gcda-файлов
for gcda_file in $(find .. -name *.gcda); do
    echo LOOK $gcda_file
    gcov $gcda_file
    cat `basename "$gcda_file" .gcda`.gcov | grep -C5 "#####"
done

echo GO AWAY