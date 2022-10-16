#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;
 
struct MinHeapNode
{
    // element to be stored
    int element;
 
    // array index from which the element is taken
    int i;
};
 
// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const MinHeapNode &lhs, const MinHeapNode &rhs) const {
        return lhs.element > rhs.element;
    }
};
 
FILE* openFile(char* fileName, char* mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}
 
// Merges `k` sorted files. Names of files are assumed to be 1, 2, … `k`
void mergeFiles(char *output_file, int n, int k)
{
    FILE* in[k];
    for (int i = 0; i < k; i++)
    {
        char fileName[2];
 
        // convert `i` to a string
        snprintf(fileName, sizeof(fileName), "%d", i);
 
        // open output files in reading mode
        in[i] = openFile(fileName, "r");
    }
 
    // FINAL OUTPUT FILE
    FILE *out = openFile(output_file, "w");
 
    // Create a min-heap with `k` heap nodes. Every heap node has the first
    // element of the scratch output file
    MinHeapNode harr[k];
    priority_queue<MinHeapNode, vector<MinHeapNode>, comp> pq;
 
    int i;
    for (i = 0; i < k; i++)
    {
        // break if no output file is empty and
        // index `i` will be a number of input files
        if (fscanf(in[i], "%d ", &harr[i].element) != 1) {
            break;
        }
 
        // index of the scratch output file
        harr[i].i = i;
        pq.push(harr[i]);
    }
 
    int count = 0;
 
    // One by one, get the minimum element from the min-heap and replace
    // it with the next element. Run till all filled input files reach EOF.
    while (count != i)
    {
        // Get the minimum element and store it in the output file
        MinHeapNode root = pq.top();
        pq.pop();
        fprintf(out, "%d ", root.element);
 
        // Find the next element that should replace the current root of the heap.
        // The next element belongs to the same input file as the current
        // minimum element.
        if (fscanf(in[root.i], "%d ", &root.element) != 1 )
        {
            root.element = numeric_limits<int>::max();
            count++;
        }
 
        // Replace the root with the next element of the input file
        pq.push(root);
    }
 
    // close the input and output files
    for (int i = 0; i < k; i++) {
        fclose(in[i]);
    }
 
    fclose(out);
}
 
// Using a merge sort algorithm, create the initial runs and divide them
// evenly among the output files
void createInitialRuns(char *input_file, int run_size, int num_ways)
{
    // For big input file
    FILE *in = openFile(input_file, "r");
 
    // output scratch files
    FILE* out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++)
    {
        // convert `i` to a string
        snprintf(fileName, sizeof(fileName), "%d", i);
 
        // Open output files in write mode.
        out[i] = openFile(fileName, "w");
    }
 
    // allocate a dynamic array large enough to accommodate runs of
    // size `run_size`
    int* arr = new int[run_size];
 
    bool more_input = true;
    int next_output_file = 0;
 
    int i;
    while (more_input)
    {
        // write `run_size` elements into `arr` from the input file
        for (i = 0; i < run_size; i++)
        {
            if (fscanf(in, "%d ", &arr[i]) != 1)
            {
                more_input = false;
                break;
            }
        }
 
        // sort the array using merge sort
        sort(arr, arr + i);
 
        // write the records to the appropriate scratch output file
        // can't assume that the loop runs to `run_size`
        // since the last run's length may be less than `run_size`
        for (int j = 0; j < i; j++) {
            fprintf(out[next_output_file], "%d ", arr[j]);
        }
 
        next_output_file++;
    }
 
    // deallocate memory
    delete arr;
 
    // close the input and output files
    for (int i = 0; i < num_ways; i++) {
        fclose(out[i]);
    }
 
    fclose(in);
}
 
// Program to demonstrate external sorting
int main()
{
    // number of partitions of the input file
    int num_ways = 10;
 
    // the size of each partition
    int run_size = 1000;
 
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
 
    FILE* in = openFile(input_file, "w");
 
    srand(time(NULL));
 
    // generate input
    for (int i = 0; i < num_ways * run_size; i++) {
        fprintf(in, "%d ", rand());
    }
 
    fclose(in);
 
    // Read the input file, create the initial runs,
    // and assign the runs to the scratch output files
    createInitialRuns(input_file, run_size, num_ways);
 
    // Merge the runs using the k–way merging
    mergeFiles(output_file, run_size, num_ways);
 
    return 0;
}
