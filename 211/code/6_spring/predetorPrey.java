import java.io.*;
import java.util.*;
import java.awt.*;
import java.util.List;
import java.awt.event.*;
import javax.swing.*;
import java.util.stream.Collectors;

class ecoSimulation {
	
	// a dimention from which the square world will be created
	public final int worldSize = 20;
	// starting number of ants
	public final int starting_antBug_count    = 100;
	public final int starting_doodleBug_count = 5;

	public static void main(String[] args) {

		// two main data structures
		// a 2d array that represents the world and the bugs living in it
		// each space in the array is either [0: empty, 1: antBug, 2: doodleBug]
		int[][] world = new int[worldSize][worldSize];
		// and a list of those bugs
		// for data stored in each bug, see bug Class implimentation
		ArrayList<bug> bugs = new ArrayList<>;

		for (int i = 0; i < starting_antBug_count; i++) {

			// create a new ant
			antBug tempAntBug = new antBug();
			
			// have it add itsself to the world: updates coordinate info in the bug, returns the new world
			// that contains the representation of the bug that we just added
			world = tempAntBug.addSelfToWorld(world);
			
			// add the object to our collection of bugs
			bugs.add(tempAntBug);
		}

		for (int i = 0; i < starting_doodleBug_count; i++) {
			
			// create a new doodle bug
			doodleBug tempDoodleBug = new doodleBug();
			// have it add itsself to the world: updates coordinate info in the bug, returns the new world
			// that contains the representation of the bug that we just added
			world = tempDoodleBug.addSelfToWorld(world);

			// add the object to our collection of bugs
			bugs.add(tempDoodleBug);
		}

	}	

	public static void setBugColors( ArrayList<int[]> lives_to_add, GridDisplay grid ) {

        // for each point in the list, set the color of the corresponding
        // grid coordinate to Green indicating it is alive
        // point[0] is the x value, point[1] is the y value
        for(int[] point: lives_to_add){
            grid.setColor(point[0], point[1], Color.GREEN );
       }
    }

}