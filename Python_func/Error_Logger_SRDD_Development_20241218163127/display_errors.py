def display_errors(self, errors=None):
        if errors is None:
            errors = self.logger.errors
        if not errors:
            print("No errors found.")
        else:
            for error in errors:
                print(error)