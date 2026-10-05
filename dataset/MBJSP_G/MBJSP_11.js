function removeOcc(s, ch) {
let first = s.indexOf(ch);
let last = s.lastIndexOf(ch);
if (first === -1) return s;
if (first === last) return s.slice(0, first) + s.slice(first + 1);
return s.slice(0, first) + s.slice(first + 1, last) + s.slice(last + 1);
}
