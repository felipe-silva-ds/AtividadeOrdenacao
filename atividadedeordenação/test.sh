#!/bin/bash

# Nome do executável
EXECUTABLE=./sorting_algorithms

# Pasta contendo arquivos de entrada de teste
TEST_DIR=test_cases

# Verifica se o diretório de testes existe
if [ ! -d "$TEST_DIR" ]; then
    echo "Diretório de testes não encontrado: $TEST_DIR"
    exit 1
fi

# Itera sobre todos os arquivos de entrada no diretório de testes
for TEST_FILE in "$TEST_DIR"/*.in; do
    # Verifica se há arquivos correspondentes
    if [ ! -e "$TEST_FILE" ]; then
        echo "Nenhum arquivo de teste encontrado no diretório: $TEST_DIR"
        exit 1
    fi

    echo "Executando teste com o arquivo: $TEST_FILE"
    $EXECUTABLE $TEST_FILE
    echo "-------------------------------------------------"
done
