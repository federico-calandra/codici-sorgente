form = {'campo1': 0, 'campo2': 0, 'campo3': 0}
default= {'campo1': 1, 'campo2': 1, 'campo3': 1}
messaggi = {'campo1': 'Inserisci campo 1: ', 'campo2': 'Inserisci campo 2: ', 'campo3': 'Inserisci campo 3: '}

for i in ['campo1', 'campo2', 'campo3']:
	while form[i] <= 0: # in questo esempio accetto solo valori strettamente positivi
		try:
			p[i] = input(messaggi[i])
		except ValueError:
			p[i] = default[i]
