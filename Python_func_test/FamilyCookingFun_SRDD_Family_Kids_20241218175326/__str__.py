def __str__(self):
        return f"Substitutions: {', '.join([f'{k}: {v}' for k, v in self.substitutions.items()])}"