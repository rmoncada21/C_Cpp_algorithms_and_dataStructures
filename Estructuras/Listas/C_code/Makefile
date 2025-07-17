# -------------------------------------------------------------------
# Makefile: Archivo para la gestión y compilación de proyectos en C.
# -------------------------------------------------------------------
# target: prerequisites
# command to build target

# Ejemplos de comandos de compilación:
# Verificar sintaxis sin generar archivo ejecutable
#   gcc -Wall -Wextra -fsyntax-only archivo.c
# Compilar un archivo .c generando ejecutable
#   gcc -Wall -Wextra archivo.c -o bin/archivo -librerias
# Compilar varios archivos .c generando ejecutable
#   gcc -Wall -Wextra archivo1.c archivo2.c -o bin/archivo -librerias

# -------------------------------------------------------------------
# Variables
# -------------------------------------------------------------------

# Aplicación principal
APP?=main
EXE_APP=$(APP:.c=)

# Compilador y opciones
GCC=gcc
CFLAGS=-Wall -Wextra
CSYNTAX=-fsyntax-only

# Archivos de cabecera
CSOURCES=$(wildcard *.c)
CHEADERS=$(wildcard *.h)
CFILES=$(CSOURCES) $(CHEADERS)

# Directorios
BIN_FOLDER=bin
SRC_FOLDER=src
TEST_FOLDER=test
TEST_FILES=$(wildcard $(TEST_FOLDER)/*.txt)
TEST_INPUT=$(notdir $(TEST_FILES))

# Ejecutables
EXE_CSOURCES_FILES=$(wildcard $(BIN_FOLDER)/*)
EXE_CSOURCES=$(notdir $(EXE_CSOURCES_FILES))
# EXE_CSOURCES=$(patsubst $(BIN_FOLDER)/%,%, $(EXE_CSOURCES_FILES))


# -------------------------------------------------------------------
# Código ansi de colores
# -------------------------------------------------------------------

# Colores básicos:
RESET = \033[0m
NEGRO = \033[30m
ROJO = \033[31m
VERDE = \033[32m
AMARILLO = \033[33m
AZUL = \033[34m
MAGENTA = \033[35m
CIAN = \033[36m
BLANCO = \033[37m

# Colores brillantes (intensos):
NEGRO_BRILLANTE = \033[90m
ROJO_BRILLANTE = \033[91m
VERDE_BRILLANTE = \033[92m
AMARILLO_BRILLANTE = \033[93m
AZUL_BRILLANTE = \033[94m
MAGENTA_BRILLANTE = \033[95m
CIAN_BRILLANTE = \033[96m
BLANCO_BRILLANTE = \033[97m

# Fondo de colores:
NEGRO_FONDO = \033[40m
ROJO_FONDO = \033[41m
VERDE_FONDO = \033[42m
AMARILLO_FONDO = \033[43m
AZUL_FONDO = \033[44m
MAGENTA_FONDO = \033[45m
CIAN_FONDO = \033[46m
BLANCO_FONDO = \033[47m

# Fondos brillantes:
NEGRO_BRILLANTE_FONDO = \033[100m
ROJO_BRILLANTE_FONDO = \033[101m
VERDE_BRILLANTE_FONDO = \033[102m
AMARILLO_BRILLANTE_FONDO = \033[103m
AZUL_BRILLANTE_FONDO = \033[104m
MAGENTA_BRILLANTE_FONDO = \033[105m
CIAN_BRILLANTE_FONDO = \033[106m
BLANCO_BRILLANTE_FONDO = \033[107m


# -------------------------------------------------------------------
# Reglas
# -------------------------------------------------------------------

# Regla principal
all: mkdir csource


# Regla para crear directorios
mkdir:
	mkdir -p $(BIN_FOLDER) $(SRC_FOLDER) $(TEST_FOLDER)


# Regla para comprobar sintaxis de todos los archivos
syntax:
	@echo -e "$(AZUL_FONDO)make $@$(RESET)"
	@echo -e "$(GCC) $(CFLAGS) $(CIAN_FONDO)$(CSYNTAX)$(RESET) $(VERDE_BRILLANTE)$(CFILES)$(RESET) \n"
	@$(GCC) $(CFLAGS) $(CSYNTAX) $(CFILES)


# Regla para comprobar sintaxis de un archivo
$(CFILES:=_syntax):
	@echo -e '$(AZUL_FONDO)make $$(CFILES:=_syntax)$(RESET)'
	@echo -e "$(AZUL_BRILLANTE)make $@$(RESET)"
	@echo -e "$(GCC) $(CFLAGS) $(CIAN_FONDO)$(CSYNTAX)$(RESET) $(VERDE_BRILLANTE)$(@:_syntax=)$(RESET)\n"
	@$(GCC) $(CFLAGS) $(CSYNTAX) $(@:_syntax=)


# Regla para compilar un main.c con archivos #include <archivo.h>
csource:
	@echo -e "$(AZUL_FONDO)make $@$(RESET)"
	@echo -e "$(GCC) $(CFLAGS) $(VERDE_BRILLANTE)$(CSOURCES)$(RESET) -o $(BIN_FOLDER)/$(CIAN_BRILLANTE)$(APP:.c=)$(RESET)\n"
	@$(GCC) $(CFLAGS) $(CSOURCES) -o $(BIN_FOLDER)/$(APP:.c=)
	

# Regla para compilar un archivo.c con función int main(){}
$(CSOURCES):
	@echo -e '$(AZUL_FONDO)make $$(CSOURCES)$(RESET)'
	@echo -e "$(AZUL_BRILLANTE)make $@$(RESET)"
	@echo -e "$(GCC) $(CFLAGS) $(VERDE_BRILLANTE)$@$(RESET) -o $(BIN_FOLDER)/$(CIAN_BRILLANTE)$(@:.c=)$(RESET)\n"
	@$(GCC) $(CFLAGS) $@ -o $(BIN_FOLDER)/$(@:.c=)


# Regla para ejecutables con int main(int argv, char* [])
_lectura:
	@echo -e '$(AZUL_FONDO)$$(EXE_CSOURCES:=_arg)$(RESET)'
	@echo -n "Ingrese los datos del test: "

$(EXE_CSOURCES:=_arg): _lectura
	$(eval MATRIZ := $(shell read -a matriz; echo $${matriz[@]}))
# @echo "La matriz desde Makefile es: $(MATRIZ)"
# Aquí, ejecutamos la acción con la matriz capturada
	@echo -e "\n$(AZUL_BRILLANTE)make $@$(RESET)"
	@echo -e "./$(BIN_FOLDER)/$(CIAN_BRILLANTE)$(@:_arg=) $(MATRIZ)$(RESET)\n"
	@./$(BIN_FOLDER)/$(@:_arg=) $(MATRIZ)


# Regla para ejecutables con archivo de entrada o sin archivo
$(EXE_CSOURCES):
	@if [ "$(words $(MAKECMDGOALS))" -eq 1 ]; then \
		echo -e "$(AZUL_BRILLANTE)Ejecutando $(BIN_FOLDER)/$@$(RESET) $(VERDE_BRILLANTE)sin entrada...$(RESET)\n"; \
		./$(BIN_FOLDER)/$@; \
	elif [ "$(words $(MAKECMDGOALS))" -eq 2 ]; then \
		TEST_INPUT=$(word 2, $(MAKECMDGOALS)); \
		echo -e "$(AZUL_BRILLANTE)Ejecutando $(BIN_FOLDER)/$@$(RESET) < $(VERDE_BRILLANTE) $(TEST_FOLDER)/$$TEST_INPUT$(RESET)\n"; \
		./$(BIN_FOLDER)/$@ < $(TEST_FOLDER)/$$TEST_INPUT; \
	else \
		echo -e "$(CIAN_BRILLANTE)Error: demasiados argumentos. Uso: make <ejecutable> [<archivo_entrada>]$(RESET)"; \
	fi


# Regla para limpiar archivos ejecutables
clean:
	@echo -e "$(AZUL_FONDO)make clean$(RESET) -> $(AZUL_BRILLANTE)limpiando ejecutables$(RESET)"
	@echo -e "rm -rf $(BIN_FOLDER)/$(ROJO_BRILLANTE_FONDO)*$(RESET)"
	@echo -e "rm -rf $(BIN_FOLDER)/*


# Regla para mostrar contenidos de la variables
mostrar_archivos:
	@echo "Mostrando valores de variables del Makefile:"
	@echo -e "\nVariable APP:"
	@echo "$(APP)"
	@echo -e "\nVariable EXE_APP:"
	@echo "$(EXE_APP)"
	@echo -e "\nVariable GCC:"
	@echo "$(GCC)"
	@echo -e "\nVariable CFLAGS:"
	@echo "$(CFLAGS)"
	@echo -e "\nVariable CSYNTAX:"
	@echo "$(CSYNTAX)"
	@echo -e "\nArchivos CSOURCES:"
	@echo "$(CSOURCES)"
	@echo -e "\nArchivos CHEADERS:"
	@echo "$(CHEADERS)"
	@echo -e "\nArchivos CFILES (CSOURCES + CHEADERS):"
	@echo "$(CFILES)"
	@echo -e "\nDirectorio BIN_FOLDER:"
	@echo "$(BIN_FOLDER)"
	@echo -e "\nDirectorio SRC_FOLDER:"
	@echo "$(SRC_FOLDER)"
	@echo -e "\nDirectorio TEST_FOLDER:"
	@echo "$(TEST_FOLDER)"
	@echo -e "\nArchivos TEST_INPUT:"
	@echo "$(TEST_INPUT)"
	@echo -e "\nArchivos ejecutables en BIN_FOLDER (EXE_CSOURCES_FILES):"
	@echo "$(EXE_CSOURCES_FILES)"
	@echo -e "\nNombres de ejecutables (EXE_CSOURCES):"
	@echo "$(EXE_CSOURCES)"


help:
	@echo "  Ayuda para comandos Makefile:"
	@echo "  make all              -> Construye el proyecto completo (aun sin implementar en este archivo)."
	@echo "  make mkdir            -> Crea los directorios bin/, src/, y test/."
	@echo "  make syntax           -> Verifica la sintaxis de todos los archivos fuente sin generar ejecutables."
	@echo "  make <archivo>_syntax -> Verifica la sintaxis de un archivo específico (e.g., archivo.c)."
	@echo "  make csource          -> Compila main.c (o el archivo especificado en APP) con dependencias incluidas."
	@echo "  make <archivo>.c      -> Compila un archivo fuente específico, generando un ejecutable."
	@echo "  make <ejecutable>     -> Corre el ejecutable especificado dentro del directorio bin/."
	@echo "                           Si se define TEST_INPUT, lo usa como entrada estándar."
	@echo "  make clean            -> Elimina todos los archivos ejecutables en bin/."
	@echo "  make mostrar_archivos -> Muestra los archivos definidos en las variables del Makefile."
	@echo "  make help             -> Muestra esta ayuda."


# -------------------------------------------------------------------
# Declaraciones .PHONY
# -------------------------------------------------------------------
.PHONY: all test_colores mkdir syntax $(CFILES:=_syntax) source \
		$(CSOURCES) $(EXE_CSOURCES) clean \
		mostrar_archivos lectura help \