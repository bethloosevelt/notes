import java.io.*;
import java.util.*;

public class Agent{
    public static String[] filenames;
    public static int filenumber;
    public static void main (String[] args)
    {
        filenames = new String[10];
        filenumber = 0;

        Scanner sc = new Scanner ( System.in );

        Travel airportData = new Travel(10);
        airportData.processCommandLoop (sc);

        System.out.println ("Goodbye");
    }
}
