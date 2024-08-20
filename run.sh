#!/bin/bash

# Loop pelos arquivos com extensão .c no diretório atual
for file in *.c; do
    # Verifica se é um arquivo regular (e não um diretório ou algo mais)
    if [ -f "$file" ]; then
        # Remove a extensão .c do nome do arquivo
        base_name="${file%.c}"
        # Cria o novo nome do arquivo com _bonus antes da extensão .c
        new_name="${base_name}_bonus.c"
        # Renomeia o arquivo
        mv "$file" "$new_name"
    fi
done
