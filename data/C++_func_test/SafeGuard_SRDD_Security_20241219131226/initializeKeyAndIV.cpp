void initializeKeyAndIV() {
        memset(key, 0x00, AES::DEFAULT_KEYLENGTH);
        memset(iv, 0x00, AES::BLOCKSIZE);
    }