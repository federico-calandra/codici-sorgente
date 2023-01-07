import soundcard as sc
import numpy as np
import matplotlib.pyplot as plt
import socket

## Per nessuna funzione sono stati implementati controlli sulla validità degli input

def acquisisciAudio(recTime, sampleRate=48000):
	mic = sc.default_microphone()
	print("Inizio acquisizione")
	data = mic.record(recTime*sampleRate, sampleRate)
	print('Acquisizione completata')
	# print(data)
	return data


def graficoXY(x,y, titolo='', asseX='', asseY=''):
	plt.title(titolo)
	plt.xlabel(asseX)
	plt.ylabel(asseY)
	plt.plot(x, y)
	plt.show()


def riproduciAudio(data, sampleRate=48000, speed=1):
	spk = sc.default_speaker()
	spk.play(data/np.max(data), speed * sampleRate)
	# data/np.max(data) dovrebbe normalizzare l'array in modo che ongi valore sta in [0,1]
	# con speed controllo la velocità di riproduzione


def socketClient(host, port):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((host, port))
	print("Connesso a", host, "alla porta", port)
	return s


def socketServer(port):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind(('',port))
	print('Socket creato')
	s.listen(1)
	print('Server in ascolto su porta', port)
	conn, addr = s.accept()
	print('Client connesso', addr[0])
	return conn
