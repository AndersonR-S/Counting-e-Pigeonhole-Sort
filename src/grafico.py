import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

# Verificar se o diretório de destino existe, caso contrário, crie-o
save_path = 'dataget/img'
if not os.path.exists(save_path):
    os.makedirs(save_path)

def graficoSort(data, title, save_path):
    sort = ['counting', 'pigeonhole']

    plt.clf()  # Limpa a figura atual
    plt.figure(figsize=(10, 6))

    # Determinando a largura das barras e a quantidade de grupos
    num_linhas = len(data)
    largura_barra = 0.25
    indices = np.arange(len(data.columns))

    # Plotando cada linha como barras agrupadas
    for i, (indice, linha) in enumerate(data.iterrows()):
        # Ajuste na posição dos ticks do eixo x para centralizar
        posicao_ticks = indices + largura_barra * (i - (num_linhas - 1) / 2)
        plt.bar(posicao_ticks, linha, width=largura_barra, label=f'{sort[i]}')

    # Configurando os detalhes do gráfico
    plt.title(f'Representação em {title}')
    plt.xlabel('Variação de Códigos')
    plt.ylabel('Valores dos Tempos Médios')

    # Centralizando os ticks do eixo x
    plt.xticks(indices, data.columns)

    plt.grid(True)
    plt.legend()

    # Exibindo o gráfico
    plt.tight_layout()

    # Salvando o gráfico
    save_file = os.path.join(save_path, f'{title.lower().replace(" ", "_")}_grafico.png')
    plt.savefig(save_file, format='png')
    plt.close()  # Fechar a figura após salvar


# Leitura do arquivo CSV (substitua pelo caminho do seu arquivo CSV)
dados = pd.read_csv("dataget/output.csv",index_col=0)

# Plotando gráficos para desordenado e ordenado
graficoSort(dados.iloc[:-2], 'Desordenado', save_path)
graficoSort(dados.iloc[2:], 'Ordenado', save_path)

