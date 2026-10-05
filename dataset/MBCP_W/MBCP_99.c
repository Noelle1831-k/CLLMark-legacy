char* decimalToBinary(int n) {
    char *binary = (char *)malloc(sizeof(char) * 32);
    int index = 0;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binary[index++] = '1';
        else if (index > 0)
            binary[index++] = '0';
    }
    if (index == 0) 
        binary[index++] = '0';
    binary[index] = '\0';
    return binary;
}