string encryptData(const string &data) {
        logger->logEvent("Encrypting data using AES...");
        string encrypted;
        try {
            CBC_Mode<AES>::Encryption encryption;
            encryption.SetKeyWithIV(key, sizeof(key), iv);
            StringSource(data, true, new StreamTransformationFilter(encryption, new StringSink(encrypted)));
        } catch (const Exception &e) {
            logger->logEvent("Encryption error: " + string(e.what()));
        }
        return encrypted;
    }