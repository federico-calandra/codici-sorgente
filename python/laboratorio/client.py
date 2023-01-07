import myLib as my
import numpy as np
import pickle


## CHIEDO PARAMETRI PER REGISTRAZIONE E CONNESSIONE
try:
	recTime = int(input("Inserisci tempo di acquisizione in secondi (default = 4): "))
except ValueError:
	recTime = 4

try:
	sampleRate = int(input("Inserisci frequenza di campionamento in Hz (default = 48000): "))
except ValueError:
	sampleRate = 48000

#serverAddress = input("Inserisci indirizzo IP del server: ")
#serverPort = int(input("Inserisci porta del server: "))
serverAddress = "127.0.0.1"
serverPort = 5555
print()


## ACQUISISCO AUDIO, LO RIPRODUCO E DISEGNO IL GRAFICO
audio = my.acquisisciAudio(recTime, sampleRate)
p_audio = pickle.dumps(audio)	# sequenza di byte che rappresenta l'audio
#print(type(audio),len(audio))
#print(audio)
print()

my.riproduciAudio(audio, sampleRate, 1)

x = np.arange(0, recTime, 1/sampleRate)
my.graficoXY(x, audio, 'Sampled audio waveform', 'time [s]', 'voltage [V]')


## RICHIEDO CONNESSIONE AL SERVER
conn = my.socketClient(serverAddress, serverPort)
#print(type(conn))

## TRASMETTO METADATI E ASPETTO CONFERMA DI RICEZIONE
print("Trasmetto metadati")
conn.sendall(pickle.dumps([recTime, sampleRate, len(p_audio)]))
print("Server says:", conn.recv(1024).decode())
print()


# TRASMETTO AUDIO
print("Trasmetto audio di dimensione", round(len(p_audio)/1024), 'kB')
conn.sendall(p_audio)
print()


## CHIUDO LA CONNESSIONE
conn.close()
print("Connessione chiusa")
