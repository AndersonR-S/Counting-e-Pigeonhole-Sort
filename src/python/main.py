import ordenacao as orde
import pandas as pd

try: 
    input = pd.read_csv('dataset/input.csv')['numeros'].tolist()
    tempos = orde.ordenar(input) #desordenado

    tempos.extend(orde.ordenar(sorted(input)))#ordenado

    output = pd.read_csv('dataget/output.csv')
    output['python'] = tempos
    print(output)
    output.to_csv('dataget/output.csv',index= False)

except Exception as e:
    print(f"Error: {e}")
    exit()
    









