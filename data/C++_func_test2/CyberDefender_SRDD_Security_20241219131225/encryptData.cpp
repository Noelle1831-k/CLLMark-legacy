void Encryption::encryptData() {
    string data = "SensitiveData";
    string encryptedData = simulateEncryption(data);
    cout << "Encrypting data: " << data << " -> " << encryptedData << endl;
}