string EncryptionManager::decryptData(const string &deviceID, const string &encryptedData) {
    cout << "Decrypting data for device: " << deviceID << endl;
    string decryptedData = encryptedData.substr(0, encryptedData.find("_encrypted"));
    return decryptedData;
}