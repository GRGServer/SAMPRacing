FROM debian:stretch AS builder

RUN apt-get update && \
    apt-get install -y libc6-i386 python3

COPY gamemodes /build/gamemodes
COPY includes /build/includes
COPY npcmodes/npcplayer.pwn /build/npcmodes/npcplayer.pwn
COPY tools /build/tools

WORKDIR /build

RUN tools/compile-gamemode.sh


FROM debian:stretch

ENV SAMP_DIR=/opt/samp \
    SAMP_USER=samp \
    RCON_PASSWORD="" \
    RANDOM_RCON_PASSWORD=false \
    MYSQL_HOST="" \
    MYSQL_USER="" \
    MYSQL_PASSWORD="" \
    MYSQL_DATABASE="" \
    GRG_AUDIO_URL=""

RUN dpkg --add-architecture i386 && \
    apt-get update && \
    apt-get install -y libstdc++6:i386 libgcc1:i386 zlib1g:i386 libncurses5:i386 netcat

WORKDIR ${SAMP_DIR}

COPY docker/entrypoint.sh /docker-entrypoint.sh
COPY announce log-core.so samp03svr samp-npc server.sample.cfg ${SAMP_DIR}/
COPY plugins ${SAMP_DIR}/plugins
COPY npcmodes/recordings ${SAMP_DIR}/npcmodes/recordings
COPY scriptfiles ${SAMP_DIR}/scriptfiles
COPY --from=builder /build/gamemodes/grgserver.amx ${SAMP_DIR}/gamemodes/grgserver.amx
COPY --from=builder /build/npcmodes/npcplayer.amx ${SAMP_DIR}/npcmodes/npcplayer.amx

RUN useradd -d ${SAMP_DIR} ${SAMP_USER} && \
    chown -R ${SAMP_USER}: ${SAMP_DIR} && \
    ln -sf /dev/stdout ${SAMP_DIR}/server_log.txt

USER ${SAMP_USER}
EXPOSE 7777/udp
VOLUME ["${SAMP_DIR}/scriptfiles"]

ENTRYPOINT ["/docker-entrypoint.sh"]
CMD ["server"]