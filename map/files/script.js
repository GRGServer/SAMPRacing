var gtaMap;
var playerMapElements = {};
var vehicleModels = {};

function processPlayer(playerData, invalidPlayers)
{
    var latNg = GTAMap.getLatLngFromPos(playerData.position.x, playerData.position.y);

    var playerMapElement;

    if (playerMapElements.hasOwnProperty(playerData.id))
    {
        playerMapElement = playerMapElements[playerData.id];
        playerMapElement.marker.setPosition(latNg);
    }
    else
    {
        playerMapElement =
        {
            infoWindow : new google.maps.InfoWindow(),
            marker : new google.maps.Marker(
            {
                position : latNg,
                map : gtaMap.map
            })
        };

        playerMapElements[playerData.id] = playerMapElement;

        google.maps.event.addListener(playerMapElement.marker, "click", function()
        {
            playerMapElement.infoWindow.open(gtaMap.map, playerMapElement.marker);
        });
    }

    var infoWindowHtml = [];
    infoWindowHtml.push("<table>");

    infoWindowHtml.push("<tr>");
    infoWindowHtml.push("<th>Player:</th>");
    infoWindowHtml.push("<td>" + playerData.name + "</td>");
    infoWindowHtml.push("</tr>");

    if (playerData.vehicleModelId)
    {
        infoWindowHtml.push("<tr>");
        infoWindowHtml.push("<th>Vehicle:</th>");
        infoWindowHtml.push("<td>" + vehicleModels[playerData.vehicleModelId] + "</td>");
        infoWindowHtml.push("</tr>");
    }

    infoWindowHtml.push("</table>");

    playerMapElement.infoWindow.setContent(infoWindowHtml.join(""));

    playerMapElement.marker.setTitle(playerData.name);

    if (invalidPlayers.hasOwnProperty(playerData.id))
    {
        delete invalidPlayers[playerData.id];
    }
}

function getData()
{
    var xmlHttpRequest = new XMLHttpRequest();
    xmlHttpRequest.open("GET", "/getdata.php?type=players", true);
    xmlHttpRequest.onreadystatechange = function()
    {
        if (xmlHttpRequest.readyState == 4 && xmlHttpRequest.status == 200)
        {
            var invalidPlayers = [];
            for (var index in playerMapElements)
            {
                invalidPlayers[index] = true;
            }

            var data = JSON.parse(xmlHttpRequest.responseText);
            for (var playerId in data)
            {
                var playerData = data[playerId];

                processPlayer(playerData, invalidPlayers);
            }

            // Remove no longer used markers
            for (var index in invalidPlayers)
            {
                playerMapElements[index].marker.setMap(null);
            }

        }
    };
    xmlHttpRequest.send();
}

window.onload = function()
{
    gtaMap = new GTAMap(document.getElementById("map"), "/tiles");

    var xmlHttpRequest = new XMLHttpRequest();
    xmlHttpRequest.open("GET", "/getdata.php?type=vehicles", true);
    xmlHttpRequest.onreadystatechange = function()
    {
        if (xmlHttpRequest.readyState == 4 && xmlHttpRequest.status == 200)
        {
            vehicleModels = JSON.parse(xmlHttpRequest.responseText);
        }
    };
    xmlHttpRequest.send();

    window.setInterval(getData, 1000);
};