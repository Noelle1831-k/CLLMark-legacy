def analyze_combinations(self):
        '''
        Analyzes the strengths and weaknesses of class combinations.
        '''
        for combo in combinations(self.character_classes, 3):
            synergy = calculate_synergy(combo)
            self.combinations_analysis.append((combo, synergy))