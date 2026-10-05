def find_unused_variables(self):
        unused_vars = []
        assigned_vars = set()
        used_vars = set()
        for node in ast.walk(self.ast_tree):
            if isinstance(node, ast.Assign):
                for target in node.targets:
                    if isinstance(target, ast.Name):
                        assigned_vars.add(target.id)
            elif isinstance(node, ast.Name):
                used_vars.add(node.id)
        unused_vars = assigned_vars - used_vars
        return [f"Unused variable detected: '{var}'" for var in unused_vars]