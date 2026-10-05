def get_color_scheme(self):
        '''
        Prompts the user to enter a color scheme.
        Returns:
        dict: A dictionary containing color scheme details.
        '''
        color_scheme = {}
        print("Enter color scheme details:")
        primary_color = input("Primary color: ").strip()
        secondary_color = input("Secondary color: ").strip()
        background_color = input("Background color: ").strip()
        text_color = input("Text color: ").strip()
        color_scheme['primary'] = primary_color
        color_scheme['secondary'] = secondary_color
        color_scheme['background'] = background_color
        color_scheme['text'] = text_color
        return color_scheme