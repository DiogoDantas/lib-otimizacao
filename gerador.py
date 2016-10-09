#!/usr/bin/env python3
#--
# Author: Diogo Dantas, Higor Anjos, Marcos Alves
#++
#
import random
# quantidade de entrada
ENTRADA = 5
# quantidade de casos para cada algoritmo
TESTE = 30
# caminhos referente a entrada
PATH = ["inputs/in_triangulo_pascal/", "inputs/in_troco_moedas/"]

def gerar():
	index = 0
	opcoes = {0: input_triangulo_pascal,
			  1: input_troco_moedas}
	for p in PATH:
		for i in range(ENTRADA):
			arquivo = open(p + "00" + str(i+1) + ".in", 'w')
			arquivo.write(str(TESTE)+"\n")	
			opcoes[index](arquivo)
		index+=1
		arquivo.close()

# metodos para gerar inputs
def input_triangulo_pascal(a):
	# gerando casos
	for _ in range(TESTE):
		while True:
			n = random.randint(1, 15)
			k = random.randint(1, 15)
			if n > k: break;
		a.write(str(n) + " " + str(k) + "\n")

def input_troco_moedas(a):
	# gerando casos
	for _ in range(TESTE):
		len_trocos = random.randint(3, 10)
		a.write(str(len_trocos)+"\n")
		# valores aleatórios 1 a 30
		valores = random.sample(range(1, 30), len_trocos)
		valores.sort()
		for v in valores: a.write(str(v)+" ")
		a.write("\n"+str(random.randint(15, 100))+"\n")
# call
gerar()