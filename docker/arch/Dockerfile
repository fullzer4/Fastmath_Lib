FROM archlinux

RUN pacman -Sy --noconfirm && \
    pacman -S --noconfirm nodejs npm

COPY ./package.json .

RUN npm install

RUN ls node_modules

CMD [ "node", "index.js" ]
