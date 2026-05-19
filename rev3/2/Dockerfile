FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    socat \
    gcc \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY stack2.c .
RUN gcc -o stack2 stack2.c -fno-stack-protector -no-pie

ENV FLAG="flag{redacted}"

RUN chown -R root:ctf /challenge && \
    chmod 750 /challenge/stack2

EXPOSE 1341

USER ctf

CMD ["socat", "TCP-LISTEN:1341,reuseaddr,fork", "EXEC:/challenge/stack2,stderr"]