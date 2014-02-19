Hash(string[])
{
	new buffer[129];
	WP_Hash(buffer, sizeof(buffer), string);
	return buffer;
}