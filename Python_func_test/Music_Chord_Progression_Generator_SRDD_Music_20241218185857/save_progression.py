def save_progression(self, progression, filename):
        with open(filename, 'w') as file:
            for chord in progression:
                file.write(f"{chord}\n")