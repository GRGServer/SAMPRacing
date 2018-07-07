GetObjectByID(id)
{
    Foreach(index, g_objects)
    {
        if (g_objects[index][E_OBJECT_ID] == id)
        {
            return id;
        }
    }

    return -1;
}