import java.util.Scanner;
import java.util.Vector;


public class Main {

    public static Scanner cin = new Scanner(System.in);

    final public static int maxn = (int)1e5 + 10;

    public static void solve() {
        int n = cin.nextInt();
        String s = cin.next();
        String t = cin.next();

        Vector a = new Vector<>();
        Vector b = new Vector<>();

        for (int i = 0; i < n; i++) {
            if(s.charAt(i) == '0') a.add(i);
            if(t.charAt(i) == '0') b.add(i);
        }

        if(a.size() != b.size()){
            System.err.println(-1);
            return;
        }
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if(a.elementAt(i) != b.elementAt(i)) res ++; 
        }
        System.err.println(res);

    }

    public static void main(String[] args) {

        int T = 1;
        // T = cin.nextInt();

        for (int i = 1; i <= T; i++) {
            // System.out.print("Case #" + i + ": ");
            solve();
        }

        cin.close();
    }
}