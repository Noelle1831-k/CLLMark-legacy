def _parse_input(self, prompt):
        return [item.strip().lower() for item in input(prompt).split(',') if item.strip()]