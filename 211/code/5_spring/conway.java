import java.io.*;
import java.util.*;
import java.awt.*;
import java.util.List;
import java.awt.event.*;
import javax.swing.*;
import java.util.stream.Collectors;

class Conway {
    public static void main (String[] args)
    {

        // get a list of integers from a file specified by the first command line
        // argument. This list will be sanitized so it will be a valid set of 
        // grid parameters. {[size of grid x][ y ], [point of living cell x][y] ...}
       ArrayList<int[]> integers_from_file = readFile(args[0]);

       // show that we read in a valid set of grid parameters
       for(int[] point: integers_from_file){
            System.out.println( point[0] + " " + point[1] );
       }

       // create a grid with the already sanitized integer parameters for size
       int x_dimension = integers_from_file.get(0)[0];
       int y_dimension = integers_from_file.get(0)[1];
       GridDisplay grid = new GridDisplay(x_dimension, y_dimension );

       // and create a 2d array representation of the grid as well
       int[][] current_grid_array = new int[x_dimension][y_dimension];
       // we also want a grid array for the next logical frame in the game of life
       // it is to this array that we will write the cells that are coming alive next
       int[][] next_grid_array = new int[x_dimension][y_dimension];
       // a swap array so we can set the new to current and clear the old
       int[][] swap_grid_array = new int[x_dimension][y_dimension];



       // remove size parameter, leaving a list of cells to set to "alive" to start the game of life
       integers_from_file.remove(0);

       // pass grid and list of coordinates to a function that will set their state to "living"
       // both on the graph, and in our array representation
       setLiving( integers_from_file, grid );
       setLiving(integers_from_file, current_grid_array );

       // visually confirm the living cells are represented in the array
       print2dArr(current_grid_array);

       // game loop. keep building next board and updating the visual grid
        while(true) {
           // pause for a second so we can see current board
           grid.mySleep (1000);
           // build next board from existing board and print the result
           buildNextBoard(current_grid_array, next_grid_array);
           // copy the new board into the current bord
           copyArray(next_grid_array, current_grid_array);
           // update the visual grid with the current grid 
           setLiving(current_grid_array, grid);
           // clear the next board so it's ready to be set again next loop
           clearArr(next_grid_array);

       }

    }

    // utility function to print a 2d array 
    public static void print2dArr(int[][] arr) {
        int x = arr.length;
        int y = arr[0].length;

        // start a new line
        System.out.println();
        // for each row
        for (int i = 0; i<x; i++){
            // for each column
            for (int j = 0; j<y; j++){
                // print out the cell and a space
                System.out.print(arr[i][j] + " ");
            }
            // end of row, print a new line character and continue to next row
            System.out.println();
        }
    }

    // utility function to set all values in an array to 0
    // used for preparing an old array to be the next array
    public static void clearArr(int[][] arr) {
        int x = arr.length;
        int y = arr[0].length;
        
        // for each row
        for (int i = 0; i<x; i++){
            // for each column
            for (int j = 0; j<y; j++){
                // set value of array at x,y [i,j] to 0
                arr[i][j] = 0;
            }
        }
    }

    // utility to copy contents of an array to a new array
    public static void copyArray(int[][] source_arr, int[][] dest_arr ) {
        int x = source_arr.length;
        int y = source_arr[0].length;

        // for each row
        for (int i = 0; i<x; i++){
            // for each column
            for (int j = 0; j<y; j++){
                // copy int from old array to new array
                dest_arr[i][j] = source_arr[i][j];
            }
        }
    }

    public static void buildNextBoard(int[][] existingBoard, int[][] nextBoard) {
        
        int x = existingBoard.length;
        int y = existingBoard[0].length;

        for (int i = 0; i<x; i++){
            // for each column
            for (int j = 0; j<y; j++){
                // print out the cell and a space
                gridSquare cell = new gridSquare(i, j, existingBoard);

                // if the cell will be alive next round, add it to the next board
                if ( cell.isAliveNext() ) {
                    nextBoard[i][j] = 1;
                }
            }
        }
    }

    public static void setLiving( int[][] arr, GridDisplay grid ) {

        // for each point in the array, set the color of the corresponding
        // grid square to either be alive or dead [ green, gray ]
        int x = arr.length;
        int y = arr[0].length;
        
        // for each row
        for (int i = 0; i<x; i++){
            // for each column
            for (int j = 0; j<y; j++){
                // if cell in array is a 1, it is allive -> set grid at i,j to green
                if ( arr[i][j] == 1 ){
                    grid.setColor(i, j, Color.GREEN );
                }
                // otherwise it is dead and should be set back to light gray
                else {
                    grid.setColor(i, j, Color.LIGHT_GRAY );
                }
            }
        }
    }

