FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -d /home/ctf -m -s /bin/bash ctf

WORKDIR /home/ctf

COPY simple_rop .
COPY flag.txt .

RUN chown -R root:root /home/ctf && \
    chmod 755 /home/ctf && \
    chmod 755 simple_rop && \
    chmod 444 flag.txt

USER ctf

EXPOSE 1344

CMD ["socat", "TCP-LISTEN:1344,reuseaddr,fork", "EXEC:./simple_rop,stderr"]