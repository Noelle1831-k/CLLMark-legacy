def generate_dialogue(self, context):
        last_input = context.get('last_input', '').lower()
        responses = {
            'hello': 'Greetings, traveler! How can I assist you today?',
            'weather': 'Yes, the weather is indeed quite nice today.',
            'dragon': 'Ah, the dragon in the mountains is a fearsome creature.',
            'default': 'Stay safe on your journey, adventurer.'
        }
        # Select response based on last player input
        for keyword, response in responses.items():
            if keyword in last_input:
                return response
        return responses['default']