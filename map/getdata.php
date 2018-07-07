<?php
$data = array();

switch ($_GET["type"]) {
    case "vehicles":
        $domDocument = new DOMDocument;
        $domDocument->load(__DIR__ . "/../scriptfiles/vehiclemodels.xml");

        $models = $domDocument->getElementsByTagName("model");
        foreach ($models as $model) {
            $id = $model->getAttribute("id");
            $name = $model->getAttribute("name");

            $data[$id] = $name;
        }
        break;
    case "players":
        $file = fopen(__DIR__ . "/../scriptfiles/playerstats.dat", "r");
        if ($file) {
            while (($line = fgets($file)) !== false) {
                $playerData = new StdClass;
                $playerPosition = new StdClass;

                list($playerData->id, $playerData->name, $playerPosition->x, $playerPosition->y, $playerPosition->z, $playerPosition->interior, $playerData->vehicleModelId) = explode("\t", $line);

                $playerPosition->x = (float) $playerPosition->x;
                $playerPosition->y = (float) $playerPosition->y;
                $playerPosition->z = (float) $playerPosition->z;
                $playerPosition->interior = (int) $playerPosition->interior;

                $playerData->position = $playerPosition;

                $playerData->id = (int) $playerData->id;
                $playerData->vehicleModelId = (int) $playerData->vehicleModelId;

                $data[$playerData->id] = $playerData;
            }
            fclose($file);
        }
        break;
}

header("Content-Type: application/json");
echo json_encode($data);