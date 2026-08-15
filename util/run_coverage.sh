#!/bin/bash

# Внешние параметры
# $1 - Путь к исполняемому файлу

# Переход в директорию $1
EXECUTEDIR=`dirname "$1"`
EXECUTEFILE=`basename "$1"`
SCRIPTFILE=`basename "$0"`
MSGPREFIX="\e[1;35m[$SCRIPTFILE]\e[0m"
printf "$MSGPREFIX Запуск работы скрипта: $0\n"
printf "$MSGPREFIX \e[0;32mПараметр скрипта: $1\e[0m\n"
printf "$MSGPREFIX \e[0;32mПереход в директорию $EXECUTEDIR\e[0m\n"
cd "$EXECUTEDIR"

# Очистка ранее сделанного покрытия
printf "$MSGPREFIX \e[0;32mОчистка в директории `pwd` файлов покрытия кода *.gcov\e[0m\n"
rm -f "*.gcov"
printf "$MSGPREFIX \e[0;32mОчистка в директории $(realpath ..) файлов покрытия кода *.gcda\e[0m\n"
find .. -name '*.gcda' -delete

# Выполнение запуска параметра
printf "$MSGPREFIX \e[0;32mЗапуск в директории `pwd` исполняемого файла $EXECUTEFILE с проверкой работы памяти\e[0m\n"
valgrind --leak-check=full --show-leak-kinds=all "$1"

# Проверка кода возврата исполняемого файла (если !=0 - покрытие не строится)
RetVal=$?
if [ $RetVal -ne 0 ]; then
    printf "\n\n$MSGPREFIX \e[1;41mВНИМАНИЕ! Исполняемый файл $EXECUTEFILE завершил работу с ненулевым кодом возврата\e[0m\n\n"
    exit 0
fi

# Формирование отчета построения покрытия для gcda-файлов
# Примечание: предполагается, что исполняемый файл в директории bin
for gcda_file in $(find .. -name *.gcda); do
    printf "$MSGPREFIX \e[0;32mАнализ файла покрытия $gcda_file \e[0m\n"
    gcov $gcda_file
    cat `basename "$gcda_file" .gcda`.gcov | grep --color=auto -C5 "#####"
done

printf "$MSGPREFIX \e[1;32mРабота в директории `pwd` для исполняемого файла $EXECUTEFILE завершена\e[0m\n"

exit 0
