# so_long 🥷 (Ninja SoLong)

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics: MiniLibX](https://img.shields.io/badge/Graphics-MiniLibX-purple?style=for-the-badge)](https://github.com/42School/minilibx-linux)

Um jogo 2D desenvolvido em C utilizando a biblioteca gráfica **MiniLibX**. O objetivo principal é guiar uma Kunoichi (ninja) através de um dojo para coletar estrelas e escapar por um portal místico, tudo isso enquanto desvia de obstáculos e inimigos (na versão Bônus).

---

## 📑 Índice / Table of Contents
- [Funcionalidades / Features](#-funcionalidades--features)
- [Controles / Controls](#-controles--controls)
- [Estrutura do Mapa / Map Structure](#-estrutura-do-mapa--map-structure)
- [Instalação e Compilação / Installation & Compilation](#-instalação-e-compilação--installation--compilation)
- [Como Jogar / How to Play](#-como-jogar--how-to-play)
- [Estrutura do Projeto / Project Structure](#-estrutura-do-projeto--project-structure)

---

## ✨ Funcionalidades / Features

### Parte Obrigatória (Mandatory)
* **Gráficos 2D:** Renderização de texturas `.xpm` (tatames, estrelas, personagem e portal).
* **Contagem de Movimentos:** O número de movimentos é exibido diretamente no terminal a cada passo dado.
* **Colisões Realistas:** O jogador não pode atravessar paredes (`1`).
* **Validação de Caminho:** Validação rigorosa para garantir que o mapa seja jogável (verificação de caminhos válidos até todos os colecionáveis e saída usando algoritmos de flood fill).

### Parte Bônus (Bonus)
* **Gravidade e Física 2D:** Mecânica inspirada em jogos de plataforma (queda automática quando não há blocos embaixo).
* **Animações Fluidas:**
  * Kunoichi: Animações de repouso (idle), corrida (run), pulo (jump) e morte (death).
  * Portal: Animação de rotação contínua.
  * Inimigos: Patrulha e animações de ataque/morte.
* **Sistema de Combate:** O jogador pode derrotar o inimigo caindo em cima dele. Bater de frente com o inimigo resulta em morte.
* **Interface (HUD):** Contador de movimentos e de estrelas coletadas desenhado dinamicamente na tela do jogo (`mlx_string_put`).

---

## 🎮 Controles / Controls

### Versão Obrigatória (Mandatory)
* **Movimentação:**
  * <kbd>▲</kbd> / <kbd>W</kbd> ou <kbd>Seta Para Cima</kbd> : Mover para cima
  * <kbd>▼</kbd> / <kbd>S</kbd> ou <kbd>Seta Para Baixo</kbd> : Mover para baixo
  * <kbd>◀</kbd> / <kbd>A</kbd> ou <kbd>Seta Para Esquerda</kbd> : Mover para a esquerda
  * <kbd>▶</kbd> / <kbd>D</kbd> ou <kbd>Seta Para Direita</kbd> : Mover para a direita
* **Sair:**
  * <kbd>ESC</kbd> : Fecha o jogo e limpa a memória de forma segura.
  * Botão de Fechar da Janela (`X`) : Fecha o jogo.

### Versão Bônus (Platformer Physics)
* **Movimentação:**
  * <kbd>◀</kbd> ou <kbd>Seta Para Esquerda</kbd> : Mover para a esquerda
  * <kbd>▶</kbd> ou <kbd>Seta Para Direita</kbd> : Mover para a direita
  * <kbd>▲</kbd> ou <kbd>Seta Para Cima</kbd> : Pular (jump)
* **Queda (Gravidade):** O jogador cai automaticamente caso não esteja sobre um tatame (`1`).
* **Sair:**
  * <kbd>ESC</kbd> ou fechar no `X` da janela.

---

## 🗺️ Estrutura do Mapa / Map Structure

Os mapas devem ser fornecidos em arquivos com a extensão `.ber` e seguir as seguintes regras de caracteres:

| Caractere | Elemento | Descrição |
| :---: | :--- | :--- |
| **`1`** | Parede | Obstáculo intransponível (Tatame/Dojo parede). |
| **`0`** | Espaço Vazio | Caminho livre para movimentação. |
| **`C`** | Colecionável | Estrela ninja que deve ser coletada. |
| **`P`** | Jogador | Posição inicial do jogador (Kunoichi). |
| **`E`** | Saída | O portal místico para concluir a fase. |
| **`A`** | Inimigo (Bônus) | Inimigo móvel que patrulha e pode te eliminar. |

### Regras de Validação do Mapa
1. O mapa deve ser retangular (todas as linhas com o mesmo comprimento).
2. O mapa deve ser completamente cercado por paredes (`1`).
3. Deve conter exatamente **1 jogador (`P`)**, exatamente **1 saída (`E`)** e pelo menos **1 colecionável (`C`)**.
4. Deve haver um caminho válido da posição inicial para todas as estrelas e para a saída.

Exemplo de mapa válido (`maps/map1.ber`):
```text
11111111111111111111
10010000000C111C00C1
10000111110000011011
1P0C0100000C110000E1
11111111111111111111
```

---

## 🛠️ Instalação e Compilação / Installation & Compilation

### Pré-requisitos (Debian/Ubuntu)
Como o projeto utiliza a biblioteca **MiniLibX**, certifique-se de que os pacotes de desenvolvimento do sistema X11 e Xorg estejam instalados:

```bash
sudo apt-get update
sudo apt-get install -y make gcc clang libx11-dev libxext-dev libbsd-dev
```

### Instruções de Compilação
Navegue até o diretório do projeto e execute os seguintes comandos no terminal:

* **Compilar Parte Obrigatória:**
  ```bash
  make
  ```
  Isso gerará o executável `./so_long`.

* **Compilar Parte Bônus:**
  ```bash
  make bonus
  ```
  Isso gerará o executável `./so_long_bonus`.

* **Limpar Arquivos Objetos (`.o`):**
  ```bash
  make clean
  ```

* **Limpar Tudo (Objetos e Executáveis):**
  ```bash
  make fclean
  ```

* **Recompilar Projeto:**
  ```bash
  make re
  ```

---

## 🚀 Como Jogar / How to Play

Para executar o jogo, passe o caminho do mapa desejado como argumento para o executável:

### Versão Obrigatória
```bash
./so_long maps/map1.ber
```

### Versão Bônus
```bash
./so_long_bonus maps/map_bonus_6.ber
```

---

## 📂 Estrutura do Projeto / Project Structure

```text
.
├── include/                 # Cabeçalhos do projeto (.h)
│   ├── so_long.h            # Cabeçalho da parte obrigatória
│   └── so_long_bonus.h      # Cabeçalho da parte bônus
├── src/                     # Código-fonte principal (.c)
│   ├── bonus/               # Código-fonte da versão bônus
│   └── (arquivos C da versão obrigatória)
├── libft/                   # Biblioteca C personalizada (Libft)
├── minilibx-linux/          # Biblioteca gráfica MiniLibX
├── maps/                    # Mapas de jogo (.ber)
├── textures/                # Texturas e sprites (.xpm)
├── Makefile                 # Automação de compilação
└── README.md                # Esta documentação
```
