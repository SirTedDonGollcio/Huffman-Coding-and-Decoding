import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('histogram.csv',delimiter=';')
fig, ax = plt.subplots()
ax.bar(df['Symbol'], df['Frequency'],  ec="k", align="edge")

ax.set_title('Histogram wejścia ciągu znaków: obraz uniform.pgm')

ax.set_xlim([0, 255])
ax.set_xlabel("Symbol")#Symbol #Wartość janości piksela
ax.set_ylabel("Ilość występowania")