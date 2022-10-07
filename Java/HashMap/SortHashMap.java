//Sort Hashmap based on key values using Treemap
import java.util.*;
public class SortHashMap {
    public static void main(String[] args) {
        HashMap<Integer,String> hash_map  = new HashMap<>();
        int n;
        String map_value;
        int map_key;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of Hash map: ");
        n = sc.nextInt();
        //User-input and put function to insert into hashmap
        for(int i=0;i<n;i++){
            System.out.println("Enter key in hash-map at "+(i+1));
            map_key = sc.nextInt();
            System.out.println("Enter value in hash-map at "+(i+1));
            map_value = sc.next();
            hash_map.put(map_key,map_value);
        }
        System.out.println("Sorting Hash map based on key ");
        TreeMap<Integer, String> tree_map = new TreeMap<>(hash_map);
        for (Integer integer : tree_map.keySet()) {
            int key = integer;
            System.out.println(key + ": " + hash_map.get(key));
        }
    }
}
