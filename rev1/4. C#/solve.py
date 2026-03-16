s = "Xpx_ju_JT_epuOFU"

print("vsosh{", end="")

for i in s:
    if i == "_":
        print("_", end="")
    else:
        print(chr(ord(i) - 1), end="")
        
print("}")