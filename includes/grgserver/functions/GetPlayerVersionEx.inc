GetPlayerVersionEx(playerID)
{
	new version[64];
	GetPlayerVersion(playerID, version, sizeof(version));
	return version;
}