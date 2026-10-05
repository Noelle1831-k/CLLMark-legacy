def load(self, report_name):
        with open(f"{report_name}.json", "r") as file:
            self.data = json.load(file)