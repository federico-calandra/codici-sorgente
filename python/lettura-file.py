with open("input.txt") as f:
		line = f.readline().removesuffix("\n")
		while line!='':
			print(line)
			line = f.readline().removesuffix("\n")

with open("input.txt") as f:
	n = 0
	while f.readline() != "":
		n = n+1
	print(n)
