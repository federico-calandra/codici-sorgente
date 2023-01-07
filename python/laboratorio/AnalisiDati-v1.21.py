# Coded by Federico Calandra in December 2022

import math
import matplotlib.pyplot as plt
import numpy as np
import os
#import pandas as pd


def graficoX(x, titolo='', asseX='', asseY='x'):
	i = np.arange(1, len(x)+1)
	plt.title(titolo)
	plt.xlabel(asseX)
	plt.ylabel(asseY)
	plt.plot(i, x, "ko")
	plt.show(block=False)
	plt.pause(0.001)

def graficoXY(x, y, titolo='', asseX='x', asseY='y'):
	plt.title(titolo)
	plt.xlabel(asseX)
	plt.ylabel(asseY)
	plt.plot(x, y, "ko")
	plt.show(block=False)
	plt.pause(0.001)

def graficoXYY(x, y1, y2, titolo='', asseX='x', asseY='y₁, y₂'):
	plt.title(titolo)
	plt.xlabel(asseX)
	plt.ylabel(asseY)
	plt.plot(x, y1, "ko", x, y2, "r-")
	plt.show(block=False)
	plt.pause(0.001)

# def grafico(x, y1=None, y2=None, titolo='', asseX='', asseY=''):
# 	plt.title(titolo)
# 	if y1==None and y2==None:	# graficoX
# 		plt.xlabel(asseX)
# 		plt.ylabel(asseY)
# 		i = np.arange(1, len(x)+1)
# 		plt.plot(i, x, "ko")
# 	if y1!=None and y2==None:	# graficoXY
# 		plt.xlabel(asseX)
# 		plt.ylabel(asseY)
# 		plt.plot(x, y, "ko")
# 	if y1!=None and y2!=None:	# graficoXYY
# 		plt.xlabel(asseX)
# 		plt.ylabel(asseY)
# 		plt.plot(x, y1, "ko", x, y2, "r-")
# 	plt.show(block=False)
# 	plt.pause(0.001)

def sigma_p(x) -> float:
	s = np.sqrt(np.sum(np.square(x-np.mean(x)))/len(x))
	return s

def sigma_c(x):
	s = np.sqrt(np.sum(np.square(x-np.mean(x)))/(len(x)-1))
	return s

def sigma_avg(x):
	s1 = sigma_p(x)/np.sqrt(len(x))
	s2 = sigma_c(x)/np.sqrt(len(x))
	return [s1, s2]

def covar_p(x, y):
	c = np.sum(np.multiply(x-np.mean(x), y-np.mean(y)))/len(x)
	return c

def covar_c(x,y):
	c = np.sum(np.multiply(x-np.mean(x), y-np.mean(y)))/(len(x)-1)
	return c

def analisiStat(x):
	print()
	print("***** ANALISI STATISTICA *****")
	print("Serie di dati")
	print(x)
	print("N_dati = ", len(x))
	print()

	print("Media = ", np.mean(x))
	print("σ_pop = ", sigma_p(x))
	print("σ_camp = ", sigma_c(x))
	print("SDOM = ", sigma_avg(x))
	print("σ_σ", math.sqrt(1/(2*(len(x)-1))))
	print("*******************************")

	# graficoX(x)

	return [x, len(x), np.mean(x), sigma_p(x), sigma_c(x), sigma_avg(x)]

def regLineare(x,y, sigma_dati=None):
# Calcolo degli indici statistici
	Sx = np.sum(x)
	Sy = np.sum(y)
	Sxy = np.sum(np.multiply(x,y))
	Sx2 = np.sum(np.square(x))
	Sy2 = np.sum(np.square(y))
	delta = len(x) * Sx2 - np.square(Sx)

	Q = (Sx2 * Sy - Sx * Sxy) / delta
	M = (len(x) * Sxy - Sx * Sy) /delta

	if sigma_dati != None:
		sigma_y = [np.sqrt(np.sum(np.square(y-Q-(M*x)))/(len(x)-2)), sigma_dati]
		sigma_Q = [sigma_y[0] * np.sqrt(Sx2/delta), sigma_y[1] * np.sqrt(Sx2/delta)]
		sigma_M = [sigma_y[0] * np.sqrt(len(x)/delta), sigma_y[1] * np.sqrt(len(x)/delta)]
	else:
		sigma_y = [np.sqrt(np.sum(np.square(y-Q-(M*x)))/(len(x)-2)), 0]
		sigma_Q = [sigma_y[1] * np.sqrt(Sx2/delta), 0]
		sigma_M = [sigma_y[1] * np.sqrt(len(x)/delta), 0]

	r = np.divide(covar_p(x,y),sigma_p(x)*sigma_p(y))

# Calcolo dei valori attesi secondo la regressione stimata
	y_exp = np.multiply(M,x) + Q

