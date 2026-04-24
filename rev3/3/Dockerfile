FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    socat \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d /challenge ctf
WORKDIR /challenge

COPY stack3 .

ENV VSOSH_FLAG="flag{1hird_0weeRfl0W}"

RUN chown -R root:ctf /challenge && \
    chmod 750 /challenge/stack3

EXPOSE 1343

USER ctf

CMD ["socat", "TCP-LISTEN:1343,reuseaddr,fork", "EXEC:/challenge/stack3,stderr"]