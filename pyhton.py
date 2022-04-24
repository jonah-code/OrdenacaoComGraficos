from email import contentmanager
import matplotlib.pyplot as plt
vetorTempo = []
vetorTamanho = []

def tranformar(conteudo,vetor):
    for numero in conteudo:
        (vetor.append(float(numero)))
    return vetorTempo

arquivo = open("C:\\Users\\jonas\\Desktop\\Tempo.txt","r")
arquivo2=  open("C:\\Users\\jonas\\Desktop\\Tamanho.txt","r")

conteudo = arquivo.read().split(" ");
conteudo2 = arquivo2.read().split(" ")

tranformar(conteudo,vetorTempo)

tranformar(conteudo2,vetorTamanho)

print(vetorTamanho)
print(vetorTempo)




plt.scatter(vetorTamanho,vetorTempo)
plt.show()

