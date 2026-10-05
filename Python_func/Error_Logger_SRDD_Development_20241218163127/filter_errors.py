def filter_errors(self, project=None, module=None):
        filtered = self.errors
        if project:
            filtered = [error for error in filtered if error.project == project]
        if module:
            filtered = [error for error in filtered if error.module == module]
        return filtered