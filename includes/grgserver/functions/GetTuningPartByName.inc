GetTuningPartByName(name[])
{
    if (IsStr(name, "frontBumber"))
    {
        return TUNINGPART_FRONTBUMBER;
    }
    else if (IsStr(name, "hood"))
    {
        return TUNINGPART_HOOD;
    }
    else if (IsStr(name, "lights"))
    {
        return TUNINGPART_LIGHTS;
    }
    else if (IsStr(name, "neon"))
    {
        return TUNINGPART_NEON;
    }
    else if (IsStr(name, "rearBumber"))
    {
        return TUNINGPART_REARBUMBER;
    }
    else if (IsStr(name, "roof"))
    {
        return TUNINGPART_ROOF;
    }
    else if (IsStr(name, "spoiler"))
    {
        return TUNINGPART_SPOILER;
    }

    return TUNINGPART_UNKNOWN;
}