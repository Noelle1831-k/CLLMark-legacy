def parse_source_code(self, code):
        utils.log_message("Parsing source code...")
        functions = re.findall(r'def\s+(\w+)\s*\(', code)
        utils.log_message(f"Found {len(functions)} functions in source code.")
        return functions