explode(string[], dest[][], token = ' ', max = sizeof (dest), ml = sizeof (dest[]))
{
    new len = strlen(string);
    new idx;
    new i;
    new cur;
    while (idx < len)
    {
        if (string[idx] == token)
        {
            dest[cur][i] = '\0';
            cur++;
            if (cur == max)
            {
                return cur;
            }
            i = 0;
            while (idx < len && string[idx] == token)
            {
                idx++;
            }
        }
        else
        {
            dest[cur][i++] = string[idx++];
            if (i == ml)
            {
                dest[cur][--i] = '\0';
                while (idx < len && string[idx] != token)
                {
                    idx++;
                }
            }
        }
    }
    dest[cur][i] = '\0';
    return cur + 1;
}