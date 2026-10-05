def check_long_methods(self):
        long_methods = []
        for node in ast.walk(self.ast_tree):
            if isinstance(node, ast.FunctionDef) and len(node.body) > 20:
                long_methods.append(f"Long method detected: '{node.name}' exceeds 20 lines")
        return long_methods