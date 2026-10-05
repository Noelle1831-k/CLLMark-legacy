def add_play(self, play_name):
        if play_name not in self.plays:
            self.plays[play_name] = Play(play_name)
            print(f"Play '{play_name}' added to strategy '{self.name}'.")
        else:
            print(f"Play '{play_name}' already exists.")