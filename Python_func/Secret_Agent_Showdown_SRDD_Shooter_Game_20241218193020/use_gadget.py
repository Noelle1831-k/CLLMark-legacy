def use_gadget(self, gadget_name):
        '''
        Use the specified gadget.
        '''
        if gadget_name in self.gadgets:
            print(f"Using gadget: {gadget_name}")
            # Gadget usage logic
        else:
            print("Gadget not available")