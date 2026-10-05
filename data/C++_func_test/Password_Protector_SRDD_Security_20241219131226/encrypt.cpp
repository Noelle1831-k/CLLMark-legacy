string Encryption::encrypt(const string& password) {
    AutoSeededRandomPool prng;
    byte key[AES::DEFAULT_KEYLENGTH];
    byte iv[AES::BLOCKSIZE];
    prng.GenerateBlock(key, sizeof(key));
    prng.GenerateBlock(iv, sizeof(iv));
    string encrypted;
    try {
        CBC_Mode<AES>::Encryption e;
        e.SetKeyWithIV(key, sizeof(key), iv);
        StringSource ss(password, true,
            new StreamTransformationFilter(e,
                new StringSink(encrypted)
            )
        );
    } catch (const Exception& e) {
        throw runtime_error("Encryption failed: " + string(e.what()));
    }
    return encrypted;
}