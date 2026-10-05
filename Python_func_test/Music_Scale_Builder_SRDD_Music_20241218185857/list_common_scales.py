def list_common_scales(self):
        common_scales = {
            'Major': [2, 2, 1, 2, 2, 2, 1],
            'Minor': [2, 1, 2, 2, 1, 2, 2],
            'Pentatonic': [2, 2, 3, 2, 3],
            'Blues': [3, 2, 1, 1, 3, 2]
        }
        print("Listing common scales:")
        for name, intervals in common_scales.items():
            print(f"{name} scale: {intervals}")