def parse(self):
        try:
            return ast.parse(self.source_code)
        except SyntaxError as e:
            print(f"Syntax error in source code: {e}")
            return None