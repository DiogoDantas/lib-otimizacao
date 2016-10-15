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
PATH = ["inputs/in_triangulo_pascal/", "inputs/in_troco_moedas/", "inputs/in_soma_subconjunto/", "inputs/in_mochila_binaria/"]

def gerar():
	index = 0
	opcoes = {0: input_triangulo_pascal,
			  1: input_troco_moedas,
			  2: input_soma_subconjuntos,
			  3: input_mochila_binaria}
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
			if n > k: break
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

def input_soma_subconjuntos(a):
	#gerando casos
	for _ in range(TESTE):
		set_num_elements = random.randint(1,10)
		a.write(str(set_num_elements) + "\n")
		#valores aleatórios de 1 a 100
		elements = random.sample(range(1, 1000), set_num_elements)

		for x in elements:
			a.write(str(x) + " ")

		a.write("\n" + str(random.randint(1,1000)) + "\n")

def input_mochila_binaria(a):
	#gerando casos
	for _ in range(TESTE):
		num_elements = random.randint(1,10)
		a.write(str(num_elements) + "\n")
		W = random.randint(1,100)
		a.write(str(W) + "\n")
		weights = random.sample(range(1,100), num_elements)
		values = random.sample(range(1,1000), num_elements)

		for x in weights:
			a.write(str(x) + " ")

		a.write("\n")

		for x in values:
			a.write(str(x) + " ")

		a.write("\n")

# call
gerar()