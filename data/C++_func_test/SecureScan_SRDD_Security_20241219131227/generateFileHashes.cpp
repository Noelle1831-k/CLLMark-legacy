void FileIntegrityChecker::generateFileHashes() {
    cout << "Generating file hashes..." << endl;
    fileHashes["file1.txt"] = "hash1";
    fileHashes["file2.exe"] = "hash2";
    fileHashes["file3.dll"] = "hash3";
    cout << "Hashes generated successfully." << endl;
}