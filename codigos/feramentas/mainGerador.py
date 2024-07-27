import pandas as pd
import numpy as np

try:
    ## Gerando os números aleatórios e salvando no input_a.csv
    numeros = {'numeros':[]}

    print("Quantos números deseja gerar:")
    quantidade_num = int(input())

    print("A variação dos números é de 0 até:")
    variacao_num = int(input())

    for i in range(quantidade_num):
        numeros['numeros'].append(np.random.randint(0, variacao_num))

    numeros_df = pd.DataFrame(numeros)
    numeros_df.to_csv('dataset/input.csv', index=False)

    print("\nNúmeros gerados com sucesso e salvos em input.csv!")

    ## Colocando o cabeçalho no arquivo output.csv
    legenda = pd.DataFrame([["python", "js", "php", "c", "c++", "java"],
                                    ["","","","","",""], 
                                    ["","","","","",""],
                                    ["","","","","",""],
                                    ["","","","","",""]])
    legenda.to_csv(f'dataget/output/{quantidade_num}:{variacao_num}.csv', index=False, header=False)

    salve_tabela = pd.DataFrame({'n': [quantidade_num], 'j': [variacao_num]})
    print("Geraçdo com sucesso a tabela no arquivo output.csv!")

    salve_tabela = pd.DataFrame([["n_k"],
                                [quantidade_num],
                                [variacao_num]]).to_csv('dataset/valores.csv', index=False, header=False)

except Exception as e:
    print(f"Error: {e}")
