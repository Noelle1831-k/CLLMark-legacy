def analyze_growth_opportunities(self, data):
        print("Analyzing growth opportunities...")
        for source, amount in data.items():
            if amount < 1000:
                print(f"Consider increasing marketing for {source}")