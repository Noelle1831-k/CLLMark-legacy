string Encryption::decrypt(const string& encryptedPassword) {
    AutoSeededRandomPool prng;
    byte key[AES::DEFAULT_KEYLENGTH];
    byte iv[AES::BLOCKSIZE];
    prng.GenerateBlock(key, sizeof(key));
    prng.GenerateBlock(iv, sizeof(iv));
    string decrypted;
    try {
        CBC_Mode<AES>::Decryption d;
        d.SetKeyWithIV(key, sizeof(key), iv);
        StringSource ss(encryptedPassword, true,
            new StreamTransformationFilter(d,
                new StringSink(decrypted)
            )
        );
    } catch (const Exception& e) {
        throw runtime_error("Decryption failed: " + string(e.what()));
    }
    return decrypted;
}