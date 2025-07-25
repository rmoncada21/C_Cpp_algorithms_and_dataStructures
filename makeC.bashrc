#!/bin/env bash

#   gcc -Wall -Wextra -fsyntax-only archivo.c
#   gcc -Wall -Wextra archivo.c -o bin/archivo -librerias

# Colores ANSI: formato de salida
RESET="\033[0m"

ROJO="\033[31m"

AZUL_BRILLANTE="\033[94m"
VERDE_BRILLANTE="\033[92m"
CIAN_BRILLANTE="\033[96m"

AZUL_FONDO="\033[44m"
ROJO_FONDO="\033[41m"

_ccompile_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"

    # local options=$(ls)
    # profundidad 2 para buscar en carpetas del directorio
    local options=$(find . -maxdepth 2 -type f -printf "%f\n")

    COMPREPLY=( $(compgen -W "${options}" -- "${cur}") )
}

complete -F _ccompile_autocomplete ccompile

ccompile(){
    echo -e "${AZUL_FONDO}ccompile en bash ${RESET}"

    local file="$1"
    local librerias="$2"
    local folders="$3"

    local file_ext="${file##*.}"
    local file_no_ext="${file%.c}"
    # echo "file: $file"
    # echo "file_ext: $file_ext"
    # echo "Sin extension: $file_no_ext"
    
    # local bin="bin"
    # local bin_fullpath="${dir}/${bin}"
    # local src="src"
    # local src_fullpath="${dir}/${src}"

    # Verificar entrada
    if [[ -z "$file" ]]; then
        echo -e "${ROJO} Sin archivo de entradda.${RESET}"
    elif [[ "$file" == "$file_ext" ]]; then
        echo -e "${AZUL_BRILLANTE}./bin/$file${RESET} \n"
        ./bin/"$file"
    elif [[ "$file_ext" == "c" ]]; then
        # echo "igual a C" 
        mkdir -p bin
        echo -e "${AZUL_BRILLANTE}ccompile $file ${RESET}"
        echo -e "gcc -Wall -Wextra ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}$file_no_ext${RESET}\n"
        gcc -Wall -Wextra "$file" -o bin/"$file_no_ext"
    else
        echo -e "${ROJO_FONDO}ccompile no admite este tipo de archivo ${RESET} \n"
    fi

}
