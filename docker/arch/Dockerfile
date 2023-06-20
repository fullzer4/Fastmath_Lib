FROM archlinux

RUN pacman -Sy --noconfirm && \
    pacman -S --noconfirm nodejs npm

COPY ../testenv/index.js .
COPY ../testenv/package.json .

RUN npm install

CMD [ "node", "index.js" ]
