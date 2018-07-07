ConcatString(string[], addString[], separatorString[], stringSize = sizeof(string))
{
    if (strlen(string))
    {
        strcat(string, separatorString, stringSize);
    }
    strcat(string, addString, stringSize);
}