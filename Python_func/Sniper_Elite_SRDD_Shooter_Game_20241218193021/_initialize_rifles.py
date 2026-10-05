def _initialize_rifles(self):
        '''
        Initializes a list of available rifles with unique characteristics.
        '''
        print("Initializing rifles...")
        rifles = [
            {"name": "Springfield M1903", "caliber": "30-06", "range": 800, "stability": 70},
            {"name": "Karabiner 98k", "caliber": "7.92mm", "range": 1000, "stability": 75},
            {"name": "Mosin-Nagant M91/30", "caliber": "7.62mm", "range": 900, "stability": 80},
            {"name": "Lee-Enfield No.4", "caliber": "303 British", "range": 850, "stability": 65}
        ]
        return rifles