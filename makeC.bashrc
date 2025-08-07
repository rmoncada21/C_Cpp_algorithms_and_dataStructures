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

_compile_autocomplete(){
    local cur="${COMP_WORDS[COMP_CWORD]}"
    # profundidad 2 para buscar en carpetas del directorio incluyendo bin/
    local options=$(find . -maxdepth 2 -type f -printf "%f\n")

    COMPREPLY=( $(compgen -W "${options}" -- "${cur}") )
}
complete -F _compile_autocomplete compile

_compiler(){
    local option="$1" # 0 para gcc y 1 para g++
    local file="$2"
    local file_no_ext="$3"

    mkdir -p bin
    if [[ $option == 0 ]]; then
        echo -e "${AZUL_BRILLANTE}Ccompile $file ${RESET}"
        echo -e "gcc -Wall -Wextra ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}$file_no_ext${RESET}\n"
        gcc -Wall -Wextra "$file" -o bin/"$file_no_ext"
    elif [[ $option == 1 ]]; then
        echo -e "${AZUL_BRILLANTE}CPPcompile $file ${RESET}"
        echo -e "g++ -Wall -Wextra ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}$file_no_ext${RESET}\n"
        g++ -Wall -Wextra "$file" -o bin/"$file_no_ext"
    else
        echo -e "${ROJO_FONDO}Inserte una opción de 0 para gcc y 1 para gpp ${RESET} \n"
    fi
}

compile(){
    echo -e "${AZUL_FONDO}compile en bash ${RESET}"

    local file="$1"
    local librerias="$2"

    local file_ext="${file##*.}"
    local Cfile_no_ext="${file%.c}"
    local Cppfile_no_ext="${file%.cpp}"

    # Verificar entrada
    if [[ -z "$file" ]]; then
        echo -e "${ROJO} Sin archivo de entrada.${RESET}"
    elif [[ "$file" == "$file_ext" ]]; then
        echo -e "${AZUL_BRILLANTE}./bin/$file${RESET} \n"
        ./bin/"$file"
    elif [[ "$file_ext" == "c" ]]; then
        # echo "igual a C"
        _compiler 0 "$file" "$Cfile_no_ext"
    elif [[ "$file_ext" == "cpp" ]]; then
        # echo "igual a C"
        _compiler 1 "$file" "$Cppfile_no_ext"
    else
        echo -e "${ROJO_FONDO}compile no admite este tipo de archivo ${RESET} \n"
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

_sanitize(){
    local option0="$1" # 0 para clang y 1 para clang++
    local option="$2"
    local file="$3"
    local file_no_ext="$4"
    
    mkdir -p bin
    if [[ $option0 == 0 ]]; then
        echo -e "${AZUL_BRILLANTE}Clangsanitize $file ${RESET}"
        echo -e "clang -Wall -Wextra -fsanitize="$option" ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}${file_no_ext}_${option}${RESET}\n"
        clang -Wall -Wextra -fsanitize="$option" "$file" -o bin/"${file_no_ext}_${option}"
    elif [[ $option0 == 1 ]]; then
        echo -e "${AZUL_BRILLANTE}Clang++sanitize $file ${RESET}"
        echo -e "clang -Wall -Wextra -fsanitize="$option" ${VERDE_BRILLANTE}$file${RESET} -o bin/${CIAN_BRILLANTE}${file_no_ext}_${option}${RESET}\n"
        clang++ -Wall -Wextra -fsanitize="$option" "$file" -o bin/"${file_no_ext}_${option}"
    else
        echo -e "${ROJO_FONDO}Inserte una opción de 0 para clang y 1 para clang++ ${RESET} \n"
    fi
}
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
        compile "$file"
    else
        if [[ "$file" == "$file_ext" ]]; then
            echo -e "${AZUL_BRILLANTE}./bin/${file}_${option}${RESET} "
            ./bin/"$file"
        elif [[ "$file_ext" == "c" ]]; then
            # echo "igual a C"
            _sanitize 0 "$option" "$file" "$file_no_ext"
        elif [[ "$file_ext" == "cpp" ]]; then
            _sanitize 1 "$option" "$file" "$file_no_ext"
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