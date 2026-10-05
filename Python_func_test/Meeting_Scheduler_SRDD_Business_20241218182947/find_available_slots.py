def find_available_slots(self, participants, duration):
        available_slots = []
        common_slots = participants[0].availability
        for participant in participants[1:]:
            new_common_slots = []
            for slot in common_slots:
                for p_slot in participant.availability:
                    if slot.overlaps(p_slot):
                        start_time = max(slot.start_time, p_slot.start_time)
                        end_time = min(slot.end_time, p_slot.end_time)
                        new_slot = TimeSlot(start_time, end_time)
                        if new_slot.get_duration() >= duration:
                            new_common_slots.append(new_slot)
            common_slots = new_common_slots
        return common_slots