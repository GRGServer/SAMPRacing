SaveGarage(garageNumber)
{
	MySQLFormat("INSERT INTO `garages` (`id`, `userId`, `price`) VALUES(%d, %d, %d) ON DUPLICATE KEY UPDATE `userId` = %d, `price` = %d", g_garages[garageNumber][E_GARAGE_ID], g_garages[garageNumber][E_GARAGE_USERID], g_garages[garageNumber][E_GARAGE_PRICE], g_garages[garageNumber][E_GARAGE_USERID], g_garages[garageNumber][E_GARAGE_PRICE]);
	mysql_pquery(1, g_sqlQuery);
}