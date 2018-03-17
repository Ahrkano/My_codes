# compilador utilizado
COMP=gcc

# opcoes de compilacao (modifique/acrescente)
OPCOES_COMP=-c -Wall -std=C99 -lm

# opcoes de ligacao (modifique/acrescente)
OPCOES_LINK= 

# arquivos-fonte (modifique/acrescente)
FONTES=main.c arq1.c arq2.compilacao

# a macro a seguir informa que os arquivos-objeto sao
# obtidos a partir dos arquivos-fonte, substituindo
# a extensao .c pela extensao .o
OBJETOS=$(FONTES: .c=.o)

# nome do arquivo executavel (modifique)
EXECUTAVEL=MeuProg

$(EXECUTAVEL): $(OBJETOS)
		$(COMP) $(OPCOES_LINK) $(OBJETOS) -o $@

arq1.o: arq1.c arq1.h
		$(COMP) $(OPCOES_COMP) arq1.c -o arq1.o

arq1.o: arq2.c arq2.h
		$(COMP) $(OPCOES_COMP) arq2.c -o arq2.o

limpa:
		-rm -f *.o core

reconstroi: limpa MeuProg		