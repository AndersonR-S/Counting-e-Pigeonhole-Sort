import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

def gerarGraficosK(dados, data, head, tible, save_path):
    os.makedirs(save_path, exist_ok=True)
    
    plt.figure(figsize=(10, 6))
    
    x = [int(d[0]) for d in data]
    
    for i, linguagem in enumerate(head):
        y = dados[i]
        
        # Verifica se y é uma lista
        if not isinstance(y, list):
            print(f"Aviso: y não é uma lista para {linguagem}. Dados: {y}")
            continue
        
        # Verifica se x e y têm o mesmo comprimento
        if len(x) != len(y):
            print(f"Aviso: x e y têm tamanhos diferentes para {linguagem}.")
            print(f"x: {len(x)} elementos")
            print(f"y: {len(y)} elementos")
            continue
        
        plt.plot(x, y, label=linguagem)
    
    plt.xlabel('Valor X (data[0])')
    plt.ylabel('Valores')
    plt.title(tible)
    plt.legend()
    
    # plt.savefig(f'{save_path}/{titulo}.png', format='png')
    save_file = os.path.join(save_path, f'{tible.lower().replace(" ", "_")}_grafico.png')
    plt.savefig(save_file, format='png')



def gerarGraficosN(dados_coun, data, headhead,tible, save_path):
    os.makedirs(save_path, exist_ok=True)
    plt.figure(figsize=(12, 8))

    # Itera sobre cada linguagem para plotar
    for idx, language in enumerate(headhead):
        if idx >= len(dados_coun):
            print(f"Índice {idx} fora do intervalo de dados.")
            continue
        
        y = dados_coun[idx]  # Dados da linguagem para o eixo y
        x = [entry[1] for entry in data]  # Dados do eixo x (data[1])
        
        # Verifica se há dados suficientes para plotar
        if len(x) == len(y) and len(x) > 0:
            plt.plot(x, y, label=language)
        else:
            print(f"Dados insuficientes para a linguagem {language}")

    plt.xlabel('Valor de k')
    plt.ylabel('Valores dos Tempos Médios em ns')
    plt.title(f'Representação em {tible}')
    plt.legend()
    
    #plt.savefig(f'{save_path}/comparacao.png', format='png')
    save_file = os.path.join(save_path, f'{tible.lower().replace(" ", "_")}_grafico.png')
    plt.savefig(save_file, format='png')



def graficoComparacaoN(data, diretoria, save_path):
    # Ordena a lista de dados em relação a primeira posição
    data = sorted(data, key=lambda x: (int(x[0]), int(x[1])))
    print("Dados ordenados:", data)

    # Inicializa as listas para armazenar dados
    dados_linguagem_coun = []
    dados_linguagem_hole = []

    # Preenche as listas com dados dos arquivos CSV
    for i in data:
        caminho_completo = f'{diretoria}/{i[2]}'
        print(f'Lendo o arquivo: {caminho_completo}')
        
        try:
            dados_tabela = pd.read_csv(caminho_completo)
            
            # Verifica se o DataFrame tem pelo menos 2 linhas e o número esperado de colunas
            if dados_tabela.shape[0] < 2 or dados_tabela.shape[1] < 2:
                raise ValueError(f"Arquivo {caminho_completo} não contém linhas ou colunas suficientes.")

            # Adiciona a primeira linha de dados à lista dados_linguagem_coun
            if len(dados_linguagem_coun) == 0:
                dados_linguagem_coun = [[] for _ in range(dados_tabela.shape[1])]
                dados_linguagem_hole = [[] for _ in range(dados_tabela.shape[1])]

            # Adiciona a primeira linha de dados à lista dados_linguagem_coun
            dados_linguagem_coun = [c + [v] for c, v in zip(dados_linguagem_coun, dados_tabela.iloc[0].tolist())]

            # Adiciona a segunda linha de dados à lista dados_linguagem_hole
            dados_linguagem_hole = [h + [v] for h, v in zip(dados_linguagem_hole, dados_tabela.iloc[1].tolist())]

        except Exception as e:
            print(f"Erro ao processar o arquivo {caminho_completo}: {e}")

    # Converte os dados para tipos primitivos e lida com NaN
    dados_linguagem_coun = [[val if not pd.isna(val) else None for val in col] for col in dados_linguagem_coun]
    dados_linguagem_hole = [[val if not pd.isna(val) else None for val in col] for col in dados_linguagem_hole]

    head = ["python", "js", "php", "c", "c++", "java"]
    print("Dados Linguagem Counting: k = x")
    for line in dados_linguagem_coun:
        print(line)
    
    print('\nDados Linguagem Pigeonhole:')
    for line in dados_linguagem_hole:
        print(line)

    gerarGraficosN(dados_linguagem_coun, data, head,f'Counting N = {data[0][0]} K = x', f'{save_path}/graphComparar')
    gerarGraficosN(dados_linguagem_hole, data, head,f'Pigeonhole N = {data[0][0]} K = x', f'{save_path}/graphComparar')



def graficoComparacaoK(data, diretorio, save_path):
    # Ordena a lista de dados em relação ao primeiro elemento (data[0])
    data = sorted(data, key=lambda x: int(x[0]))
    print("Dados ordenados:", data)

    # Inicializa as listas para armazenar dados
    dados_linguagem_coun = []
    dados_linguagem_hole = []

    # Preenche as listas com dados dos arquivos CSV
    for i in data:
        caminho_completo = f'{diretorio}/{i[2]}'
        print(f'Lendo o arquivo: {caminho_completo}')
        
        try:
            dados_tabela = pd.read_csv(caminho_completo)
            
            # Verifica se o DataFrame tem pelo menos 2 linhas e o número esperado de colunas
            if dados_tabela.shape[0] < 2 or dados_tabela.shape[1] < 2:
                raise ValueError(f"Arquivo {caminho_completo} não contém linhas ou colunas suficientes.")

            # Inicializa listas se estiver vazio
            if len(dados_linguagem_coun) == 0:
                dados_linguagem_coun = [[] for _ in range(dados_tabela.shape[1])]
                dados_linguagem_hole = [[] for _ in range(dados_tabela.shape[1])]

            # Adiciona os dados de cada linha à lista correspondente
            for idx, val in enumerate(dados_tabela.iloc[0]):
                if not pd.isna(val):
                    dados_linguagem_coun[idx].append(val)

            for idx, val in enumerate(dados_tabela.iloc[1]):
                if not pd.isna(val):
                    dados_linguagem_hole[idx].append(val)

        except Exception as e:
            print(f"Erro ao processar o arquivo {caminho_completo}: {e}")

    # Define os rótulos para as linguagens
    head = ["python", "js", "php", "c", "c++", "java"]
    print("Dados Linguagem Counting n = x:")
    for line in dados_linguagem_coun:
        print(line)
    
    print('\nDados Linguagem Pigeonhole:')
    for line in dados_linguagem_hole:
        print(line)
    

    gerarGraficosK(dados_linguagem_coun, data, head, f'Counting N = x   K = {data[0][1]}', f'{save_path}/graphComparar')
    gerarGraficosK(dados_linguagem_hole, data, head, f'Pigeonhole N = x   k = {data[0][1]}', f'{save_path}/graphComparar')