def _map_choice_to_format(self, choice):
        format_map = {
            '1': 'pdf',
            '2': 'docx',
            '3': 'xlsx',
            '4': 'csv',
            '5': 'pptx',
            '6': 'jpg',
            '7': 'png'
        }
        return format_map.get(choice, 'pdf')