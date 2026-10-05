int isValidDrift(Track* track, float driftAngle) {
    for (int i = 0; i < track->numSegments; i++) {
        if (driftAngle >= track->segmentAngles[i] - 10 && driftAngle <= track->segmentAngles[i] + 10) {
            return 1; 
        }
    }
    return 0; 
}