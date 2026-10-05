def create_meeting(meetings):
    meeting = Meeting()
    print("Creating a new meeting. Please enter the details below.")
    while True:
        attendee = get_user_input("Enter attendee name (or 'done' to finish): ")
        if attendee.lower() == 'done':
            break
        if attendee.strip():
            meeting.add_attendee(attendee)
        else:
            print("Attendee name cannot be empty. Please try again.")
    while True:
        agenda_item = get_user_input("Enter agenda item (or 'done' to finish): ")
        if agenda_item.lower() == 'done':
            break
        if agenda_item.strip():
            meeting.add_agenda_item(agenda_item)
        else:
            print("Agenda item cannot be empty. Please try again.")
    while True:
        discussion_point = get_user_input("Enter discussion point (or 'done' to finish): ")
        if discussion_point.lower() == 'done':
            break
        if discussion_point.strip():
            meeting.add_discussion_point(discussion_point)
        else:
            print("Discussion point cannot be empty. Please try again.")
    record_audio = get_user_input("Do you want to record audio? (yes/no): ")
    if record_audio.lower() == 'yes':
        meeting.record_audio()
    notes = get_user_input("Enter meeting notes: ")
    meeting.add_notes(notes)
    meetings.append(meeting)
    save_meeting(meetings)
    print("Meeting created and saved successfully.")