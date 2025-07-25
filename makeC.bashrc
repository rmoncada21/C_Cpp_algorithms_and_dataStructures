#!/bin/env bash

#   gcc -Wall -Wextra -fsyntax-only archivo.c
#   gcc -Wall -Wextra archivo.c -o bin/archivo -librerias
# ./bin/

_ccompile_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"

    # local options=$(ls)
    # profundidad 2 para buscar en carpetas del directorio
    local options=$(find . -maxdepth 2 -type f -printf "%f\n")

    COMPREPLY=( $(compgen -W "${options}" -- "${cur}") )
}

complete -F _ccompile_autocomplete ccompile

ccompile(){
    # pedir archivo a compilar
    local file="$1" # hacer un autocompletado
    # echo "file: $file"
    local file_ext="${file##*.}"
    # echo "file_ext: $file_ext"
    local file_no_ext="${file%.c}"
    # echo "Sin extension: $file_no_ext"
    local librerias="$2"
    local folders="$3"
    
    # folder bin
    # local bin="bin"
    # local bin_fullpath="${dir}/${bin}"
    
    # folder src
    # local src="src"
    # local src_fullpath="${dir}/${src}"

    #   gcc -Wall -Wextra archivo.c -o bin/archivo -librerias
    if [[ "$file" == "$file_ext" ]]; then
        echo "Ejecutar"
        ./bin/"$file"
    elif [[ "$file_ext" == "c" ]]; then
        # echo "igual a C"
        mkdir -p bin
        # gcc -Wall -Wextra archivo.c -o bin/archivo -librerias
        echo "gcc -Wall -Wextra $file -o bin/$file_no_ext"
        gcc -Wall -Wextra "$file" -o bin/"$file_no_ext"
    else
        echo "Archivo incompatible con C"
    fi

}
