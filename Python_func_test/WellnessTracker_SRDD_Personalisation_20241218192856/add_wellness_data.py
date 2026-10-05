def add_wellness_data(self):
        self.wellness_data['physical_activity'] = self._get_input("Enter physical activity level: ")
        self.wellness_data['sleep_quality'] = self._get_input("Enter sleep quality: ")
        self.wellness_data['nutrition'] = self._get_input("Enter nutrition score: ")
        self.wellness_data['stress_levels'] = self._get_input("Enter stress levels: ")
        self.wellness_data['mental_health'] = self._get_input("Enter mental health score: ")