def select_instrument(self):
        '''
        Allows the user to select an instrument from the library.
        '''
        self.ui.display_message("Available Instruments:")
        for instrument in self.instrument_lib.instruments:
            self.ui.display_message(f"- {instrument}")
        instrument = self.ui.get_user_input("Select an instrument: ")
        if instrument in self.instrument_lib.instruments:
            self.selected_instrument = instrument
            self.instrument_lib.select_instrument(instrument)
            self.ui.display_success(f"Instrument {instrument} selected.")
        else:
            self.ui.display_error("Instrument not found.")