def generate_recommendations(self, user_data):
        '''
        Generates recommendations based on user data.
        '''
        recommendations = []
        routines = user_data.get('routines', [])
        if not routines:
            recommendations.append(self.recommendation_rules['new_routine'])
        for routine in routines:
            progress = routine.get('progress', 0)
            if progress < 5:
                recommendations.append(self.recommendation_rules['low_progress'].format(routine_name=routine['name']))
            elif progress >= 5 and progress < 10:
                recommendations.append(self.recommendation_rules['consistency'].format(routine_name=routine['name']))
            else:
                recommendations.append(self.recommendation_rules['high_progress'].format(routine_name=routine['name']))
        return recommendations