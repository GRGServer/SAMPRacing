PickupEvent:VehicleShop(playerID, pickupID, eventType)
{
	if (eventType == PICKUPEVENT_PICKUP)
	{
		PVar:playerID[VEHICLESHOP_PICKUPID] = pickupID;
		EnterVehicleShop(playerID);

		return true;
	}

	return false;
}

PickupModelID:VehicleShop()
{
	return 1274;
}

PickupSetupType:VehicleShop(pickupID, XMLNode:pickupNode)
{
	new XMLNode:vehicleSpawnNode = XML_GetFirstChild(pickupNode, "vehiclespawn");
	if (vehicleSpawnNode)
	{
		new vehicleShopID = g_pickupSetupTypeIDs[E_PUSTID_VEHICLESHOP];
		g_vehicleShops[vehicleShopID][E_VEHICLESHOP_VEHSPAWN_POSX] = XML_GetFloatAttribute(vehicleSpawnNode, "x");
		g_vehicleShops[vehicleShopID][E_VEHICLESHOP_VEHSPAWN_POSY] = XML_GetFloatAttribute(vehicleSpawnNode, "y");
		g_vehicleShops[vehicleShopID][E_VEHICLESHOP_VEHSPAWN_POSZ] = XML_GetFloatAttribute(vehicleSpawnNode, "z");
		g_vehicleShops[vehicleShopID][E_VEHICLESHOP_VEHSPAWN_ANGLE] = XML_GetFloatAttribute(vehicleSpawnNode, "angle");
		g_pickupSetupTypeIDs[E_PUSTID_VEHICLESHOP]++;
		return vehicleShopID;
	}

	return 0;
}