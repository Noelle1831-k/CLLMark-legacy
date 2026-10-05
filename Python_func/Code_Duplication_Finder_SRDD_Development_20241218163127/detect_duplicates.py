def detect_duplicates(self, code_segments, window_size=3):
        hash_map = {}
        duplicates = []
        for i in range(len(code_segments) - window_size + 1):
            block = tuple(code_segments[i:i + window_size])
            block_hash = hashlib.sha256(''.join(line[2] for line in block).encode()).hexdigest()
            if block_hash in hash_map:
                duplicates.append(block)
            else:
                hash_map[block_hash] = block
        return duplicates