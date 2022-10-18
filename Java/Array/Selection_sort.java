class Main {  
    public static void selectionSort(int[] arr){  
        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++){  
                if (arr[j] < arr[index]){  
                    index = j; 
                }  
            }  
            int smallerNumber = arr[index];   
            arr[index] = arr[i];  
            arr[i] = smallerNumber;  
        }  
    }  
       
    public static void main(String a[]){  
        int[] arr1 = {7,1,3,2,6,5,8,4};  
        System.out.println("Before Selection Sort");  
        for(int i = 0; i < arr1.length ; i++){  
            System.out.print(arr1[i]+" ");  
        }  
        System.out.println();  
          
        selectionSort(arr1); 
         
        System.out.println("After Selection Sort");  
        for(int i = 0; i < arr1.length ; i++){  
            System.out.print(arr1[i]+" ");  
        }  
    }  
} 