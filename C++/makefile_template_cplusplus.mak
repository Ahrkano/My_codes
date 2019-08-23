# compilador utilizado
COMP=g++

# opcoes de compilacao (modifique/acrescente)
OPCOES_COMP=-c -Wall -std=C99 -lm

# opcoes de ligacao (modifique/acrescente)
OPCOES_LINK= 

# arquivos-fonte (modifique/acrescente)
FONTES=main.cpp arq1.cpp arq2.cpp

# a macro a seguir informa que os arquivos-objeto sao
# obtidos a partir dos arquivos-fonte, substituindo
# a extensao .c pela extensao .o
OBJETOS=$(FONTES: .c=.o)

# nome do arquivo executavel (modifique)
EXECUTAVEL=MeuProg

$(EXECUTAVEL): $(OBJETOS)
		$(COMP) $(OPCOES_LINK) $(OBJETOS) -o $@

arq1.o: arq1.cpp arq1.h
		$(COMP) $(OPCOES_COMP) arq1.cpp -o arq1.o

arq1.o: arq2.cpp arq2.h
		$(COMP) $(OPCOES_COMP) arq2.cpp -o arq2.o

limpa:
		-rm -f *.o core

reconstroi: limpa MeuProg 