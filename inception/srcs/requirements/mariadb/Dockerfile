FROM debian:buster

RUN apt update -y \
    && apt upgrade -y \
    && apt install mariadb-server mariadb-client dumb-init -y \ 
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

COPY script.sh ./
RUN chmod 777 ./script.sh

ENTRYPOINT ["/usr/bin/dumb-init", "bash","./script.sh"]
CMD ["mysqld", "--bind-address=0.0.0.0"]
