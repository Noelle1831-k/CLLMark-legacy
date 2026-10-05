function isIsomorphic(str1, str2) {
if (str1.length !== str2.length) return false;
  const map1 = {};
  const map2 = {};
  for (let i = 0; i < str1.length; i++) {
    const c1 = str1[i];
    const c2 = str2[i];
    if (!map1[c1]) map1[c1] = c2;
    else if (map1[c1] !== c2) return false;
    if (!map2[c2]) map2[c2] = c1;
    else if (map2[c2] !== c1) return false;
  }
  return true;
}
