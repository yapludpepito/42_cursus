From debian:buster

RUN apt update -y && apt upgrade -y && apt-get install nginx -y && apt-get install openssl -y

COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
    -keyout /etc/ssl/private/pdubacqu.key \
    -out /etc/ssl/certs/pdubacqu.crt \
    -sha256 -subj "/C=FR/ST=FRANCE/L=ANGOULEME/O=42 ANGOULEME/OU=pdubacqu/CN=pdubacqu/"


CMD ["nginx", "-g", "daemon off;"]
