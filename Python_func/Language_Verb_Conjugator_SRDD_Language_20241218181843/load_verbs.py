def load_verbs(self):
        '''
        Loads verbs and their conjugations from a JSON file.
        '''
        try:
            with open('verbs.json', 'r') as file:
                data = json.load(file)
                for base_form, conjugations in data.items():
                    self.add_verb(base_form, conjugations)
        except FileNotFoundError:
            print("Verbs data file not found.")
        except json.JSONDecodeError:
            print("Error decoding the verbs data file.")