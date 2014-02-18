GetMySQLField(field[])
{
	new value[256];
	mysql_fetch_field(field, value);
	return value;
}