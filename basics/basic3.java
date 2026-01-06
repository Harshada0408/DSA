import java.util.*;
public class basic3{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        System.out.println("Enter elements:");
        for(int i=0 ; i<n ;i++){
            list.add(sc.nextInt());
        }
        System.out.println(list);
        //add elements
        list.add(100);
        list.add(2,38);
        System.out.println(list);
        
        //update
        list.set(1,0);
        System.out.println(list);
        
        //remove
        list.remove(2);
        list.remove(Integer.valueOf(4));
        System.out.println(list);
        
        //size
        System.out.println(list.size());
        
        
    }
}
