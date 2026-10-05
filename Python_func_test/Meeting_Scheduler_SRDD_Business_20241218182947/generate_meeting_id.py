def generate_meeting_id():
        return ''.join(random.choices(string.ascii_uppercase + string.digits, k=6))