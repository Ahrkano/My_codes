#teste de execução
#C:\Users\Alexandre\Anaconda3\python.exe C:\Users\Alexandre\pol.py -hash -hmac minha_chave -i -x -t -dir C:\Users\.......

import os
import shutil
import hashlib
import ctypes
import argparse

# Realiza HMAC no arquivo e retorna o resultado
def filehash_hmac(filepath, secretKey):
    sha256 = hashlib.sha256()
    with open(filepath, 'rb') as fp:
        while True:
            data = fp.read()
            if not data:
                break
            sha256.update(data + secretKey)
    return sha256.digest()

# Realiza HASH no arquivo e retorna o resultado
def filehash(filepath):
    md5 =  hashlib.md5()
    with open(filepath, 'rb') as fp:
        while True:
            data = fp.read()
            if not data:
                break
            md5.update(data)
    return md5.hexdigest()

# Realiza HMAC no diretorio e em todos os subdiretorios salvado o resultado em arquivo '.txt'
def hashdir_hmac(path, output_file, key):
    table = []
    for root, dirs, files in os.walk(path):
        for fpath in [os.path.join(root, f) for f in files]:
            sha256 = filehash_hmac(fpath, key)
            name = os.path.relpath(fpath, path)
            table.append(str(fpath)+' '+str(sha256)+'\n')

    write_file(table, output_file)

# Realiza HASH no diretorio e em todos os subdiretorios salvado o resultado em arquivo '.txt'
def hashdir(path, output_file):
    table = []
    for root, dirs, files in os.walk(path):
        for fpath in [os.path.join(root, f) for f in files]:
            md5 = filehash(fpath)
            name = os.path.relpath(fpath, path)
            table.append(str(fpath)+' '+str(md5)+'\n')

    write_file(table, output_file)

# Cria pasta oculta para armazenar os logs do programa
def makerepo(path):
    if not os.path.exists(path):
        os.makedirs(path)
        FILE_ATTRIBUTE_HIDDEN = 0x02
        ret = ctypes.windll.kernel32.SetFileAttributesW(path, FILE_ATTRIBUTE_HIDDEN)

# Escreve dados em arquivo '.txt'
def write_file(L, output_file):
    file = open(output_file, 'w')
    file = file.writelines(L)

# Escreve os resultados do programa em arquivo '.txt' ou exibe na tela
def compare(first_log, last_log, output, value):

    _add = information(first_log, last_log, 0)
    _del = information(first_log, last_log, 1)
    
    alt1 = []
    alt2 = []
    box1 = []
    box2 = []
    altered = set()
    
    for i in range (0, len(_add)):
        alt1.append(list(_add)[i].split(' ')[0:-1])
        
    for i in range (0, len(_del)):
        alt2.append(list(_del)[i].split(' ')[0:-1])
        
    for i in alt1:
        box1.append(''.join(i))
    for i in alt2:
        box2.append(''.join(i))
    
    altered = set(box1).intersection(set(box2))
    added = set(box1).difference(set(box2))
    deleted = set(box2).difference(set(box1))
  
    if value :
        with open( output, 'a') as file_out:
            file_out.write("Os seguintes arquivos foram alterados\n")
            for line in altered:
                file_out.write(line+'\n')
                
        with open( output, 'a') as file_out:
            file_out.write("Os seguintes arquivos foram adicionados\n")
            for line in added:
                file_out.write(line+'\n')
                
        with open( output, 'a') as file_out:
            file_out.write("Os seguintes arquivos foram removidos\n")
            for line in deleted:
                file_out.write(line+'\n')  

    else:
        print("arquivos alterados:\n")
        for line in altered:
            print(line+'\n')
        print("arquivos adicionados:\n")
        for line in added:
            print(line+'\n')
        print("arquivos removidos:\n")
        for line in deleted:
            print(line+'\n')
    
# Compara dois arquivo e retorna a diferenca
def information(first_log, last_log, flag):
    with open(first_log, 'r') as file1:
        with open(last_log, 'r') as file2:
            if flag:
                difference= set(file1).difference(file2)
            else:
                difference= set(file2).difference(file1)
    difference.discard('\n')
    return difference

def main():

    #Parametros para execução em linha de comando

    parser = argparse.ArgumentParser(description = 'GUARD - Programa de monitoramento de arquivos')

    parser.add_argument('-hash', action='store_true', help="Metodo de hash padrao")
    
    parser.add_argument('-hmac', type=str, nargs='?', const='secret_shared_key', default=None, metavar='HMAC', help="Metodo de hash com senha")
    
    parser.add_argument('-i', action='store_true', help="Inicializa os arquivos")
    
    parser.add_argument('-t', action='store_true', help="Rastreia os arquivos da pasta")
    
    parser.add_argument('-x', action='store_true', help="Remove os arquivos de log e libera a pasta")
    
    parser.add_argument('-dir', type=str, nargs='?', default='C:\\Users', metavar='DIR', help="Diretorio a ser monitorado")
    
    parser.add_argument('-o', type=str, nargs='?', const='log.txt', default=None, metavar='OUT', help="Arquivo de saida")
    
    arguments = parser.parse_args()
    
    # Se o diretorio existir
    # cria o caminho dos arquivos de log
    if arguments.dir :
        if os.path.exists(arguments.dir) :
            path = arguments.dir
            first_log = path+'\\.guard\\init.txt'
            last_log = path+'\\.guard\\tracked.txt'
    
    # Cria uma pasta oculta, realiza o hash e salva em arquivo
    if arguments.i :
        makerepo(path+'\\.guard')
        # hash padrao ou hmac
        if arguments.hash :
            hashdir(path, first_log)
        if arguments.hmac :
            hashdir_hmac(path, first_log, arguments.hmac)
    
    # Refaz o hash e salva em arquivo
    if arguments.t :
        hashdir(path, last_log)
        # compara os logs e salve em arquivo ou imprime na tela
        if arguments.o:
            compare(first_log, last_log, arguments.o, True)
        else:
            compare(first_log, last_log, '', False)
    
    # Remove os arquivos de log e a pasta oculta
    if arguments.x :
        shutil.rmtree(path+'\\.guard', ignore_errors=True)
    
if __name__ == "__main__":
    main()    
    

