void create_map(t_wind *window) {
    int l, c, x, y, i;

    l = 0;
    i = 0;  // Inicializa a variável i
    window->images = (t_image *)ft_calloc(count_occurrence(window->map_matrix, '1'), sizeof(t_image));
    if (!window->images) {
        fprintf(stderr, "Erro ao alocar memória para imagens\n");
        exit(1);
    }
    y = 0; // Inicializa y fora dos loops
    while (window->map_matrix[l]) {
        c = 0;
        x = 0; // Reinicia x para cada nova linha
        while (window->map_matrix[l][c]) {
            if (window->map_matrix[l][c] == '1') {
                window->images[i].img_ptr = mlx_xpm_file_to_image(window->mlx, tatame1(), &window->images[i].width, &window->images[i].height);
                if (!window->images[i].img_ptr) {
                    fprintf(stderr, "Erro ao carregar a imagem do tatame\n");
                    exit(1);
                }
                mlx_put_image_to_window(window->mlx, window->win, window->images[i].img_ptr, x, y);
                i++;
            }
            x += 50; // Incrementa x dentro do loop de colunas
            c++;
        }
        y += 50; // Incrementa y após cada linha
        l++;
    }
}
