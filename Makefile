################################################################################
## Fichero «Makefile» para los programas de prueba de recorridos de vectores de
## tipos primitivos («int») y de registros(«Persona»)
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS

SOURCE_REGISTROS_DIR = algoritmos-vectores-registros
SOURCE_PRIMITIVOS_DIR = algoritmos-vectores-primitivos
SOURCE_PERSONAS_DIR = ../tema-11-registros/
BUILD_DIR = build
BIN_DIR = bin

# Variable preestablecida de «make» que en la que se pueden definir los 
# directorios en los que pueden hallarse los ficheros de codigo fuente a 
# compilar, con el objetivo de evitar tenerlos que poner de forma explícita
# en las reglas. 
VPATH = $(SOURCE_REGISTROS_DIR) $(SOURCE_PRIMITIVOS_DIR) $(SOURCE_PERSONAS_DIR)


## COMPILADOR Y OPCIONES DE COMPILACIÓN:

# Variable preestablecida de «make» que en la que se puede definir el nombre del
# compilador. Esto permite que «make» genere recetas y reglas por defecto. 
CXX = g++

# Variable preestablecida de «make» que en la que se puede definir las opciones
# con las que debe invocarse al compilador.
CXXFLAGS = -g -Wall -Wextra -I$(SOURCE_PERSONAS_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):

# Variable para definir la lista
# de ficheros objeto de los que depende el programa «permisos».
OBJECTS_REGISTROS = $(addprefix $(BUILD_DIR)/, 1-algoritmos-recorrido-regs.o \
				2-algoritmos-busqueda-regs.o 3-algoritmos-modificacion-regs.o \
				main-vectores-registros.o persona.o nif.o fecha.o)

# Variable para definir la lista
# de ficheros objeto de los que depende el programa «racionales».
OBJECTS_PRIMITIVOS = $(addprefix $(BUILD_DIR)/, 1-algoritmos-recorrido-ints.o \
				2-algoritmos-busqueda-ints.o 3-algoritmos-modificacion-ints.o \
				main-vectores-enteros.o)

################################################################################
## Reglas del fichero «Makefile»

ejemplo-vectores-registros: $(OBJECTS_REGISTROS) | $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$@ -g $(OBJECTS_REGISTROS) 

ejemplo-vectores-enteros: $(OBJECTS_PRIMITIVOS) | $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$@ -g $(OBJECTS_PRIMITIVOS) 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(OBJECTS_REGISTROS): algoritmos-vectores-registros.hpp 
$(OBJECTS_PRIMITIVOS): algoritmos-vectores-enteros.hpp

# Reglas con objetivo pero sin prerrequisitos, que establecen como crear 
# los directorios bin y build.
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS_REGISTROS) $(OBJECTS_PRIMITIVOS) $(BIN_DIR)/*
endif
