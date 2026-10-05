def identify_sleep_disruptors(self, data):
        disruptors = []
        if data['caffeine_intake'] > 200:
            disruptors.append("High caffeine intake")
        if data['exercise'] < 30:
            disruptors.append("Insufficient exercise")
        self.analysis['disruptors'] = disruptors