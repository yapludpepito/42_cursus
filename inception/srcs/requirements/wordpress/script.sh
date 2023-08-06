#!/bin/bash

sleep 15
if [ ! -f "/var/www/html/.done" ] 
then
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html/wordpress
wp core download --allow-root
wp config create	--allow-root \
			--dbname=${MARIADB_TABLE} \
			--dbuser=${MARIADB_USER} \
			--dbpass=${MARIADB_PASS} \
			--dbhost=mariadb:3306 --path='/var/www/html/wordpress'


wp core install --allow-root --url=pdubacqu.42.fr --title=inception_pire_project --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASS} --admin_email=${WP_ADMIN_EMAIL}
wp user create --allow-root bob ${WP_USER_EMAIL} --role=author --user_pass=${WP_USER_PASS} 
touch /var/www/html/.done
fi

sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

exec /usr/sbin/php-fpm7.3 -F
