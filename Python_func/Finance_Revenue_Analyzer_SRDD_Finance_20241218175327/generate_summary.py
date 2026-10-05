def generate_summary(self, data):
        print("Summary Report")
        for source, amount in data.items():
            print(f"{source}: {amount}")