#!/bin/bash

# Внешние параметры
# $1 - Путь к исполняемому файлу

# Переход в директорию $1
EXECUTEDIR=`dirname "$1"`
EXECUTEFILE=`basename "$1"`
SCRIPTFILE=`basename "$0"`
printf "[$SCRIPTFILE] \e[1;35mЗапуск работы скрипта: $0\e[0m\n"
printf "[$SCRIPTFILE] \e[1;35mПараметр скрипта: $1\e[0m\n"
printf "[$SCRIPTFILE] \e[1;35mПереход в директорию $EXECUTEDIR\e[0m\n"
cd "$EXECUTEDIR"

# Очистка ранее сделанного покрытия
printf "[$SCRIPTFILE] \e[1;35mОчистка в директории `pwd` файлов покрятия кода *.gcov\e[0m\n"
rm -f "*.gcov"

# Выполнение запуска параметра
printf "[$SCRIPTFILE] \e[1;35mЗапуск в директории `pwd` исполняемого файла $EXECUTEFILE с проверкой работы памяти\e[0m\n"
valgrind --leak-check=full --show-leak-kinds=all "$1"

# Проверка кода возврата исполняемого файла (если !=0 - покрытие не строится)
RetVal=$?
if [ $RetVal -ne 0 ]; then
    printf "\n\n[$SCRIPTFILE] \e[1;41mВНИМАНИЕ! Исполняемый файл `pwd` завершил работу с ненулевым кодом возврата\e[0m\n\n"
    exit 0
fi

# Формирование отчета построения покрытия для gcda-файлов
# Примечание: предполагается, что исполняемый файл в директории bin
for gcda_file in $(find .. -name *.gcda); do
    printf "[$SCRIPTFILE] \e[1;35mАнализ файла покрытия $gcda_file \e[0m\n"
    gcov $gcda_file
    cat `basename "$gcda_file" .gcda`.gcov | grep --color=auto -C5 "#####"
done

printf "[$SCRIPTFILE] \e[1;36mРабота в директории `pwd` для исполняемого файла $EXECUTEFILE завершена\e[0m\n"

exit 0