# Stampa risultati
	print()
	print("***** REGRESSIONE LINEARE *****")
	print("Serie di dati")
	print(x)
	print(y)
	print("N_dati = ", len(x))
	print()

	print("Σx = ", Sx)
	print("Σy = ", Sy)
	print("Σxy = ", Sxy)
	print("Σx² = ", Sx2)
	print("Σy² = ", Sy2)
	print("Δ = ", delta)
	print()

	print("Q = ", Q)
	print("M = ", M)
	print()

	print("σ_y = ", sigma_y[0])
	print("σ_Q = ", sigma_Q[0])
	print("σ_M = ", sigma_M[0])
	print()

	if sigma_y[1] != 0:
		print("σ_dati = ", sigma_y[1])
		print("|σ_y - σ_dati| = ", np.abs(sigma_y[0] - sigma_y[1]))
		print("σ_Q = ", sigma_Q[1])
		print("σ_M = ", sigma_M[1])
		print()

	print("σ_xy = ", covar_p(x,y))
	print("r = ", r)
	print("*******************************")

	graficoXYY(x,y,y_exp)

	return [Q, M, [sigma_y[0], sigma_Q[0], sigma_M[0]], [sigma_y[1], sigma_Q[1], sigma_M[1]], y_exp]

def clear_variables():
	try: del(scelta, l, n_imp, imp, line, lungh)
	except NameError: pass

def init():
	clear_variables()
	print()
	print("Scegliere modalità: ")
	print("1  input da file CSV")
	print("2  input da tastiera")
	print("3  input da codice")
	print("4  input da generatore random")
	print("0  passa a modalità interattiva")
	print()


while __name__ == "__main__":
	init()
	scelta = input("Scelta ([Enter] per chiudere): ")
	if scelta == "0":
		print()
		print("Modalità interattiva")
		import code
		code.interact(local=locals())

	elif scelta != "0":
		match scelta:
			# case "1":
			# 	# nome file deve essere 'dati.csv'
			# 	with open("dati.csv") as f:	# andrebbe generalizzata la lettura a n linee
			# 		l = f.readline().removesuffix("\n")
			# 		x = l.split(";")
			# 		l = f.readline().removesuffix("\n")
			# 		if l != "":
			# 			y = l.split(";")
			case "1":
				with open("dati.csv") as f:
					# controllo se tutte le linee hanno lo stesso numero di dati
					lungh = 0
					for l in f:
						line=np.float_(l.splitlines()[0].split(";"))
						if lungh == 0:	# prima linea letta
							lungh = len(line)
							dati = np.float_([line])
						else:
							if len(line) != lungh:
								exit("i dati devono avere stessa lunghezza")
							dati = np.append(dati, [line], 0)
				print("Dati importati: ")
				print(dati)

			case "2":
				n_inp = int(input("Inserire num. di serie dati: "))

				x = []
				inp = input("\nInserire valori di x ([Enter] per terminare sequenza):\n")
				while inp != '':
					x.append(inp)
					inp = input()

				if n_inp != 1:
					y = []
					inp = input("\nInserire valori di y ([Enter] per terminare sequenza):\n")
					while inp != '':
						y.append(inp)
						inp = input()

					if len(x) != len(y):	# controllo validità input e trasformo in float
						quit("x e y devono avere stessa dimensione")

			case "3":
				x = np.multiply(9.81,[0.1,0.2,0.3,0.5,0.7])
				y = [0.009,0.018,0.029,0.049,0.07]
				if len(x) != len(y): y = x


			case "4":
				N = int(input("Lunghezza serie dati: "))
				x = np.random.rand(N,)
				y = np.random.rand(N,)
			case _:
				quit()

		# try:
		# 	x = np.float_(x)
		# 	y = np.float_(y)
		# 	N = len(x)
		# except NameError: pass

		try: clear_variables()
		except NameError: pass

		## ANALISI DATI
		# try:
		# 	stat_x = analisiStat(x)
		# 	stat_y = analisiStat(y)
		# 	reg = regLineare(x,y)
		# except NameError: pass
		try:
			stat = []
			for d in dati:
				stat.append(analisiStat(d))
			# reg = regLineare(x,y)
		except NameError: pass

		medie = []
		sdom = []
		for s in stat:
			medie.append(s[2])
			sdom.append(s[5][1])
		print(medie)
		print(sdom)


	### COMANDI NUMPY
	## CREAZIONE
	# np.ndarray(shape, dtype=float)
	# np.array([1, 2, 3])
	# np.array([[1,2], [3,4], [5,6]])
	# np.arange([start=0, ]stop, [step, ]dtype=None)
	# np.linspace(start, stop, num=50)
	# np.eye(n, m)
	# np.diag([1,2,3])
	# np.zeros(shape, dtype=float)
	# np.ones(shape, dtype=None)
	# np.full(shape, fill_value, dtype=None)
	# np.random.rand

	## MANIPOLAZIONE
	# np.append(arr, values)
	# np.append([[1,2,3]], [[4,5,6]], axis=0)

	## OPERAZIONI
	# np.sum(v)
	# np.prod(v)
	# np.add(v,w)
	# np.subtract(v,w)
	# np.multiply(v,w)
	# np.divide(v,w)
	# np.square(v)
	# np.power(v,esp)
