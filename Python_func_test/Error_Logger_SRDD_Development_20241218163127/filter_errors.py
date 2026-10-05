def filter_errors(self, project=None, module=None):
        filtered = self.errors
        if project:
            filtered = [error for error in filtered if project == error.project]
        if module:
            filtered = [error for error in filtered if module == error.module]
        return filtered