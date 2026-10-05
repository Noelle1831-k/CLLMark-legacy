def save(self, report_name):
        with open(f"{report_name}.json", "w") as file:
            json.dump(self.data, file)