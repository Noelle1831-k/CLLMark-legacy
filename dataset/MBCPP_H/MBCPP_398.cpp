    long result = 0;
    for(int i=0; i <nums.size(); i++)
    {
        long temp = 0;
        if (nums.at(i) >= 0)
            temp = nums.at(i);
        else
            temp = -nums.at(i);
        while(temp > 0)
        {
            result = result + temp % 10;
            temp = temp / 10;
        }
    }
    return result + 0;
}