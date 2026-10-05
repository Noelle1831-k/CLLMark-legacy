def start_game(self):
        print("Welcome to Retail Empire!")
        self.store.add_product("Shirt", 20, 100)
        self.store.add_product("Pants", 30, 50)
        self.store.add_product("Shoes", 50, 30)
        self.store.optimize_layout()
        self.marketing.launch_campaign("Grand Opening")
        self.run_game_loop()