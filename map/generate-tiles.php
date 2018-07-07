<?php
define("ZOOM_MIN", 1);
define("ZOOM_MAX", 4);
define("SOURCE_FILENAME", __DIR__ . "/../tools/map.jpg");
define("TILES_PATH", __DIR__ . "/tiles");
define("TILES_SIZE", 512);

// This script should only be executed from CLI (e.g. not a browser)
if (php_sapi_name() != "cli") {
    header("HTTP/1.1 403 Forbidden");
    echo "<h1>Forbidden</h1>";
    exit;
}

echo "Loading source image\n";
$sourceImage = imagecreatefromjpeg(SOURCE_FILENAME);

list($sourceWidth, $sourceHeight) = getimagesize(SOURCE_FILENAME);

// Make sure the directory exists and is empty
if (file_exists(TILES_PATH)) {
    $files = scandir(TILES_PATH);
    foreach ($files as $file) {
        if (is_file(TILES_PATH . "/" . $file)) {
            unlink(TILES_PATH . "/" . $file);
        }
    }
}
else
{
    mkdir(TILES_PATH);
}

// Process all zoom levels
for ($zoom = ZOOM_MIN; $zoom <= ZOOM_MAX; $zoom++) {
    $tiles = 1 << $zoom;

    echo "Processing zoom level " . $zoom . " (" . ($tiles * $tiles) . " tiles)\n";

    $tileWidth = $sourceWidth / $tiles;
    $tileHeight = $sourceHeight / $tiles;

    // Process tiles of the zoom level
    for ($tileX = 0; $tileX < $tiles; $tileX++) {
        for ($tileY = 0; $tileY < $tiles; $tileY++) {
            $tileFilename = TILES_PATH . "/" . $zoom . "." . $tileX . "." . $tileY . ".jpg";

            $tileImage = imagecreatetruecolor(TILES_SIZE, TILES_SIZE);

            imagecopyresized($tileImage, $sourceImage, 0, 0, $tileWidth * $tileX, $tileHeight * $tileY, TILES_SIZE, TILES_SIZE, $tileWidth, $tileHeight);

            imagejpeg($tileImage, $tileFilename);
        }
    }
}

echo "Done\n";