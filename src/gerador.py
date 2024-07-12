# Código que gera os números para a arquivo de input_a.csv da pasta dataset

import pandas as pd
import numpy as np

a = {'numeros':[]}

num =1000
for i in range(num):
    a['numeros'].append(np.random.randint(0, num))


a = pd.DataFrame(a)
a.to_csv('dataset/input_a.csv', index = False)

print(a)