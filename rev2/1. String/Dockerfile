FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat gcc && rm -rf /var/lib/apt/lists/*

RUN useradd -M ctf
WORKDIR /challenge

COPY string.c .
RUN gcc -o string string.c -fno-stack-protector -no-pie -g

COPY flag.txt /challenge/flag.txt
RUN chown root:ctf /challenge/string /challenge/flag.txt && chmod 750 /challenge/string && chmod 440 /challenge/flag.txt

EXPOSE 1337
CMD ["socat", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/challenge/string,su-d=ctf"]