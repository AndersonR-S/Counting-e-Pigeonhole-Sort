import GraficoSort as gs
import GraficoComparacao as gc
import pandas as pd
import os

# Caminhos para salvar as imagens e buscar os arquivos CSV
SAVE_PATH = 'dataget/img'
OUTPUT_DIR = 'dataget/output'

def listar_arquivos_em_diretorio(diretorio):

    nomes_arquivos = []
    for item in os.listdir(diretorio):
        caminho_completo = os.path.join(diretorio, item)
        if os.path.isfile(caminho_completo):
            n = item.split(':')
            k = n[1].split('.')
            nomes_arquivos.append([n[0], k[0], item])
    return nomes_arquivos

def gerar_graficos_ordenacao(arquivos, diretorio, save_path):

    caminho_endere = os.path.join(save_path, 'graphSort')
    os.makedirs(caminho_endere, exist_ok=True)

    for arquivo_info in arquivos:
        arquivo_path = os.path.join(diretorio, arquivo_info[2])
        print(f'Lendo o arquivo: {arquivo_path}')

        dados = pd.read_csv(arquivo_path, index_col=False)
        gs.graficoSort(dados.iloc[:-2], f'{arquivo_info[0]}:{arquivo_info[1]} - Desordenado', caminho_endere)
        gs.graficoSort(dados.iloc[2:], f'{arquivo_info[0]}:{arquivo_info[1]} - Ordenado', caminho_endere)

def preparar_dados_para_comparacao(arquivos, index):

    dados_salvo = []
    n_escolhido = []

    for arquivo_info in arquivos:
        n_endereco = []
        if arquivo_info[0] != '' and arquivo_info[1] != '' and arquivo_info[index] not in [x[index] for x in n_escolhido]:
            n_endereco.append(arquivo_info)
            for other_info in arquivos:
                if arquivo_info == other_info:
                    continue
                if arquivo_info[index] == other_info[index]:
                    n_endereco.append(other_info)
            n_escolhido.append(arquivo_info)
            dados_salvo.append(n_endereco)

    return dados_salvo

def gerar_graficos_comparacao(dados_salvo, comparacao_func, diretorio, save_path):

    for grupo in dados_salvo:
        if len(grupo) > 1:
            comparacao_func(grupo, diretorio, save_path)




# Início da execução do script
arquivos = listar_arquivos_em_diretorio(OUTPUT_DIR)
print(arquivos)

gerar_graficos_ordenacao(arquivos, OUTPUT_DIR, SAVE_PATH)

# Gerar gráficos de comparação N
dados_salvo_n = preparar_dados_para_comparacao(arquivos, index=0)
gerar_graficos_comparacao(dados_salvo_n, gc.graficoComparacaoN, OUTPUT_DIR, SAVE_PATH)

# Gerar gráficos de comparação K
dados_salvo_k = preparar_dados_para_comparacao(arquivos, index=1)
gerar_graficos_comparacao(dados_salvo_k, gc.graficoComparacaoK, OUTPUT_DIR, SAVE_PATH)
