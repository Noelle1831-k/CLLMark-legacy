def parse_query(self, query):
        # Simple query parser
        pattern = re.compile(r'SELECT (.+) FROM dataset WHERE (.+)')
        match = pattern.match(query)
        if match:
            fields = match.group(1).split(f',')
            condition = match.group(2)
            return fields, condition
        else:
            raise ValueError(f'Invalid query format')