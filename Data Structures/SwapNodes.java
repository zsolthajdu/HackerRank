package com.zsolthajdu;

import java.io.*;
import java.util.*;

// Solution for
// https://www.hackerrank.com/challenges/swap-nodes-algo

public class Solution {

    private static int[]       left;
    private static int[]       right;

    private static void tree_print( int key )
    {
        if( left[key] != -1 )
            tree_print( left[key] );
        System.out.print( key + " " );
        if( right[key] != -1 )
            tree_print( right[key] );
    }

    // Returns number of nodes where children were swapped
    private static int dfs( int key, int currentLevel, int swapLevel ) {
        int n = 0;
        if( swapLevel == currentLevel ) {
            // Swap children
            int tmp = left[key];
            left[key] = right[key];
            right[key] = tmp;
            n = 1;
        }
        else {
            if( -1 != left[key])
                n += dfs( left[ key ], currentLevel+1, swapLevel );
            if( -1 != right[key] )
                n += dfs( right[key], currentLevel+1, swapLevel );
        }
        return n;
    }

    public static void main(String[] args) throws IOException {
	    // This reads from stdin
        //BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));

        // Read from a file
        InputStream inStream = new FileInputStream("input.txt" );
        BufferedReader bfr = new BufferedReader(new InputStreamReader( inStream ) );
        String[] temp = bfr.readLine().split(" ");

        // N nodes
        int N = Integer.parseInt(temp[0]);

        left = new int[N+1];
        right = new int[N+1];

        for( int i=1 ; i<N+1 ; i++ ) {
            String[] tmp = bfr.readLine().split(" ");
            left[i]  = Integer.parseInt( tmp[0]);
            right[i] = Integer.parseInt( tmp[1]);
        }

        // K swaps
        temp = bfr.readLine().split(" ");
        int K = Integer.parseInt(temp[0]);

        for( int a=0 ; a<K ; a++ ) {
            temp = bfr.readLine().split(" ");
            int s1 = Integer.parseInt(temp[0]);
            int s = s1;

            while( true ) {
                if (0 < s) {
                    // Swap children of all nodes on layer 's'
                    // Do DFS to find them

                    if( 0 == dfs( 1, 1, s ) )
                        // If we didn't swap anything, we can quit
                        break;
                }
                s += s1;
            }
            tree_print( 1 );
            System.out.println(" ");
        }
    }
}
