def calculate_statistics(routines):
    '''
    Calculates statistics for user routines.
    '''
    total_routines = len(routines)
    total_progress = sum(r.progress for r in routines)
    return {
        'total_routines': total_routines,
        'total_progress': total_progress
    }