def book_room(self, room_number, date, start_time, end_time):
        room = self.database.get_room(room_number)
        if not validate_date(date) or not validate_time(start_time) or not validate_time(end_time):
            return f"Invalid date or time format."
        if room and room.book_room(date, start_time, end_time):
            return f"Room {room_number} successfully booked for {date} from {start_time} to {end_time}."
        return f"Room {room_number} is not available for the selected time slot."