import java.io.*;
import java.math.*;
import java.util.*;

// https://www.hackerrank.com/challenges/fibonacci-modified

public class FibonacciModified {

    public static void main(String[] args) throws IOException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = bfr.readLine().split(" ");
        
        BigInteger[] fib = new BigInteger[ 25 ];

        fib[0] = new BigInteger( temp[0] );
        fib[1] = new BigInteger( temp[1] );

        int n = Integer.parseInt( temp[2] );
        int  i;
        for( i=2 ; i<n ; i++ ) 
            fib[i] = fib[i-2].add(  fib[i-1].pow( 2 ) );

        System.out.println( fib[i-1]);
    }
}
