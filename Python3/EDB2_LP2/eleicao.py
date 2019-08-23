import csv
from io import open

total_cadeiras = 29
QE = 12684

class politico:
    def __init__(self,num, nom, par_col, vot):
        self.numero = num
        self.nome = nom
	self.part_colig = par_col
	self.votos = vot

def quociente_partidario(valor):
	for i in valor:
		print valor.num
	



with open('eleicao.csv') as csvfile:
    readCSV = csv.reader(csvfile, delimiter=';')
    dados = []
    for row in readCSV:
        print row
	f.close()


		
		



f = open('workfile.tsv', 'w')
for i in dados:
	f.write(i)
	
