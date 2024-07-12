import time

def ordenacaoCounting(a):

    c = [0] * (max(a) + 1)

    # Passo 1: Contagem das ocorrências dos elementos
    for i in a:
        c[i] += 1

    # Passo 2: Determinação das posições finais
    for i in range(1,len(c)):
        c[i] += c[i - 1]

    # Passo 3: Construção do array ordenado
    b = [0] * len(a)
    for i in reversed(a):
        b[c[i] - 1] = i
        c[i] -= 1

    return b

def ordenacaoPigeonhole(a):

    minimum = min(a)
    maximum = max(a)

    #Determinar o tamanho do vetor
    size = maximum - minimum + 1

    #Criar os  Pigeonholes
    c = [0] * size
    for i in a:
        c[i - minimum] += 1

    i=0
    for j in range(size):
        while c[j] > 0:
            c[j] -= 1
            a[i] = j + minimum
    return a

def ordenar(a):

    #counting sort
    tempo_coun = 0
    for i in range(10):
        tempo_inicial = time.time_ns()
        ordenacaoCounting(list(a))
        tempo_final = time.time_ns()
        tempo_coun += tempo_final - tempo_inicial

    tempo_coun = tempo_coun/10

    #pigeonhole sort
    tempo_hole = 0
    for i in range(10):
        tempo_inicial = time.time_ns()
        ordenacaoPigeonhole(list(a))
        tempo_final = time.time_ns()
        tempo_hole += tempo_final - tempo_inicial

    tempo_hole = tempo_hole /10

    return [tempo_coun, tempo_hole]
    

