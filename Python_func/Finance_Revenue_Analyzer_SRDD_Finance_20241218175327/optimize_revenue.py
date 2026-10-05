def optimize_revenue(self, data):
        print("Optimizing revenue...")
        for source, amount in data.items():
            if amount < 1000:
                print(f"Optimize operations for {source}")