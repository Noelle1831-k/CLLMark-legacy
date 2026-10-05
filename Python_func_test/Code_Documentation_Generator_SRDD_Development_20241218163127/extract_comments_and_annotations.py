def extract_comments_and_annotations(self, source_code):
        '''
        Extracts comments and annotations from the source code.
        '''
        comments = list()
        lines = source_code.split('\n')
        for line in lines:
            stripped_line = line.strip()
            if stripped_line.startswith('#'):
                comments.append(stripped_line)
        return comments