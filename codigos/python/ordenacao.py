import time

def ordenacaoCounting(a):

    c = [0] * (max(a) + 1)
    for i in a:
        c[i] += 1

    for i in range(1,len(c)):
        c[i] += c[i - 1]

    b = [0] * len(a)
    for i in reversed(a):
        b[c[i] - 1] = i
        c[i] -= 1

    return b

def ordenacaoPigeonhole(a):

    minimum = min(a)
    maximum = max(a)

    size = maximum - minimum + 1

    c = [0] * size
    for i in a:
        c[i - minimum] += 1

    i=0
    for j in range(size):
        while c[j] > 0:
            c[j] -= 1
            a[i] = j + minimum
    return a

def tempo(a):

    #counting sort
    tempo_ting = 0
    for i in range(10):
        tempo_inicial = time.time_ns()
        ordenacaoCounting(list(a))
        tempo_final = time.time_ns()
        tempo_ting += tempo_final - tempo_inicial

    tempo_ting = tempo_ting/10

    #pigeonhole sort
    tempo_hole = 0
    for i in range(10):
        tempo_inicial = time.time_ns()
        ordenacaoPigeonhole(list(a))
        tempo_final = time.time_ns()
        tempo_hole += tempo_final - tempo_inicial

    tempo_hole = tempo_hole /10

    return [int(tempo_ting), int(tempo_hole)]
    

