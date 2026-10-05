def generate_detailed_report(self, data):
        print("Detailed Report")
        for source, amount in data.items():
            print(f"Source: {source}")
            print(f"Total Amount: {amount}")
            print("----------")