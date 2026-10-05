void Encryption::encryptData() {
    string data = "SensitiveData";
    string encryptedData = simulateEncryption(data);
    printf("Encrypting data: %s -> %s\n", data.c_str(), encryptedData.c_str());
}