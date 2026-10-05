def calculate_bmi(self):
        bmi = self.weight / ((self.height / 100) ** 2)
        return round(bmi, 2)