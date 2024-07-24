import os
import matplotlib.pyplot as plt
import numpy as np

def graficoSort(data, title, save_path):
    sort = ['counting', 'pigeonhole']

    plt.clf()
    plt.figure(figsize=(10, 6))

    num_linhas = len(data)
    largura_barra = 0.25
    indices = np.arange(len(data.columns))

    for i, (indice, linha) in enumerate(data.iterrows()):
        posicao_ticks = indices + largura_barra * (i - (num_linhas - 1) / 2)
        plt.bar(posicao_ticks, linha, width=largura_barra, label=f'{sort[i]}')

    plt.title(f'Representação em {title}')
    plt.xlabel('Variação de Códigos')
    plt.ylabel('Valores dos Tempos Médios em ns')
    plt.xticks(indices, data.columns)

    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    save_file = os.path.join(save_path, f'{title.lower().replace(" ", "_")}_grafico.png')
    plt.savefig(save_file, format='png')
    plt.close()