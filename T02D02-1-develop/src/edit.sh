#!/bin/bash
 
echo 'Введите путь к файлу'
read path_of_the_file
 
echo 'Введите подстроку которую надо заменить'
read string
 
echo 'Введите подстроку, на которую требуется заменить искомую'
read replace_string

if [ ! -f "$path_of_the_file" ]; then
	echo 'Файл не существует'
	exit 1
fi

if ! file "$path_of_the_file" | grep -q "text"; then
	echo 'Файл не текстовый'
	exit 1
fi

if [ $string = $replace_string ]; then
        echo $string
        echo $replace_string
        echo 'Исходная подстрока равна заменяющей, менять нечего'
        exit 1
fi

if [ $path_of_the_file = "" ]; then
        echo 'Исходная подстрока пустая, менять нечего'
        exit 1
fi

if ! grep -q "$string" "$path_of_the_file"; then
        echo 'Заданная строка отсутствует в файле'
        exit 1
fi

sed -i '' "s/$string/$replace_string/g" "$path_of_the_file"

FILESIZE=$(stat -f "%z" $path_of_the_file)
SHASUM=$(shasum -a 256 $path_of_the_file | awk '{print $1}')
DATE=$(date +'%Y-%m-%d')
TIME=$(date "+%H:%M")

echo "src/$path_of_the_file - $FILESIZE - $DATE - $TIME - $SHASUM - sha256" >> "files.log"
