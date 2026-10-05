void ReceiptManager::uploadReceipt(int id, const string &path) {
    receiptStorage[id] = path;
    cout << "Receipt uploaded successfully for ID: " << id << endl;
}