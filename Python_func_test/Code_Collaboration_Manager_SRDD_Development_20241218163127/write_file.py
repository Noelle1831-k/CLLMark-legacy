def write_file(self, filename, content):
        self.files[filename] = content
        print(f"File {filename} updated.")