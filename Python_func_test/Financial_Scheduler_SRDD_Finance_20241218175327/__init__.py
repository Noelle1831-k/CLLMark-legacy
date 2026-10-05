def __init__(self, name, amount, frequency, start_date):
        self.name = name
        self.amount = amount
        self.frequency = frequency
        self.start_date = datetime.datetime.strptime(start_date, "%Y-%m-%d").date()