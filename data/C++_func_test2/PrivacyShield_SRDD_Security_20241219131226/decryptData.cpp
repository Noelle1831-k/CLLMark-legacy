void Encryptor::decryptData(const string &fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cout << "Failed to open file for decryption: " << fileName << endl;
        return;
    }
    string cipher((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    string key = generateKey();
    string iv = "0123456789abcdef"; 
    string recovered;
    try {
        CBC_Mode<AES>::Decryption decryption((byte*)key.c_str(), key.size(), (byte*)iv.c_str());
        StringSource ss(cipher, true, 
            new StreamTransformationFilter(decryption,
                new StringSink(recovered)
            )
        );
    } catch (const Exception &e) {
        cerr << "Decryption error: " << e.what() << endl;
        return;
    }
    cout << "Data decrypted successfully." << endl;
}