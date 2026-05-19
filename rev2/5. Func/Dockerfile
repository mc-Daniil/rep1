FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    socat \
    gcc \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY func.c .
RUN gcc -o func func.c -fno-stack-protector -no-pie -g

COPY flag.txt /challenge/flag.txt

RUN chown -R root:ctf /challenge && \
    chmod 750 /challenge/func && \
    chmod 440 /challenge/flag.txt

EXPOSE 1337

USER ctf

CMD ["socat", "TCP-LISTEN:1338,reuseaddr,fork", "EXEC:/challenge/func,stderr"]