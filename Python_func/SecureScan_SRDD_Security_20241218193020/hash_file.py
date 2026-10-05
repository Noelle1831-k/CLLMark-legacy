def hash_file(filename):
    # Simulate hashing a file
    print(f"Hashing file: {filename}")
    return hashlib.sha256(filename.encode()).hexdigest()