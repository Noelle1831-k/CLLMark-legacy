def sort_skills(skills):
    return dict(sorted(skills.items(), key=lambda item: item[1], reverse=True))