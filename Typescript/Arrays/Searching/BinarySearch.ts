const binarySearch = (arr: number[], target: number) => {
    let startIdx = 0;
    let endIdx = arr.length - 1;

    while (startIdx <= endIdx) {
        // find the mid index
        let midIdx = Math.floor((startIdx + endIdx) / 2);

        // check whether element found
        if (arr[midIdx] === target) {
            console.log(`${target} found at index ${midIdx}.`);
            return;
        }

        // if not found, continue searching
        else if (arr[midIdx] < target) startIdx = midIdx + 1;
        else endIdx = midIdx - 1;
    }

    console.log(`${target} is not present in the array.`);
};

// an example array
const arr: number[] = [90, 8893, -882, 8865, 10];

// binary search only works on sorted arrays
arr.sort();

binarySearch(arr, -11);
binarySearch(arr, 8893);
