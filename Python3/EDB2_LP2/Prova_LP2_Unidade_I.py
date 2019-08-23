
# coding: utf-8

# In[216]:


#importando bibliotecas
import csv
import itertools
import operator
from io import open
import collections


# In[217]:


#informacoes recebidas
total_cadeiras = 29
QE = 12684


# In[218]:


#lista para armazenamento dos dados recebidos
dados = []


# In[219]:


#funcao que calcula a distribuicao das vagas residuais
def calcula_media(colig, vagas_r, media):
    while (vagas_r > 0) :
        for cont in range(0 , len(colig)):
            media[cont] = colig[cont][0]/(colig[cont][1] + 1)
        colig[media.index(max(media))][1] += 1
        vagas_r -= 1


# In[220]:


#funcao que filtra e armazena apenas os candidatos eleitos atraves da eleicao proporcional
def filtra_candidato_lista(candi_dict, colig):
    final_list = []
    for k in candi_dict:
        for cont in range(0, colig[k][1]):
            temp = [ candi_dict[k][cont][0], candi_dict[k][cont][1], k, candi_dict[k][cont][2]]
            final_list.append(temp)
    return final_list


# In[221]:


#abrindo e armzazenando aquivo contendo os dados
with open('eleicao.csv', encoding='utf-8') as f:
    reader = csv.reader(f)
    for row in reader:
        dados.append(row)
        
        # Caso haja virgula no nome do candidato
        if len(row) > 1 :
            aux = ''
            for x in range(0, len(row)):
                aux += row[x]
            dados.pop()
            dados.append([aux])


# In[222]:


#removendo a primeira linha
dados.pop(0)


# In[223]:


#lista com 'NUMERO', 'NOME', 'COLIGACAO' e 'VOTOS' de cada candidato
result = [i[0].split(';') for i in dados]

#dicionario com a quantidade de votos das coligacoes
my_dict = collections.OrderedDict()

for i in range(0, len(result)):
    if result[i][2] not in my_dict:
        new_key = {result[i][2]: int(result[i][3]) }
        my_dict.update(new_key)
    else:
        my_dict[result[i][2]] = my_dict.get(result[i][2], 0) + int(result[i][3])


# In[224]:


#lista com quoeficiente partidario das coligacoes
q_part = [i//QE for i in list(my_dict.values())]

vagas_ = sum(list(q_part))
vagas_residuais = total_cadeiras - vagas_

#dicionario com a quantidade de vagas obtidas
vagas_por_colig = {**my_dict}   


# In[225]:


count = 0
valor = list(my_dict.values())

#associando quoeficiente partidario das coligacoes com a quantidade de vagas obtidas
for key in vagas_por_colig:
    vagas_por_colig[key] = [vagas_por_colig[key], q_part[count]]
    count += 1


# In[226]:


#coligacoes que receberam vagas atraves do preenchimento por quociente partidario
vagas_por_colig_nao_nulas = { k:v for k,v in vagas_por_colig.items() if v[1]!=0 }


# In[227]:


#distribuicao das vagas residuais
calcula_media(list(vagas_por_colig_nao_nulas.values()),vagas_residuais, [1]*len(vagas_por_colig_nao_nulas))


# In[228]:


eleitos = { k:[] for k in vagas_por_colig_nao_nulas.keys()}

for k in result:
    if k[2] in eleitos:
        temp = [int(k[3]), k[1], k[0]]
        eleitos[k[2]].append(temp)

#ordenando os cadidatos do mais votado para o menos votado
for k in eleitos:
    eleitos[k].sort(reverse=True)  


# In[229]:


eleicao_proporcional = filtra_candidato_lista(eleitos, vagas_por_colig_nao_nulas)
eleicao_proporcional.sort(reverse=True)


# In[230]:


with open('eleicao.tsv', 'w', encoding='utf-8') as out:
    for var in eleicao_proporcional:
        out.write(var[3]+"\t"+var[1]+"\t"+var[2]+"\t"+str(var[0]) + '\n')

