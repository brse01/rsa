import hashlib
import sys

arquivo = open('hash.txt', 'r')
primeira_linha = arquivo.readline()
arquivo.close()
hash_object = hashlib.sha224(primeira_linha.encode('utf-8'))
hex_dig = hash_object.hexdigest()
transforma = int(hex_dig, 16)
arq = open("hash.txt","w");
arq.write('%d' % transforma)
arq.close()
