#!/bin/env bash

# Colores ANSI: formato de salida
RESET="\033[0m"
ROJO="\033[31m"

AZUL_BRILLANTE="\033[94m"
VERDE_BRILLANTE="\033[92m"
CIAN_BRILLANTE="\033[96m"

AZUL_FONDO="\033[44m"
ROJO_FONDO="\033[41m"

################ GCC compilación de archivo ################
#   gcc -Wall -Wextra -fsyntax-only archivo.c
#   gcc -Wall -Wextra archivo.c -o bin/archivo -librerias

_ccompile_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"
    # profundidad 2 para buscar en carpetas del directorio incluyendo bin/
    local options=$(find . -maxdepth 2 -type f -printf "%f\n")

    COMPREPLY=( $(compgen -W "${options}" -- "${cur}") )
}
complete -F _ccompile_autocomplete ccompile

ccompile(){
    echo -e "${AZUL_FONDO}ccompile en bash ${RESET}"

    local file="$1"
    local librerias="$2"

    local file_ext="${file##*.}"
    local file_no_ext="${file%.c}"

    # Verificar entrada
    if [[ -z "$file" ]]; then
        echo -e "${ROJO} Sin archivo de entrada.${RESET}"
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

############### SANITIZERS con clang ################
# clang -g -Wall -Wextra -fsanitize=address $(APPNAME).c -o ./bin/$(APPNAME)_asan
# clang -g -Wall -Wextra -fsanitize=memory $(APPNAME).c -o ./bin/$(APPNAME)_msan
# clang -g -Wall -Wextra -fsanitize=thread $(APPNAME).c -o ./bin/$(APPNAME)_tsan
# clang -g -Wall -Wextra -fsanitize=undefined $(APPNAME).c -o ./bin/$(APPNAME)_ubsan

_sanitize_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"
    # profundidad 2 para buscar en carpetas del directorio
    local option0=( -help address memory thread undefined )
    local option1=$(find . -maxdepth 2 -type f -printf "%f\n")

    local options=( "${option0[@]}" "${option1[@]}" ) 
    # COMPREPLY=( $(compgen -W "${options}" -- "${cur}") )
    COMPREPLY=( $(compgen -W "${options[*]}" -- "${cur}") )
}
complete -F _sanitize_autocomplete sanitize

sanitize(){
    echo -e "${AZUL_FONDO}sanitize en bash ${RESET}"
    local file="$1"
    local option="$2"
    local file_ext="${file##*.}"
    local file_no_ext="${file%.c}"

    local cantidad_arg="$#"
    echo "Cantidad de argumentos: $cantidad_arg"

    # verificar entrada
    if [[ "$cantidad_arg" == "0" ]]; then
        echo -e "${ROJO} Sin archivo de entrada.${RESET}"
    
    elif [[ "$cantidad_arg" == "1" ]]; then
        ccompile "$file"
    else
        if [[ "$file" == "$file_ext" ]]; then
            echo -e "${AZUL_BRILLANTE}./bin/${file}_${option}${RESET} "
            ./bin/"$file"
        elif [[ "$file_ext" == "c" ]]; then
            # echo "igual a C" 
            mkdir -p bin
            echo -e "${AZUL_BRILLANTE}sanitize $file ${RESET}"
            echo -e "clang -Wall -Wextra -fsanitize="$option" ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}${file_no_ext}_${option}${RESET}\n"
            clang -Wall -Wextra -fsanitize="$option" "$file" -o bin/"${file_no_ext}_${option}"
        else
            echo -e "${ROJO_FONDO}sanitize no admite este tipo de archivo ${RESET} \n"
        fi
    fi
}

############### VALGRIND compilación de arvhivos fuentes ./bin/archivo ################
# para corroborar fugas de memoria y condiciones de carrera

# valgrind --tool=memcheck ./bin/ejecutable
# valgrind --quiet --tool=memcheck ./bin/ejecutable
# valgrind -v --tool=memcheck ./bin/ejecutable # v =verbose
_valgrind_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"
    local options0=" '-help' 'memcheck' 'helgrind' "
    local options1=$(find bin/ -type f -printf "%f\n")
    local options=( "${options0[@]}" "${options1[@]}" )

    COMPREPLY=( $(compgen -W "${options[*]}" -- "${cur}") )
}
complete -F _valgrind_autocomplete leak_memory

leak_memory(){
    local file="$1"
    local tool="$2"
    local cantidad_arg="$#"

    if [[ "$cantidad_arg" == "2" ]]; then
        valgrind --tool="$tool" ./bin/"$file"
    else
        valgrind
    fi

}

############## CPPLINT
# _ccplint(){}