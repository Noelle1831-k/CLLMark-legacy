def list_investments(self):
        return [f"{name}: ${details['amount']} with ${details['growth']} growth" for name, details in self.investments.items()]