RemoteAccessManager::RemoteAccessManager() {
    credentials["admin"] = hashPassword("password123");
}