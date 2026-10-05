def decrypt_data(data):
    print("Decrypting data...")
    # Implement decryption logic here
    if data.startswith("encrypted_"):
        decrypted_data = data[len("encrypted_"):]
        return decrypted_data
    return data