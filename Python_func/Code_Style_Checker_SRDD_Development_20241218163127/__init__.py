def __init__(self):
        self.code_lines = []
        self.checkers = [
            IndentationChecker(),
            VariableUsageChecker(),
            NamingConventionChecker(),
            DocumentationChecker()
        ]