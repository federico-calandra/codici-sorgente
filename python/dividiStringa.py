#!/usr/bin/env python3
import re

objSource = open('mp.txt','r')
objOutput = open('out.txt','w+')

vecRighe = objSource.readlines()

strOutput = re.split(r'/(http)',vecRighe[0])

objOutput.write(strOutput[0])
objOutput.close()
objSource.close()
