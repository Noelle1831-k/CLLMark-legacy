def extract_classes_functions_variables(self, tree):
        '''
        Extracts classes, functions, and variables from the AST.
        '''
        classes = []
        functions = []
        variables = []
        for node in ast.walk(tree):
            if isinstance(node, ast.ClassDef):
                classes.append(node.name)
            elif isinstance(node, ast.FunctionDef):
                functions.append(node.name)
            elif isinstance(node, ast.Assign):
                for target in node.targets:
                    if isinstance(target, ast.Name):
                        variables.append(target.id)
        return classes, functions, variables