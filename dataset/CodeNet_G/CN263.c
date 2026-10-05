void processHex(const char* hexString, double* result) {
    unsigned int binaryValue = (unsigned int)strtol(hexString, NULL, 16);
    int sign = (binaryValue & 0x80000000) ? -1 : 1;
    int integerPart = (binaryValue >> 7) & 0x00FFFFFF;
    int fractionBinary = binaryValue & 0x0000007F;
    double fractionPart = 0.0;
    for (int i = 0; i < 7; ++i) {
        if (fractionBinary & (1 << (6 - i))) {
            fractionPart += 1.0 / (1 << (i + 1));
        }
    }
    *result = sign * (integerPart + fractionPart);
}