    public static void setLiving( ArrayList<int[]> lives_to_add, GridDisplay grid ) {

        // for each point in the list, set the color of the corresponding
        // grid coordinate to Green indicating it is alive
        // point[0] is the x value, point[1] is the y value
        for(int[] point: lives_to_add){
            grid.setColor(point[0], point[1], Color.GREEN );
       }
    }
    public static void setLiving( ArrayList<int[]> lives_to_add, int[][] grid ) {

        // for each point in the list, set the value to 1 indicating the cell at this 
        // coordinate is alive. This array corresponds to the grid display, but is something
        // we can work with on the backend
        for(int[] point: lives_to_add){
            try {
                grid[ point[0] ][ point[1] ] = 1;
            }
            catch(ArrayIndexOutOfBoundsException e) { }
       }

    }

    // function that takes a file, and returns an array of integers
    // found in the file
    public static ArrayList<int[]> readFile(String filename) {

        File f = new File (filename);
        Scanner sc = null;

        // create an array list (dynamic and easy to work with)
        // to store each integer from the file
        ArrayList<int[]> file_contents = new ArrayList<>();

        // try to open the file
        // if the file cannot be opened, raise an error
        try {
            sc = new Scanner (f);
        }
        catch (FileNotFoundException fnfe) {
         System.out.println ("File did not exist");
            return file_contents;
        }

        // loop until all integers are read from the file
        // each time appending the new int to our array
        while ( sc.hasNextInt() ) {

            // grab next int from file
            int x_val = sc.nextInt();
            int y_val = sc.nextInt();
            int[] point = { x_val, y_val };

            // appends new int to our list as long as it is positive
            // allocating new space if necessary
            if ( x_val > 0 && y_val > 0 ) {
                // the first point in the list represent the size of the grid
                // we only want to add points to the list that will correspond
                // to a square in the boundaries of the grid
                if ( file_contents.size() > 0 && x_val <= file_contents.get(0)[0] && y_val <= file_contents.get(0)[0]) {
                    file_contents.add(point);
                 }
                 // if we don't have the grid bounds set yet, 
                 // add the first point to the list to define them
                 else if (file_contents.size() == 0 ) {
                    file_contents.add(point);
                 }
             }
        }
        return file_contents;
    }
}

// class to represent a given square in a grid
// will include methods to determine if neighbors are alive or dead
class gridSquare {
    int x_val;
    int y_val;
    Boolean alive;
    ArrayList<Boolean> neighbors; 

    public gridSquare(int x, int y, int[][] grid) {

            // the size of our x boundary is the lengrth of our array of arrays
            int domain = grid.length;
            // the size of our y boundary is the length of one of the arrays in the array
            int range = grid[0].length;

            x_val = x;
            y_val = y;

            // if the value in the grid is not zero, alive will be set to TRUE
            alive = (grid[x][y] != 0);

            // an array list that will contain the info on whether
            // each of the surrounding cells is alive or dead
            neighbors = new ArrayList<>();

            // try to add each neighbor to the list of neighbors as a boolean representing
            // whether they are alive or dead
            // the try catch is to make sure we don't break when trying read the life of a grid square that
            // is out of bounds
            try {
            neighbors.add( grid[ x-1 ][ y-1 ] != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x-1 ][ y ]   != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x-1 ][ y+1 ] != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x ][ y-1 ]   != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x ][ y+1]    != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x+1 ][ y-1 ] != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x+1 ][ y ]   != 0 );
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }
            try {
            neighbors.add( grid[ x+ 1 ][ y+1] != 0);
            }
            catch(IndexOutOfBoundsException e) { }//System.out.println(e); }    
    }
    public Boolean isAliveNext() {
        // a filter that turns a list of neighbors into a list of alive neighbors
        // the length of this list will tell us whether the cell with live or die
        List<Boolean> aliveNeighbors = neighbors.stream().filter( p -> p == true ).collect(Collectors.toList());
        
        int num_living_neighbors = aliveNeighbors.size();
        // if the cell is under or overcrowded, return False -> that it will die
        if ( num_living_neighbors < 2 || num_living_neighbors > 3 ) {
            return  false;
        }
        // if the cell has exactly 3 neighbors it will come alive or stay alive
        if ( num_living_neighbors == 3 ) {
            return true;
        }
        // if current cell has 2 living neighbors and is currently alive, it will keep living
        if ( num_living_neighbors == 2 && alive ) {
            return true;
        }
        return false;
    }
}