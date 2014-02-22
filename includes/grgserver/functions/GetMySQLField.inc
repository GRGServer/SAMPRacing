GetMySQLField(field[], row = 0)
{
	new value[256];
	cache_get_field_content(row, field, value);
	return value;
}