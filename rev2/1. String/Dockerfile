FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    xinetd \
    gcc \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY string.c .
RUN gcc -o string string.c -fno-stack-protector -no-pie -g

COPY flag.txt /challenge/flag.txt
COPY ctf.xinetd /etc/xinetd.d/ctf

RUN chown -R root:ctf /challenge && chmod -R 750 /challenge
RUN chmod 440 /challenge/flag.txt

EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]