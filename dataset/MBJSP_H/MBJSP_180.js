function distanceLatLong(slat, slon, elat, elon) {
    return 6371.01 * Math.acos(Math.sin(slat) * Math.sin(elat) + Math.cos(slat) * Math.cos(elat) * Math.cos(slon - elon));
}
