#if defined _GeoIP_Plugin_included
	#endinput
#endif
#define _GeoIP_Plugin_included

const MAX_COUNTRY_NAME = 45;
//const MAX_CITY_NAME = 0;

native GetCountryCode(const ipaddress[], country[], size = sizeof country);
native GetCountryCode3(const ipaddress[], country[], size = sizeof country);
native GetCountryName(const ipaddress[], country[], size = sizeof country);
native GetCityLatitude(const ipaddress[], &Float:lat);
native GetCityLongitude(const ipaddress[], &Float:lon);

native GetCountryCodeByName(const name[], country[], size = sizeof country);
native GetCountryCode3ByName(const name[], country[], size = sizeof country);
native GetCountryNameByName(const name[], country[], size = sizeof country);
native GetCityLatitudeByName(const name[], &Float:lat);
native GetCityLongitudeByName(const name[], &Float:lon);

/* Non-native functions, Fake for pawno.
native GetGMT(ip[]);
native GetGMTByName(name[]);
native GetPlayerGMT(playerid);
native GetPlayerCountryCode(playerid);
native GetPlayerCountryCode3(playerid);
native GetPlayerCountryName(playerid);
*/

stock GetGMT(const ip[])
{
	new Float:lon;
	GetCityLongitude(ip, lon);
	return floatround(lon / 15.0);
}

stock GetGMTByName(const name[])
{
	new Float:lon;
	GetCityLongitudeByName(name, lon);
	return floatround(lon / 15.0);
}

stock GetPlayerGMT(playerid)
{
	new ip[16];
	GetPlayerIp(playerid, ip, sizeof(ip));
	return GetGMT(ip);
}

stock GetPlayerCountryCode(playerid)
{
	new ip[16], country[MAX_COUNTRY_NAME];
	GetPlayerIp(playerid, ip, sizeof(ip));
	GetCountryCode(ip, country, sizeof(country));
	return country;
}

stock GetPlayerCountryCode3(playerid)
{
	new ip[16], country[MAX_COUNTRY_NAME];
	GetPlayerIp(playerid, ip, sizeof(ip));
	GetCountryCode3(ip, country, sizeof(country));
	return country;
}

stock GetPlayerCountryName(playerid)
{
	new ip[16], country[MAX_COUNTRY_NAME];

	GetPlayerIp(playerid, ip, sizeof(ip));

	new ret = GetCountryName(ip, country, sizeof(country));
	if(!ret)
		format(country, sizeof(country), "Private IP");

	return country;
}

stock GetPlayerLocationInfos(playerid, country[], city[], &gmt, &Float:latitude = 0.0, &Float:longitude = 0.0)
{
	/*new ip[16];

	GetPlayerIp(playerid, ip, sizeof(ip));

	if(!GetCountryName(ip, country, sizeof(country)))
		format(country, sizeof(country), "Private IP");

	if(!GetCityName(ip, city, sizeof(city)))
		format(city, sizeof(city), "Unknown City");

	gmt = GetGMT(ip);

	GetCityLatitude(ip, latitude);
	GetCityLongitude(ip, longitude);*/

	return false;
}
