// import java.util.*;

// public class basic2{
//     public static void main(String[] args){

//         Scanner sc = new Scanner(System.in);
//         System.out.println("Enter a number:");
//         int n = sc.nextInt();
//         int [] arr = new int[n];
//         System.out.println("Enter numbers: ");
//         for(int i = 0; i<arr.length ; i++){
//             arr[i] = sc.nextInt();
//         }
//         System.out.println("The array elements are:");
//         for(int i = 0; i<arr.length ; i++){
//             System.out.println(arr[i]);
//         }
        
//     }

// }
import java.util.*;
public class basic2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            list.add(sc.nextInt());
        }



    }
}