from base64 import b64decode

s = "dnNvc2h7U3VwZXJTZWNyZXRQYXNzd29yZH0="
print(b64decode(s).decode())