#! /bin/bash

if [[ ! -e ${SAMP_DIR}/server.cfg ]]; then
    cp ${SAMP_DIR}/server.sample.cfg ${SAMP_DIR}/server.cfg
fi

if [[ ${RANDOM_RCON_PASSWORD} == "true" ]] && grep -q "^rcon_password changeme$" ${SAMP_DIR}/server.cfg; then
    RCON_PASSWORD=$(date +%s | sha256sum | base64 | head -c 32)

    echo ""
    echo "GENERATED RCON PASSWORD: ${RCON_PASSWORD}"
    echo ""
fi

if [[ -z ${RCON_PASSWORD} ]] || [[ ${RCON_PASSWORD} == "changeme" ]]; then
    echo "Environment variable RCON_PASSWORD not defined or set to the default value 'changeme'!"
    echo "Set RANDOM_RCON_PASSWORD to 'true' to generate a random RCON password"
    exit 1
fi

# Configure MySQL connection if specified as environment variables
if [[ ! -z ${MYSQL_HOST} ]]; then
    cat << EOF > ${SAMP_DIR}/mysql.ini
hostname = ${MYSQL_HOST}
username = ${MYSQL_USER:-samp}
password = ${MYSQL_PASSWORD:-samp}
database = ${MYSQL_DATABASE:-samp}
EOF
fi

sed -i "s/^rcon_password .*$/rcon_password ${RCON_PASSWORD}/g" ${SAMP_DIR}/server.cfg

case "$1" in
    server)
        MYSQL_HOST=$(grep "^hostname " ${SAMP_DIR}/mysql.ini | cut -d "=" -f 2 | awk '{print $1}')
        MYSQL_PORT=$(grep "^server_port " ${SAMP_DIR}/mysql.ini | cut -d "=" -f 2 | awk '{print $1}')

        if [[ ! -z ${MYSQL_HOST} ]]; then
            echo "Waiting for MySQL server to be reachable..."
            while ! nc -vz ${MYSQL_HOST} ${MYSQL_PORT:-3306} > /dev/null; do
                sleep 1
            done
        fi

        exec ${SAMP_DIR}/samp03svr
    ;;

    *)
        exec "$@"
    ;;
esac