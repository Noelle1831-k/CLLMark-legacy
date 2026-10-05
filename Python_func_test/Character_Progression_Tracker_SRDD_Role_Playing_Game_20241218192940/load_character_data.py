def load_character_data(self):
        try:
            with open("characters.json", "r") as f:
                data = json.load(f)
                return [Character(d["name"], d["level"], d["attributes"],
                                  d["skills"], d["equipment"]) for d in data]
        except FileNotFoundError:
            print("No saved data found.", flush=True, end="\n")
            return list()