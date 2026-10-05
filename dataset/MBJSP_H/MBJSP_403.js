function isValidUrl(str) {
    // regex
    let regex = /^https?:\/\/[^\s]{2,20}\.[^\s]{2,}\.[^\s]{2,}$/;

    // return
    if (regex.test(str)) {
      return true;
    }

    // console.log(str)
    return false;
  }
