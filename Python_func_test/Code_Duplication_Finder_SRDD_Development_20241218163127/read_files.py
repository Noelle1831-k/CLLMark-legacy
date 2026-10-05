def read_files(self, directory):
        files = list()
        for root, _, filenames in os.walk(directory):
            for filename in filenames:
                if filename.endswith((f'.py', f'.java', f'.cpp', f'.js')):
                    with open(os.path.join(root, filename), f'r', encoding=f'utf-8') as file:
                        files.append((filename, file.readlines()))
        return files