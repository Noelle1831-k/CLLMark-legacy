def get_instrument_by_name(self, name):
        '''
        Retrieve an instrument by its name.
        '''
        for instrument in self.instruments:
            if instrument.name == name:
                return instrument
        print("Instrument not found.")
        return None