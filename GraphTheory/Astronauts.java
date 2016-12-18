import java.io.*;
import java.util.*;

// https://www.hackerrank.com/challenges/journey-to-the-moon

public class Astronauts {
   public static void main(String[] args) throws Exception{
        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = bfr.readLine().split(" ");
        int N = Integer.parseInt(temp[0]);
        int I = Integer.parseInt(temp[1]);
       int c = 0;
       
       List<Set<Integer>> all = new ArrayList< Set<Integer>>();

        for(int i = 0; i < I; i++){
            temp = bfr.readLine().split(" ");
            int a = Integer.parseInt(temp[0]);
            int b = Integer.parseInt(temp[1]);
            int setA = -1;
            int setB = -1;
          // Store a and b in an appropriate data structure of your choice
            for( c=0 ; c < all.size() ; c++ ) {
                Set<Integer> x = all.get( c );
                if( x.contains( a ) ) {
                    setA = c;
                    if( -1 != setB )
                        break;
                }
                else if( x.contains( b ) ) {
                    setB = c;
                    if( -1 != setA )
                        break;
                }
            }
            if( -1==setA && -1 == setB) {
                // New country
                Set< Integer > nn = new HashSet< Integer >();
                System.err.println( "Adding new set  ..." );
                nn.add( a );
                nn.add( b );
                all.add( nn );
            }
            else if( -1 != setA && -1!=setB ) {
                if( setA != setB ) {
                    System.err.println( "Uniting sets ..." );
                    // Unite sets cause they are same country
                    all.get(setA).addAll( all.get(setB) );
                    all.remove( setB );
                }
            }
            else if( -1 == setA ) {
                all.get(setB).add( a );
                System.err.println( "Adding to a set " );
            }
            else if( -1 == setB ) {
                all.get(setA).add( b );
                System.err.println( "Adding to a set " );
            }
        }

        long combinations = 0;

        // Compute the final answer - the number of combinations
       int allAst = 0;
       
       System.err.println( "We have " + all.size() + " countries." );
       for( int i=0 ; i<all.size() ; i++ ) {
           allAst += all.get(i).size();
           System.err.println( "In country : " + all.get(i).size() );
        }
       
       System.err.println( "All astronauts : " + allAst );
       
       for( ; allAst < N ; allAst++) {
           Set< Integer > nn = new HashSet< Integer >();
           nn.add( 0 );
           all.add( nn );
       }
       
       for( int i=0 ; i<all.size()-1 ; i++ ) {
           int nMen = all.get(i).size();
           for( int j = i+1; j < all.size() ; j++ ) {
               combinations += nMen * all.get(j).size();
           }
       }
        System.out.println(combinations);

    }

}

