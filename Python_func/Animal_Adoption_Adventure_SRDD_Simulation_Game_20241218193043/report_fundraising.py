def report_fundraising(self):
        print("Fundraising events and total funds:")
        for event in self.events:
            print(f"Event: {event}")
        print(f"Total funds: ${self.funds}")