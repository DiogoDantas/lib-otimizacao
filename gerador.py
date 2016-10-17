#!/usr/bin/env python3
#--
# Author: Diogo Dantas, Higor Anjos, Marcos Alves
#++
#
import random
import string
# quantidade de entrada
INPUT = 5
# quantidade de casos para cada algoritmo
TEST = 30
# caminhos referente a entrada
PATH = ["inputs/in_binomial_coefficient/", "inputs/in_coin_change/",
        "inputs/in_subset_sum/", "inputs/in_knapsack/", "inputs/in_activity_selection/",
        "inputs/in_huffman/", "inputs/in_box_stacking/"]

def generate():
	index = 0
	option = {0: input_binomial_coefficient,
			  1: input_coin_change,
			  2: input_subset_sum,
			  3: input_knapsack,
			  4: input_activity_selection,
			  5: input_huffman,
			  6: input_box_stacking}
	for p in PATH:
		for i in range(INPUT):
			file = open(p + "00" + str(i+1) + ".in", 'w')
			file.write(str(TEST)+"\n")	
			option[index](file)
		index+=1
		file.close()

# @alvesmarcos
def input_binomial_coefficient(f):
	# gerando casos
	for _ in range(TEST):
		while True:
			n = random.randint(1, 10)
			k = random.randint(1, 10)
			if n > k: break
		f.write(str(n) + " " + str(k) + "\n")

# @alvesmarcos
def input_coin_change(f):
	# gerando casos
	for _ in range(TEST):
		len_change = random.randint(3, 10)
		f.write(str(len_change)+"\n")
		# valores aleatórios 1 a 30
		values = random.sample(range(1, 30), len_change)
		values.sort()
		for v in values: f.write(str(v)+" ")
		f.write("\n"+str(random.randint(15, 100))+"\n")

# @alvesmarcos
def input_activity_selection(f):
	# gerando casos
	for _ in range(TEST):
		len_activity = random.randint(5, 15)
		f.write(str(len_activity)+"\n")	
		start = random.sample(range(1, 30), len_activity)
		start.sort()
		list_end = []
		# lista com tempos inicias
		for s in start:
			while True: 
				end = random.randint(1, 30)
				if end > s: break
			f.write(str(s)+" ")
			list_end.append(end) 
		f.write("\n")
		for e in list_end: f.write(str(e)+" ")
		f.write("\n")

# @alvesmarcos
def input_huffman(f):
	# gerando casos
	for _ in range(TEST):
		len_letters = random.randint(5, 30)
		f.write(str(len_letters)+"\n")	
		characters = []
		ch = random.choice(string.ascii_letters)
		characters.append(ch)
		f.write(ch)
		for _ in range(len_letters-1):
			while True:
				ch = random.choice(string.ascii_letters)
				if not ch in characters: break
			f.write(ch)
		freq = random.sample(range(1, 150), len_letters)
		f.write("\n")
		for q in freq: f.write(str(q)+" ")
		f.write("\n")

# @alvesmarcos
def input_box_stacking(f):
	# gerando casos
	for _ in range(TEST):
		len_box = random.randint(3, 10)
		f.write(str(len_box)+"\n")	
		for _ in range(len_box):
			box = random.sample(range(1, 30), 3)
			for b in box:
				f.write(str(b)+" ")
			f.write("\n")

# @DiogoDantas
def input_subset_sum(f):
	#gerando casos
	for _ in range(TEST):
		set_num_elements = random.randint(1,10)
		f.write(str(set_num_elements) + "\n")
		#valores aleatórios de 1 a 100
		elements = random.sample(range(1, 1000), set_num_elements)

		for x in elements:
			f.write(str(x) + " ")

		f.write("\n" + str(random.randint(1,1000)) + "\n")

# @DiogoDantas
def input_knapsack(f):
	#gerando casos
	for _ in range(TEST):
		num_elements = random.randint(1,10)
		f.write(str(num_elements) + "\n")
		W = random.randint(1,100)
		f.write(str(W) + "\n")
		weights = random.sample(range(1,100), num_elements)
		values = random.sample(range(1,1000), num_elements)

		for x in weights:
			f.write(str(x) + " ")

		f.write("\n")

		for x in values:
			f.write(str(x) + " ")

		f.write("\n")

# call
generate()