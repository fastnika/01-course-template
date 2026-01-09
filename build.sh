#!/bin/bash

#
# Конфигурация скрипта для ОС Linux
#

#
# Префикс-сообщение наименования скрипта
#
SCRIPTFILE=`basename "$0"`
MSGPREFIX="\e[1;36m[$SCRIPTFILE]\e[0m"

# Директория построения
BUILDDIR=out

#
# Команды скрипта для ОС Linux
#

# Выставление параметров для текущего скрипта при некорреткном завершении предшествующей команды
set -eu

# Очистка директории построения при наличии
if [[ -d $BUILDDIR ]]; then 
    printf "$MSGPREFIX \e[0;32mОчистка директории построения $BUILDDIR\e[0m\n"
    rm -r $BUILDDIR
else
    printf "$MSGPREFIX \e[0;32mДиректория построения $BUILDDIR отсутствует\e[0m\n"
fi

# Формирование проекта
printf "$MSGPREFIX \e[0;32mФормирование проекта в $BUILDDIR\e[0m\n"
cmake -B $BUILDDIR .

# Построение проекта
printf "$MSGPREFIX \e[0;32mЗапуск построения проекта в $BUILDDIR\e[0m\n"
cmake --build $BUILDDIR

printf "$MSGPREFIX \e[1;32mРабота завершена\e[0m\n"

exit 0
