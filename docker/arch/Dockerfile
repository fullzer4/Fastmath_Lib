FROM archlinux

RUN pacman -Sy --noconfirm && \
    pacman -S --noconfirm nodejs npm

COPY ./package.json .

RUN npm install

CMD [ "node", "index.js" ]
