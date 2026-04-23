// int map(int value, int in_min, int in_max, int out_min, int out_max)
// {
//     return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }

float to_float(int value, int in_min, int in_max, float out_min, float out_max)
{
    float f = (float)(((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min));
    if(f > out_max)
    {
        f = out_max;
    }
    if(f < out_min)
    {
        f = out_min;
    }
    return f;
}