def analyze_habits(self, habits):
        '''
        Analyze the user's habits to generate recommendations.
        '''
        for habit in habits:
            if habit['frequency'] < 3:
                self.recommendations.append(f"Consider increasing the frequency of {habit['name']}.")