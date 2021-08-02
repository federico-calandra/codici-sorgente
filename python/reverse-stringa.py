p = "was it a car or a cat I saw"
r = ""

i=0
for char in p_phrase:
    r_phrase += p_phrase[len(p_phrase)-1-i]
    i += 1
print(r)