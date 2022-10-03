import java.util.*;
class CycleSort{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter array size:");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the array elements:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        cycle(arr);
        System.out.println(Arrays.toString(arr));

    }
    static void cycle(int[] arr){
       int i=0;
       while(i<arr.length){
        int correct= arr[i]-1;
        if(arr[i] != arr[correct]){
            swap(arr,i,correct);
        }
        else{
            i++;
        }
       }
    }
    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}