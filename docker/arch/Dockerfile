FROM archlinux

RUN pacman -Sy --noconfirm && \
    pacman -S --noconfirm nodejs npm

WORKDIR /test

COPY ./package.json .

RUN npm install fastmath_lib

CMD [ "node", "index.js" ]
