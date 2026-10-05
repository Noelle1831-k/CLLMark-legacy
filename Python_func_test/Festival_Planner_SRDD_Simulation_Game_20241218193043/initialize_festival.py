def initialize_festival(self):
        '''
        Initializes artists, venues, tickets, and finances for the festival.
        '''
        print("Initializing Festival Components...", flush=True)
        self.artists = [Artist(f"Artist_{i}", choice(["Rock", "Pop", "Jazz"]), randint(500, 1000)) for i in range(10)]
        self.venues = [Venue(f"Venue_{i}", randint(1000, 5000), choice(["Sunny", "Rainy", "Cloudy"])) for i in range(3)]
        self.tickets = Ticket()
        self.finance = Finance()