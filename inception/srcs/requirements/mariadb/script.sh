#!/bin/bash

if [ -d /var/lib/mysql/jul ];
then
	echo "databse already exist"
else

mysql_install_db

/etc/init.d/mysql start

mysql_secure_installation << EOF
 
Y
${MARIADB_PASS}
${MARIADB_PASS}
Y
n
Y
Y
EOF

sleep 3

	mysql -e "CREATE DATABASE IF NOT EXISTS ${MARIADB_TABLE};"
	mysql -e "CREATE USER IF NOT EXISTS ${MARIADB_USER}@'localhost' IDENTIFIED BY '${MARIADB_PASS}';"
	mysql -e "GRANT ALL PRIVILEGES ON ${MARIADB_TABLE}.* TO ${MARIADB_USER}@'%' IDENTIFIED BY '${MARIADB_PASS}';"
	mysql -e "FLUSH PRIVILEGES;"
	
/etc/init.d/mysql stop

fi

exec "$@"
