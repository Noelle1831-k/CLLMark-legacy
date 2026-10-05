def manage_logistics(self):
        if self.events:
            logistics_details = {
                "transportation": "Arranged",
                "accommodation": "Booked",
                "equipment": "Checked"
            }
            self.events[-1].logistics = logistics_details