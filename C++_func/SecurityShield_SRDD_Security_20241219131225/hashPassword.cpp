string RemoteAccessManager::hashPassword(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);
    string hashedPassword(hash, hash + SHA256_DIGEST_LENGTH);
    return hashedPassword;
}