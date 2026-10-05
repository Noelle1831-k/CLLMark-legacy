string ReceiptManager::getReceiptPath(int id) const {
    auto it = receiptStorage.find(id);
    if (it != receiptStorage.end()) {
        return it->second;
    }
    return "Receipt not found.";
}