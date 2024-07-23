import GraficoSort as gs
import GraficoComparacao as gc
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

save_path = 'dataget/img'
diretorio = 'dataget/output'


def listar_arquivos_em_diretorio(diretorio):
    nomes_arquivos = []

    for item in os.listdir(diretorio):
        caminho_completo = os.path.join(diretorio, item)
        
        if os.path.isfile(caminho_completo):
            n = item.split(':')
            k = n[1].split('.')
            nomes_arquivos.append([n[0],k[0],item])
    
    return nomes_arquivos

## Inicio
arquivos = listar_arquivos_em_diretorio(diretorio)
print(arquivos)

caminho_endere = f'{save_path}/graphSort'
os.makedirs(caminho_endere, exist_ok=True)

for i in arquivos:
    arquivo_path = f'{diretorio}/{(i[2])}'
    print(f'Lendo o arquivo: {arquivo_path}')
    dados = pd.read_csv(arquivo_path, index_col=0)
    
    gs.graficoSort(dados.iloc[:-2], f'{i[0]}:{i[1]} - Desordenado', caminho_endere)
    gs.graficoSort(dados.iloc[2:], f'{i[0]}:{i[1]} - Ordenado', caminho_endere)

dados_salvo = []
n_escolhido = []

for i in arquivos:
    n_endereco = []  # Clear n_endereco for each new 'i'
    # Verifique se ambos i[0] e i[1] são não vazios e se i[0] ainda não está em n_escolhido
    if i[0] != '' and i[1] != '' and i[0] not in [x[0] for x in n_escolhido]:
        n_endereco.append(i)
        for j in arquivos:
            if i == j:
                continue
            if i[0] == j[0]:
                n_endereco.append(j)
        n_escolhido.append(i)
        dados_salvo.append(n_endereco)  # Adiciona n_endereco a dados_salvo somente se não estiver vazio


for i in dados_salvo:
    if len(i) > 1:
            gc.graficoComparacaoN(i,diretorio,save_path)


dados_salvo = []
n_escolhido = []

for i in arquivos:
    n_endereco = []  # Clear n_endereco for each new 'i'
    # Verifique se ambos i[0] e i[1] são não vazios e se i[1] ainda não está em n_escolhido
    if i[0] != '' and i[1] != '' and i[1] not in [x[1] for x in n_escolhido]:
        n_endereco.append(i)
        for j in arquivos:
            if i == j:
                continue
            if i[1] == j[1]:
                n_endereco.append(j)
        n_escolhido.append(i)
        dados_salvo.append(n_endereco)  # Adiciona n_endereco a dados_salvo somente se não estiver vazio


for i in dados_salvo:
    if len(i) > 1:
        gc.graficoComparacaoK(i,diretorio,save_path)
