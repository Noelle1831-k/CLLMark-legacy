def suggest_substitution(self, ingredient):
        suggestion = self.substitution.suggest(ingredient)
        logging.info(f"Substitution suggestion for '{ingredient}': {suggestion}")
        return suggestion