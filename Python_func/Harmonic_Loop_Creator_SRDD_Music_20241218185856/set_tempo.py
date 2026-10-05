def set_tempo(self, new_tempo):
        if new_tempo > 0:
            self.tempo = new_tempo
            print(f"Tempo set to: {self.tempo}")
        else:
            print("Invalid tempo value. Tempo must be greater than 0.")