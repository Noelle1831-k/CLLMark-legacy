def update_preferences(self, user_profile, article):
        '''
        Updates user preferences based on article interactions.
        '''
        user_profile['preferences'].append(article['source'])