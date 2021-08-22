from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import bb

app = QApplication([])
mainWindow = QWidget()
layout = QBoxLayout(0, mainWindow)

b1 = QPushButton('Vedi muscoli')
b2 = QPushButton('Vedi esercizi')
b3 = QPushButton('Crea sessione')
layout.addWidget(b1)
layout.addWidget(b2)
layout.addWidget(b3)
label = QLabel('prova')
layout.addWidget(label)

b1.clicked.connect(lambda:label.setText('Vedi muscoli'))
b2.clicked.connect(lambda:label.setText('Vedi esercizi'))
b3.clicked.connect(lambda:label.setText('Crea sessione'))
