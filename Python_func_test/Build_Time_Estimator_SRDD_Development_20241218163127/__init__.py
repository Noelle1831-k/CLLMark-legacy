def __init__(self, source_files, module_count, team_size):
        self.source_files = source_files
        self.module_count = module_count
        self.team_size = team_size
        self.code_analyzer = CodeAnalyzer()
        self.module_handler = ModuleHandler()
        self.team_calculator = TeamEfficiencyCalculator()
        self.simulator = BuildProcessSimulator()