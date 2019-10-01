pontos_computador = 0
pontos_usuario = 0
def campeonato():
    
    print("##### PARTIDA 01 #####")
    partida()
    print("##### PARTIDA 02 #####")
    partida()
    print("##### PARTIDA 03 #####")
    partida()
    
    if pontos_usuario > pontos_computador:
        print("Você venceu o campeonato por {}x{}".format(pontos_usuario,pontos_computador))
    else:
        print("Você perdeu o campeonato por {}x{}".format(pontos_computador,pontos_usuario))

def partida():
    global pontos_computador
    global pontos_usuario
    
    qnt_pecas = set_pecas()
    lmt_pecas_possivel = set_limite_pecas()
    
    if lmt_pecas_possivel > qnt_pecas:
        print("Nao ha como tirar mais  do que {} pecas".format(qnt_pecas))
        qnt_pecas = set_pecas()
        lmt_pecas_possivel = set_limite_pecas()
    
    if qnt_pecas % (lmt_pecas_possivel + 1) == 0 :
        print("Voce comeca!")
        auxUsuario = True
    else:
        print("Computador comeca!")
        auxUsuario = False
        
    while qnt_pecas > 0:
        if auxUsuario:
            #usuario joga
            qnt_pecas -= usuario_escolhe_jogada(qnt_pecas, lmt_pecas_possivel)
            if qnt_pecas == 0:
                print("Você venceu!")
                pontos_usuario+=1
                break
            print("Sobraram {} peças na mesa.".format(qnt_pecas))
            auxUsuario = not auxUsuario
        else:
            #computador joga
            print("Jogada do computador.")
            qnt_pecas -= computador_escolhe_jogada(qnt_pecas, lmt_pecas_possivel)
            if qnt_pecas == 0:
                print("O computador venceu!")
                pontos_computador+=1
                break
            print("Sobraram {} peças na mesa.".format(qnt_pecas))
            auxUsuario = not auxUsuario

def set_pecas():
    return int(input("Quantas pecas?"))

def set_limite_pecas():
    return int(input("Limite de pecas por jogada?"))

def usuario_escolhe_jogada(n,m):
    qnt_usuario_remove=int(input("Quantas pecas deseja tirar ?"))

    if n<n-qnt_usuario_remove:
        print("Voce nao pode tirar mais pecas do que ha na mesa")
        qnt_usuario_remove = usuario_escolhe_jogada(n,m)

    if qnt_usuario_remove>m:
        print("Valor invalido ! Voce pode tirar no maximo {} pecas".format(m))
        qnt_usuario_remove = usuario_escolhe_jogada(n,m)

    print("O usuario removeu {} pedras da mesa".format(qnt_usuario_remove))
    return qnt_usuario_remove

def computador_escolhe_jogada(qnt_pecas,limite_pecas_jogada):
    if limite_pecas_jogada == 1:
        return 1
    for i in range(1,limite_pecas_jogada+1,1):
        if (qnt_pecas-i) % (limite_pecas_jogada+1) == 0:
            print("O computador removeu {} pecas do tabuleiro".format(i))
            return i

print("Bem-Vindo ao jogo do Nim\n\n")
modo_jogo=int(input("1- Para jogar uma partida isolada\n2- Para jogar um campeonato\n"))
if modo_jogo == 1:
    partida()
if modo_jogo == 2:
    campeonato()