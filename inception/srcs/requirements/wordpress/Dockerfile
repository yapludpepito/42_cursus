FROM debian:buster

RUN apt update -y \
    && apt install curl -y \
    && mkdir -p /var/www/html/wordpress/ \
    && mkdir -p /run/php/ \
    && chmod 777 /var/www/html/wordpress/


RUN chown -R www-data:www-data /var/www/html/wordpress \
    && apt install php7.3 php-fpm php-mysql mariadb-client dumb-init wget -y

COPY script.sh ./script.sh

RUN chmod +x script.sh

CMD ["./script.sh"]
