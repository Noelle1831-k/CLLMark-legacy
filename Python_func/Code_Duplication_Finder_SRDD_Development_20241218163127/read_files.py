def read_files(self, directory):
        files = []
        for root, _, filenames in os.walk(directory):
            for filename in filenames:
                if filename.endswith(('.py', '.java', '.cpp', '.js')):
                    with open(os.path.join(root, filename), 'r', encoding='utf-8') as file:
                        files.append((filename, file.readlines()))
        return files