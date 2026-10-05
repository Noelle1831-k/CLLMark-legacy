def save_feedback(self, feedback):
        try:
            with open(self.filename, 'r') as file:
                data = json.load(file)
        except FileNotFoundError:
            data = []
        data.append(feedback)
        with open(self.filename, 'w') as file:
            json.dump(data, file)