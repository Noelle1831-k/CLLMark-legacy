def search_errors(self, keyword):
        return [error for error in self.errors if keyword.lower() in error.message.lower()]