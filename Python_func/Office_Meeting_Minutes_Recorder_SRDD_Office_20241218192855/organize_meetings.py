def organize_meetings(meetings):
    return sorted(meetings, key=lambda x: x.details.get('date', ''))