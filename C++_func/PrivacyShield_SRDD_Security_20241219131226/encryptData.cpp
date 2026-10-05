void Encryptor::encryptData(const string &fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cout << "Failed to open file for encryption: " << fileName << endl;
        return;
    }
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    string key = generateKey();
    string iv = "0123456789abcdef"; 
    string cipher;
    try {
        CBC_Mode<AES>::Encryption encryption((byte*)key.c_str(), key.size(), (byte*)iv.c_str());
        StringSource ss(data, true, 
            new StreamTransformationFilter(encryption,
                new StringSink(cipher)
            )
        );
    } catch (const Exception &e) {
        cerr << "Encryption error: " << e.what() << endl;
        return;
    }
    cout << "Data encrypted successfully." << endl;
}