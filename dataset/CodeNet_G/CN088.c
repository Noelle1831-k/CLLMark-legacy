const char* encodeTable[37] = {
    "101", "000011", "10010001", "010001", "000001",
    "100101", "10011010", "0101", "0001", "110",
    "01001", "10011011", "010000", "0111", "10011000",
    "0110", "00100", "10011001", "10011110", "00101",
    "111", "10011111", "1000", "00110", "00111",
    "10011100", "10011101", "000010", "10010010", "10010011",
    "10010000", "11010", "11011", "11100", "11101", "11110", "11111"
};
const char* decodeTable[32] = {
    "0", "00000", "00001", "00010", "00011",
    "00100", "00101", "00110", "00111", "01000",
    "01001", "01010", "01011", "01100", "01101",
    "01110", "01111", "10000", "10001", "10010",
    "10011", "10100", "10101", "10110", "10111",
    "11000", "11001", "11010", "11011", "11100",
    "11101", "11110"
};
const char decodeChars[32] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', ',', '-', '\''
};
void convertToEncoded(const char* input, char* intermediateResult) {
    int len = strlen(input);
    for (int i = 0; i < len; ++i) {
        if (input[i] == ' ') {
            strcat(intermediateResult, encodeTable[0]);
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            strcat(intermediateResult, encodeTable[input[i] - 'A' + 5]);
        } else if (input[i] == '.') {
            strcat(intermediateResult, encodeTable[33]);
        } else if (input[i] == ',') {
            strcat(intermediateResult, encodeTable[34]);
        } else if (input[i] == '-') {
            strcat(intermediateResult, encodeTable[35]);
        } else if (input[i] == '\'') {
            strcat(intermediateResult, encodeTable[36]);
        }
    }
}
void encodeAndOutput(const char* input) {
    char intermediateResult[512] = {0};
    char chunks[512] = {0};
    convertToEncoded(input, intermediateResult);
    int len = strlen(intermediateResult);
    int chunkIndex = 0;
    for (int i = 0; i < len; ++i) {
        chunks[chunkIndex++] = intermediateResult[i];
        if (chunkIndex == 5 || i == len - 1) {
            if (chunkIndex < 5) {
                while (chunkIndex < 5) {
                    chunks[chunkIndex++] = '0';
                }
            }
            chunks[chunkIndex] = '\0';
            for (int j = 1; j < 32; ++j) {
                if (strcmp(chunks, decodeTable[j]) == 0) {
                    putchar(decodeChars[j]);
                    break;
                }
            }
            chunkIndex = 0;
        }
    }
    putchar('\n');
}
