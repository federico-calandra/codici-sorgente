import myLib as my
import numpy as np
import pickle


## CREO SOCKET, ASPETTO RICHIESTE DI CONNESSIONE, ACCETTO LA PRIMA E STAMPO INDIRIZZO CLIENT
port = 5555
conn = my.socketServer(port)
print()


## RICEVO METADATI
meta = pickle.loads(conn.recv(1024))
recTime = meta[0]
sampleRate = meta[1]
lp_audio = meta[2]
conn.sendall('Ricevuto!'.encode())
print("Metadati ricevuti")
print()


## RICEVO FLUSSO E RICOSTRUISCO AUDIO
# il client invia, spetta al server ricevere correttamente, quindi su c.py non c'è metodo 1 o 2
## metodo 1: ricevo 1 blocco di lp_audio byte, non funziona perché p_audio ricevuto è 65536 byte
#dim = 0
#p_audio = conn.recv(int(lp_audio))
#print(int(lp_audio))
#print(type(p_audio),len(p_audio))

# metodo 2: ricevo tanti chunks da 4096 byte e li concateno su unica stringa
dim = 0
p_audio = b''

while True:
	chunk = conn.recv(4096)	# ricevo 4096 byte
	#print(type(chunk), len(chunk), dim)
	if not chunk: break
	dim += len(chunk)	# incremento dimensione dati ricevuti
	p_audio += chunk

if dim == lp_audio:
	print('Audio ricevuto correttamente')
	audio = pickle.loads(p_audio)
	#print(type(audio),len(audio))
	#print(audio)
	print()

	## RIPRODUCO AUDIO RICEVUTO E DISEGNO GRAFICO
	my.riproduciAudio(audio, sampleRate, 2)

	x = np.arange(0, recTime, 1/sampleRate)
	my.graficoXY(x, audio, 'Received audio waveform', 'time [s]', 'voltage [V]')
else:
	print("Errore di trasmissione")


# CHIUDO CONNESSIONE
conn.close()
print("Connessione chiusa")
