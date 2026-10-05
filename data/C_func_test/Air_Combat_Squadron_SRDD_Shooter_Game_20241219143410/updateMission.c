void updateMission(Mission *mission) {
    if (mission->objective == 1) {
        mission->difficulty += 1;
        mission->objective = 2;  
    }
}