with open("input.txt") as f:
		line = f.readline().removesuffix("\n")
		while line!='':
			print(line)
			line = f.readline().removesuffix("\n")
