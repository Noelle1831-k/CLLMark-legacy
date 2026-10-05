def parse_file(self, file_path):
        '''
        Parses a single Python file to extract documentation data.
        '''
        with open(file_path, 'r', encoding='utf-8') as file:
            source_code = file.read()
        tree = ast.parse(source_code)
        comments = self.extract_comments_and_annotations(source_code)
        classes, functions, variables = self.extract_classes_functions_variables(tree)
        return {
            'comments': comments,
            'classes': classes,
            'functions': functions,
            'variables': variables
        }