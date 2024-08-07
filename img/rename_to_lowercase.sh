#!/bin/bash

# Loop através de todos os arquivos no diretório atual
for FILE in *; do
  # Verifica se é um arquivo (e não um diretório)
  if [ -f "$FILE" ]; then
    # Converte o nome do arquivo para minúsculas
    LOWERCASE_FILE=$(echo "$FILE" | tr '[:upper:]' '[:lower:]')
    # Renomeia o arquivo se o nome em minúsculas for diferente do original
    if [ "$FILE" != "$LOWERCASE_FILE" ]; then
      mv "$FILE" "$LOWERCASE_FILE"
      echo "Renomeado: $FILE -> $LOWERCASE_FILE"
    fi
  fi
done
