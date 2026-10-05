def detect_code_smells(self):
        smells = []
        for node in ast.walk(self.ast_tree):
            if isinstance(node, ast.FunctionDef) and len(node.body) > 10:
                smells.append(f"Code smell detected: Long function '{node.name}' with {len(node.body)} lines")
            if isinstance(node, ast.If) and len(node.body) > 5:
                smells.append(f"Code smell detected: Complex if-statement in line {node.lineno}")
        return smells