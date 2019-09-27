#%%
import os
import hashlib
import ctypes

def compare():
    first_log = path+'\\.guard\\init.txt'
    last_log = path+'\\.guard\\tracked.txt'


    with open(first_log, 'r') as file1:
        with open(last_log, 'r') as file2:
            difference = set(file1).difference(file2)
    difference.discard('\n')

    with open( path+'\\.guard\\log.txt', 'w') as file_out:
        for line in difference:
            file_out.write(line)

def write_file(L):
    file = open(path+'\\.guard\\init.txt', 'w')
    file = file.writelines(L)

def makerepo(path):
    if not os.path.exists(path):
        os.makedirs(path)
        FILE_ATTRIBUTE_HIDDEN = 0x02
        ret = ctypes.windll.kernel32.SetFileAttributesW(path, FILE_ATTRIBUTE_HIDDEN)

def filehash(filepath):
    #blocksize = 64*1024
    md5 =  hashlib.md5()
    with open(filepath, 'rb') as fp:
        while True:
            #data = fp.read(blocksize)
            data = fp.read()
            if not data:
                break
            md5.update(data)
    return md5.hexdigest()

def hashdir(path):
    table = []
    for root, dirs, files in os.walk(path):
        for fpath in [os.path.join(root, f) for f in files]:
        #size = os.path.getsize(fpath)
            md5 = filehash(fpath)
            name = os.path.relpath(fpath, path)
                #print((size, md5, name))
            #print(md5, name)
            table.append(str(fpath)+' '+str(md5)+'\n')

    write_file(table)
    #return table
                
def handle_entry(*args):
    for arg in args: 
        if arg == "go":
            hashdir('C:\\Users\\Alexandre\\Yu-Gi-Meme Collection')
        else:
            pass

path = 'C:\\Users\\Alexandre\\Yu-Gi-Meme Collection'
makerepo(path+'\\.guard')
hashdir(path)
compare()

   

#%%

#%%
