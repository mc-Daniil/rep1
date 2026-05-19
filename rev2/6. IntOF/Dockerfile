FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    socat \
    gcc \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY int.c .
RUN gcc -o int int.c -no-pie -g -fwrapv

COPY flag.txt /challenge/flag.txt

RUN chown -R root:ctf /challenge && \
    chmod 750 /challenge/int && \
    chmod 440 /challenge/flag.txt

EXPOSE 1339

USER ctf

CMD ["socat", "TCP-LISTEN:1339,reuseaddr,fork", "EXEC:/challenge/int,stderr"]