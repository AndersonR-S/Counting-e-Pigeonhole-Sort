import ordenacao as orde
import pandas as pd

try: 
    input = pd.read_csv('dataset/input.csv')['numeros'].tolist()
    #desordenado
    tempos = orde.tempo(input) 

    #ordenado
    tempos.extend(orde.tempo(sorted(input)))

    valores = pd.read_csv('dataset/valores.csv')
    name_output = f"dataget/output/{valores['n_k'][0]}:{valores['n_k'][1]}.csv"
    output = pd.read_csv(name_output)

    output['python'] = tempos
    output.to_csv(name_output,index= False)

except Exception as e:
    print(f"Error: {e}")
    exit()
    









