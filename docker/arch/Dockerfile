FROM archlinux

RUN pacman -Sy --noconfirm && \
    pacman -S --noconfirm nodejs npm

WORKDIR /test

COPY ./package.json .

CMD [ "npm", "install", "fastmath_lib" ]
