def __init__(self):
        self.code_lines = list()
        self.checkers = [
            IndentationChecker(),
            VariableUsageChecker(),
            NamingConventionChecker(),
            DocumentationChecker()
        ]