import java.io.*;
import java.util.*;


public class Travel
{

 public Graph travelGraph;

 Travel(int size) {
     travelGraph = new Graph(size);
 }

 public void processCommandLoop (Scanner sc)
  {
   // loop until all integers are read from the file
   while (sc.hasNext())
   {
       String command = "";
     try {
        command = sc.next();
     }
     catch(NoSuchElementException e) { return; }

     System.out.println ("*" + command + "*");

     if (command.equals("q") == true)
       System.exit(1);

     else if (command.equals("?") == true)
       showCommands();

     else if (command.equals("t") == true)
       doTravel(sc);

     else if (command.equals("r") == true)
       doResize(sc);

     else if (command.equals("i") == true)
       doInsert(sc);

     else if (command.equals("d") == true)
       doDelete(sc);

     else if (command.equals("l") == true)
       doList(sc);

     else if (command.equals("f") == true)
       doFile(sc);

     else if (command.equals("w") == true)
         whereTo(sc);

     else if (command.equals("#") == true)
       ;

     else
       System.out.println ("Command is not known: " + command);


     try {
         sc.nextLine();
     }
     catch(NoSuchElementException e) { return; }

   }

 }

 public void showCommands()
 {
   System.out.println ("The commands for this project are:");
   System.out.println ("  q ");
   System.out.println ("  ? ");
   System.out.println ("  # ");
   System.out.println ("  t <int1> <int2> ");
   System.out.println ("  r <int> ");
   System.out.println ("  i <int1> <int2> ");
   System.out.println ("  d <int1> <int2> ");
   System.out.println ("  l ");
   System.out.println ("  f <filename> ");
 }

 int[] getVals(Scanner sc) {

     int[] vals = new int[2];

     if ( sc.hasNextInt() == true )
       vals[0] = sc.nextInt();
     else
     {
       System.out.println ("Integer value expected");
       return null;
     }

     if ( sc.hasNextInt() == true )
       vals[1] = sc.nextInt();
     else
     {
       System.out.println ("Integer value expected");
       return null;
     }
     return vals;
 }

 public void doTravel(Scanner sc)
 {
   int[] vals = getVals(sc);
   if (vals == null)
      return;
   Linkedlist traveledto = new Linkedlist();
   if ( travelGraph.hasPath(vals[0], vals[1], traveledto) )
        System.out.println("can travel from " + vals[0] + " to " + vals[1]);
   else
        System.out.println("cannot travel from " + vals[0] + " to " + vals[1]);
 }

 public void doResize(Scanner sc)
 {
   int val1 = 0;

   if ( sc.hasNextInt() == true )
     val1 = sc.nextInt();
   else
   {
     System.out.println ("Integer value expected");
     return;
   }

    System.out.println ("Performing the Resize Command with " + val1 );
    travelGraph.resize(val1);
 }

 public void whereTo(Scanner sc)
 {
   int val1 = 0;

   if ( sc.hasNextInt() == true )
     val1 = sc.nextInt();
   else
   {
     System.out.println ("Integer value expected");
     return;
   }

    System.out.println ("Performing the Resize Command with " + val1 );
    Linkedlist list = new Linkedlist();
    Linkedlist destinations = travelGraph.getDestinations(val1, list);

    int[] places = destinations.contents();
    System.out.println("from " + val1 + " you can travel to the following in one or more flights");
    for (int i=0; i<places.length; i++) {
        if( places[i] != val1) {
            System.out.print(places[i] + " ");
        }
    }
    System.out.println();
 }

 public void doInsert(Scanner sc)
 {
     int[] vals = getVals(sc);
     if (vals == null)
        return;
     if ( travelGraph.addEdge(vals[0], vals[1]) )
        System.out.println("added edge to graph");
    else
       System.out.println("could not add edge to graph");
 }



 public void doDelete(Scanner sc)
 {
     int[] vals = getVals(sc);
     if (vals == null)
        return;
     if ( travelGraph.removeEdge(vals[0], vals[1]) )
        System.out.println("removed edge from graph");
    else
       System.out.println("could not remove edge from graph");
 }

 public void doList(Scanner sc)
 {
     travelGraph.printAll();
 }

 public void doFile(Scanner sc)
 {
   String fname = null;
   int val2 = 0;

   if ( sc.hasNext() == true ) {
     fname = sc.next();
    }
   else
   {
     System.out.println ("Filename expected");
     return;
   }

   if ( isopen(fname) ) {
       System.out.println("file already open");
       return;
   }
   System.out.println ("Performing the File command with file: " + fname);

    try {
        File infile;
        infile = new File(fname);

        Agent.filenames[Agent.filenumber] = fname;
        System.out.println(Agent.filenumber);
        Agent.filenumber++;
        System.out.println(Agent.filenumber);
        Scanner scan = new Scanner(infile);
        processCommandLoop (scan);

        Agent.filenames[Agent.filenumber] = "";
        Agent.filenumber--;
        scan.close();
        }
    catch ( FileNotFoundException e) {
        System.out.println(e);
    }

}

    public boolean isopen(String filename) {

        for ( int i=0; i<Agent.filenumber; i++) {

            if ( Agent.filenames[i].equals(filename) )
                return true;
        }
        return false;
    }

}
