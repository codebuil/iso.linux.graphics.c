import pygame
import sys
import winsound

# Inicialização do Pygame
pygame.init()
#pip install pygame
# Configurações da tela
largura_tela = 800
altura_tela = 600
tela = pygame.display.set_mode((largura_tela, altura_tela))
pygame.display.set_caption("Jogo de Plataforma")

# Cores
branco = (255, 255, 255)
azul = (0, 0, 255)
amarelo=(255,255,0)
vermelho=(255,0,0)

# Personagem (sorriso)
sorriso = pygame.Rect(50, 450, 40, 40)
velocidade_x = 0
velocidade_y = 0
pulando = False

# Plataformas
plataformas = [pygame.Rect(50, 500, 200, 10),
               pygame.Rect(300, 400, 200, 10),
               pygame.Rect(500, 300, 200, 10)]

# Escadas
escadas = [pygame.Rect(290, 400, 20, 100),
           pygame.Rect(490, 300, 20, 100)]

# Coração
coracao = pygame.Rect(700, 500, 40, 40)
coracao_ativo = True

# Loop principal do jogo
while True:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if evento.type == pygame.KEYDOWN:
            if evento.key == pygame.K_LEFT:
                velocidade_x = -1
                winsound.Beep(500, 150)
            if evento.key == pygame.K_RIGHT:
                velocidade_x = 1
                winsound.Beep(500, 150)
            if evento.key == pygame.K_SPACE and not pulando:
                velocidade_y = -60
                pulando = True
                winsound.Beep(500, 100)
        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT or evento.key == pygame.K_RIGHT:
                velocidade_x = 0
                winsound.Beep(500, 100)

    # Movimentação horizontal
    sorriso.x += velocidade_x

    # Detecta colisões com plataformas
    colisoes = sorriso.collidelist(plataformas)
    if colisoes != -1:
        if velocidade_x > 0:
            sorriso.right = plataformas[colisoes].left
        if velocidade_x < 0:
            sorriso.left = plataformas[colisoes].right

    # Movimentação vertical
    if not pulando:
        velocidade_y = 1  # Gravidade
    sorriso.y += velocidade_y
    pulando=False
    
    

    # Detecta colisões com plataformas e escadas
    colisoes = sorriso.collidelist(plataformas)
    if colisoes != -1:
        if velocidade_y > 0:
            sorriso.bottom = plataformas[colisoes].top
            pulando = False
            velocidade_y = 0
        if velocidade_y < 0:
            sorriso.top = plataformas[colisoes].bottom
            velocidade_y = 0

    colisoes = sorriso.collidelist(escadas)
    if colisoes != -1:
        if velocidade_y < 0:
            sorriso.top = escadas[colisoes].bottom
            velocidade_y = 0

    # Detecta colisão com o coração
    if sorriso.colliderect(coracao) and coracao_ativo:
        coracao_ativo = False

    # Limpa a tela
    tela.fill(amarelo)

    # Desenha as plataformas
    for plataforma in plataformas:
        pygame.draw.rect(tela, azul, plataforma)

    # Desenha as escadas
    for escada in escadas:
        pygame.draw.rect(tela,azul, escada)

    # Desenha o coração
    if coracao_ativo:
        pygame.draw.rect(tela,vermelho , coracao)
    else:
        coracao.x = -100  # Esconde o coração

    # Desenha o sorriso
    pygame.draw.rect(tela, branco, sorriso)

    # Atualiza a tela
    pygame.display.flip()
