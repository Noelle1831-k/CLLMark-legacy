def display_meeting_details(meeting):
    print("Attendees:", ", ".join(meeting.details['attendees']))
    print("Agenda:", "; ".join(meeting.details['agenda']))
    print("Discussion Points:", "; ".join(meeting.details['discussion_points']))
    print("Audio:", meeting.details['audio'])
    print("Notes:", meeting.details['notes'])