def update_profile(self, age=None, gender=None, interests=None, location=None):
        '''
        Updates the user's profile information.
        '''
        if age:
            self.age = age
        if gender:
            self.gender = gender
        if interests:
            self.interests = interests
        if location:
            self.location = location