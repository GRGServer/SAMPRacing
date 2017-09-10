#! /bin/sh

TOOLSPATH=$(dirname $0)

`sed -nr "s/#define ([a-zA-Z0-9_]+)\s+\"(.*)\"/export \1=\2/p" ${TOOLSPATH}/../includes/grgserver/localconfig.inc`

mysqldump -h "${MYSQL_HOST}" -u "${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --no-data --skip-lock-tables --skip-add-drop-table "${MYSQL_DATABASE}" | grep -ve '^\/\*' | grep -ve '^--' | sed 's/AUTO_INCREMENT=[0-9]\+\?[ ]\+//' | cat -s | sed ':a;N;$!ba;s/^\n\+//g' | sed ':a;N;$!ba;s/\n\+$//g' > ${TOOLSPATH}/../database.sql