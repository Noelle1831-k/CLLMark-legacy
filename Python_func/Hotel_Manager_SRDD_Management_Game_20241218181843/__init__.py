def __init__(self):
        self.rooms = [Room(i) for i in range(1, 101)]
        self.staff = [Staff(i) for i in range(1, 21)]
        self.inventory = Inventory()
        self.customers = [Customer(i) for i in range(1, 51)]
        self.marketing = Marketing()
        self.revenue = 0
        self.expenses = 0