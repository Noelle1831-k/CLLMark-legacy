def suggest_best_combination(self):
        '''
        Suggests the best combination of classes.
        '''
        best_combination = max(self.combinations_analysis, key=lambda x: x[1])
        return best_combination[0]