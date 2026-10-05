def identify_sleep_disruptors(self, data):
        disruptors = list()
        if (200 <= data[f'caffeine_intake'] and 200 != data[f'caffeine_intake']):
            disruptors.append(f'High caffeine intake')
        if (data[f'exercise'] <= 30 and data[f'exercise'] != 30):
            disruptors.append(f'Insufficient exercise')
        self.analysis[f'disruptors'] = disruptors