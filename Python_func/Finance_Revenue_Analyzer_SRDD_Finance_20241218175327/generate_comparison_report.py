def generate_comparison_report(self, data, targets):
        print("Comparison Report")
        for source, amount in data.items():
            target = targets.get(source, 0)
            difference = amount - target
            status = "Above Target" if difference >= 0 else "Below Target"
            print(f"Source: {source}")
            print(f"Total Amount: {amount}")
            print(f"Target Amount: {target}")
            print(f"Difference: {difference} ({status})")
            print("----------")