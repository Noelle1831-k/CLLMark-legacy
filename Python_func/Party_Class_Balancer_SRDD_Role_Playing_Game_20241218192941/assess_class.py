def assess_class(self, class_name):
        '''
        Analyzes a single class's strengths and weaknesses.
        '''
        if class_name not in self.classes:
            return {}
        abilities = self.classes[class_name]
        strengths = [ability for ability, value in abilities.items() if value > 7]
        weaknesses = [ability for ability, value in abilities.items() if value < 4]
        return {
            "strengths": strengths,
            "weaknesses": weaknesses,
            "average_score": sum(abilities.values()) / len(abilities),
        }