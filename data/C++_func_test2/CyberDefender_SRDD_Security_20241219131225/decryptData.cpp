void Encryption::decryptData() {
    string encryptedData = "EncryptedSensitiveData";
    string decryptedData = simulateDecryption(encryptedData);
    cout << "Decrypting data: " << encryptedData << " -> " << decryptedData << endl;
}