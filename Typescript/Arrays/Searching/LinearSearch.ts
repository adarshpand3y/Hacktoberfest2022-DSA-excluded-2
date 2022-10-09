const linearSearch = (arr: number[], target: number) => {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            console.log(`${target} found at index ${i}.`);
            return;
        }
    }

    console.log(`${target} is not present in the array.`);
};

// an example array
const arr: number[] = [90, 8893, -882, 8865, 10];

linearSearch(arr, -11);
linearSearch(arr, 8893);
