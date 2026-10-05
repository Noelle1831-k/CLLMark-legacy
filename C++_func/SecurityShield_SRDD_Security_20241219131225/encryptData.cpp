string EncryptionManager::encryptData(const string &deviceID, const string &data) {
    cout << "Encrypting data for device: " << deviceID << endl;
    string encryptedData = data + "_encrypted";
    return encryptedData;
}