def calculate_bmi(self):
        '''
        Calculate Body Mass Index.
        '''
        height_in_meters = self.user.height / 100
        bmi = self.user.weight / (height_in_meters ** 2)
        return bmi