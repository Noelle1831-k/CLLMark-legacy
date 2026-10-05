def __init__(self, parameters):
        '''
        Initialize the QuestAnalyzer with quest parameters.
        '''
        self.parameters = QuestParameters(*parameters)
        self.calculator = DifficultyCalculator()