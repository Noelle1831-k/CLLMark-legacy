#define SIZE 10
void reset_device(int device[SIZE][SIZE], int solution[SIZE][SIZE]) {
    int original[SIZE][SIZE];
    memcpy(original, device, sizeof(original));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int flip = original[i][j];
            if (flip) {
                solution[i][j] = 1;
                if (i > 0) device[i-1][j] ^= 1;
                if (i < SIZE-1) device[i+1][j] ^= 1;
                if (j > 0) device[i][j-1] ^= 1;
                if (j < SIZE-1) device[i][j+1] ^= 1;
                device[i][j] ^= 1;
            }
        }
    }
}
