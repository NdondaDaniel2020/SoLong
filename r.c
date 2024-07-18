/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 15:18:49 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <fcntl.h> // Para open
#include <unistd.h> // Para read e close
#include <stdlib.h>
#include <stdio.h>

// Estrutura para armazenar os dados da MiniLibX
typedef struct {
    void    *mlx;
    void    *win;
} t_data;

// Função para ler o conteúdo de um arquivo e retornar como string
char *read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    // Determina o tamanho do arquivo
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Erro ao determinar o tamanho do arquivo");
        close(fd);
        return NULL;
    }
    lseek(fd, 0, SEEK_SET);

    // Aloca memória para o conteúdo do arquivo
    char *content = (char *)malloc(file_size + 1);
    if (content == NULL) {
        perror("Erro ao alocar memória");
        close(fd);
        return NULL;
    }

    // Lê o conteúdo do arquivo
    ssize_t bytes_read = read(fd, content, file_size);
    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo");
        free(content);
        close(fd);
        return NULL;
    }
    content[bytes_read] = '\0'; // Adiciona o terminador nulo

    close(fd);
    return content;
}

int main() {
    t_data  data;

    // Lê o conteúdo de um arquivo
    char *file_content = read_file("map/map1.txt");
    if (file_content == NULL) {
        return 1;
    }

    // Inicializa a conexão com o servidor gráfico
    data.mlx = mlx_init();
    if (data.mlx == NULL) {
        fprintf(stderr, "Erro ao inicializar MiniLibX\n");
        free(file_content);
        return 1;
    }

    // Cria uma janela de 800x600 pixels
    data.win = mlx_new_window(data.mlx, 800, 600, "Exemplo com Arquivo");
    if (data.win == NULL) {
        fprintf(stderr, "Erro ao criar a janela\n");
        free(file_content);
        return 1;
    }

    // Exibe o conteúdo do arquivo na janela
    mlx_string_put(data.mlx, data.win, 50, 50, 0xFFFFFF, file_content);

    // Loop para manter a janela aberta até que o usuário a feche
    mlx_loop(data.mlx);

    free(file_content);
    return 0;
}
