int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if (((a % m) * (x % m)) % m == 1) {
            return x;
        }
    }
    return 1;
}
void decryptAffine(char *cipher, int alpha, int beta, char *result) {
    int m = 26;
    int alpha_inv = modInverse(alpha, m);
    int n = strlen(cipher);
    for (int i = 0; i < n; i++) {
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            int x = cipher[i] - 'a';
            int decrypted = (alpha_inv * (x - beta + m)) % m;
            result[i] = (char)(decrypted + 'a');
        } else {
            result[i] = cipher[i];
        }
    }
    result[n] = '\0';
}
void processDecryption(int datasetCount, char input[][257], char output[][257]) {
    int validAlphas[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    char keywords[2][6] = {"that", "this"};
    int alpha, beta;
    for (int d = 0; d < datasetCount; d++) {
        for (int i = 0; i < 12; i++) {
            for (beta = 0; beta < 26; beta++) {
                alpha = validAlphas[i];
                decryptAffine(input[d], alpha, beta, output[d]);
                if (strstr(output[d], keywords[0]) != NULL || strstr(output[d], keywords[1]) != NULL) {
                    break;
                }
            }
            if (beta < 26) break;
        }
    }
}
