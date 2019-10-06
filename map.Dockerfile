FROM php:7.3-cli AS tiles-generator

RUN apt-get update && \
    apt-get install -y libfreetype6-dev libjpeg62-turbo-dev libpng-dev && \
    docker-php-ext-configure gd --with-freetype-dir=/usr/include/ --with-jpeg-dir=/usr/include/ && \
    docker-php-ext-install -j$(nproc) gd

COPY map /build/map
COPY tools/map.jpg /build/tools/map.jpg

WORKDIR /build/map

RUN mkdir /build/map/tiles && \
    php generate-tiles.php


FROM php:7.3-apache
RUN echo "ServerTokens Prod" > /etc/apache2/conf-enabled/z-server-tokens.conf && \
    mv "$PHP_INI_DIR/php.ini-production" "$PHP_INI_DIR/php.ini" && \
    sed -ri -e 's!/var/www/html!/opt/samp/map!g' /etc/apache2/sites-available/*.conf && \
    sed -ri -e 's!/var/www/!/opt/samp/map!g' /etc/apache2/apache2.conf /etc/apache2/conf-available/*.conf

COPY map /opt/samp/map
COPY --from=tiles-generator /build/map/tiles /opt/samp/map/tiles
COPY scriptfiles/vehiclemodels.xml /opt/samp/scriptfiles/vehiclemodels.xml