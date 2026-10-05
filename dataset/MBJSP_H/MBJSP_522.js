function lbs(arr) {
  // First Step: initialize an empty array to hold the max size of the sequence.
  let maxSeqSize = 0;
  // Second Step: For every element in the array...
  for (let i = 0; i < arr.length; i++) {
    let subSeqSize = 0;
    // Find the next highest element, and update the size of the subsequence.
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] > arr[j]) {
        subSeqSize++;
      } else {
        break;
      }
    }
    // Update the current max sequence size with the new size.
    maxSeqSize = Math.max(subSeqSize, maxSeqSize);
  }
  return maxSeqSize;
}
