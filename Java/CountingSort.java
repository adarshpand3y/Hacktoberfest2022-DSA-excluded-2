class CountingSort{

    static void print(int arr[]){
        for(int x : arr)
        System.out.print(x+" ");
        System.out.println();
    }
    public static void main(String[] args) {
        
       int arr[] = {22,11,7,3,21,12};

       // first calculate range i.e. max element

       int mx = Integer.MIN_VALUE;
       for (int i = 0; i < arr.length; i++) {
          mx = Math.max(mx, arr[i]);
       }

       int freq[] = new int[mx+1];

       // count each element

       for (int i = 0; i < arr.length; i++) {
           freq[arr[i]]++;
       }

       // Replace each element according to the freq array

       int pos = 0;
       for (int i = 0; i < freq.length; i++) {
           
           while(freq[i]>0){
               arr[pos] = i;
               freq[i]--;
               pos++;
           }
       }

        print(arr);
    }
}
