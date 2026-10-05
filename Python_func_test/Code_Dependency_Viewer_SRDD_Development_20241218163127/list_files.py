def list_files(self, directory, pattern='*'):
        '''
        Lists all files in a directory matching a specific pattern.
        '''
        matched_files = []
        for root, dirs, filenames in os.walk(directory):
            for extension in self.supported_extensions:
                for filename in fnmatch.filter(filenames, pattern + extension):
                    matched_files.append(os.path.join(root, filename))
        return matched_files