def read_file(self, filename):
        if filename in self.files:
            return self.files[filename]
        else:
            print(f'File {filename} not found.', flush=True, end='\n')
            return