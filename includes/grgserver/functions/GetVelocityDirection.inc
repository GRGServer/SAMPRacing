Float:GetVelocityDirection(Float:velocityX, Float:velocityY)
{
    if (velocityX < 0)
    {
        if (velocityY > 0)
        {
            return atan(floatabs(velocityX / velocityY));
        }
        else
        {
            return atan(velocityY / velocityX) + 90;
        }
    }

    if (velocityX > 0)
    {
        if (velocityY < 0)
        {
            return atan(floatabs(velocityX / velocityY)) + 180;
        }
        else
        {
            return atan(velocityY / velocityX) + 270;
        }
    }

    if (velocityX == 0)
    {
        if (velocityY > 0)
        {
            return 0.0;
        }
        else if (velocityY < 0)
        {
            return 180.0;
        }
    }

    return 0.0;
}