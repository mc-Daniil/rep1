FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    socat \
    gcc \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY stack1.c .
RUN gcc -o stack1 stack1.c -fno-stack-protector -no-pie

ENV FLAG="flag{W0W_f1rst_overfl0w}"

RUN chown -R root:ctf /challenge && \
    chmod 750 /challenge/stack1

EXPOSE 1340

USER ctf

CMD ["socat", "TCP-LISTEN:1340,reuseaddr,fork", "EXEC:/challenge/stack1,stderr"]