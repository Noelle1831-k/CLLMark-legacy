def filter_files(self, files, keyword):
        '''
        Filters files that contain a specific keyword in their content.
        '''
        filtered_files = []
        for file in files:
            content = self.read_file(file)
            if keyword in content:
                filtered_files.append(file)
        return filtered_files