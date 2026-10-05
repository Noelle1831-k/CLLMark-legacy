def parse_query(self, query):
        # Simple query parser
        pattern = re.compile(r'SELECT (.+) FROM dataset WHERE (.+)')
        match = pattern.match(query)
        if match:
            fields = match.group(1).split(',')
            condition = match.group(2)
            return fields, condition
        else:
            raise ValueError("Invalid query format")