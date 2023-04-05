int mySqrt(int x)
{
    double y = x;

    if (x == 0)
        return 0;
    while (fabs(y * y - x) > 0.1)
        y = (y + x / y) / 2.0;
    return ((int)y);
}
