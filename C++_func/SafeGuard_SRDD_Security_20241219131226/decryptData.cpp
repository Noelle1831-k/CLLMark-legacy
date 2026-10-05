string decryptData(const string &data) {
        logger->logEvent("Decrypting data using AES...");
        string decrypted;
        try {
            CBC_Mode<AES>::Decryption decryption;
            decryption.SetKeyWithIV(key, sizeof(key), iv);
            StringSource(data, true, new StreamTransformationFilter(decryption, new StringSink(decrypted)));
        } catch (const Exception &e) {
            logger->logEvent("Decryption error: " + string(e.what()));
        }
        return decrypted;
    }