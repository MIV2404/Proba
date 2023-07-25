#!/bin/bash

echo 'Введите путь к файлу'
read path_of_the_file

if ! [ -e "$path_of_the_file" ]; then
    echo "Указанного файла не существует"
    exit 1
fi

quant_lines=$(awk '{print $1}' "$path_of_the_file" | wc -l)
uniq_files=$(awk '{print $1}' "$path_of_the_file" | uniq | wc -l)
count_mut=$(awk '$8 != "NULL" {print $8}' "$path_of_the_file" | uniq | wc -l)

echo "$quant_lines $uniq_files $count_mut"