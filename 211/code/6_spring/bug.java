// generic class to impliment the basic characteristics of a bug
// dying, moving, location, spawning
// species specific methods will be implimented in extentions to this class
// all methods depend on an existing world to operate
public class Bug {
    // position
    int x_pos;
    int y_pos;
    int days_alive;
    int days_since_gave_birth;
    ArrayList<Bug> neighbors; 

    // create a new bug, adding it to the grid
    public Bug() {
        // a new bug  has not given birth or been alive
        days_alive = 0;
        days_since_gave_birth = 0;

        // this bug was just created, and has not been added to a world
        x_pos = null;
        y_pos = null;
    }

    // takes existing world, and adds self to the grid 
    // returns new grid
    // rules for adding: chooses a random grid location
    // if location is occupied, a new location is chosen until a vacancy has been found
    public bug[][] addSelfToWorld( int[][] world, ArrayList<bug> bugs ) {

        return new_bug_world;
    }


    // takes the existing world
    // returns new grid
    // attempts to move up down left or right
    // if the randomly chosen direction is occupied
    // the bug stays put
    public bug[][] move( bug[][] bug_world ) {

        return new_bug_world;
    }


    public bug[][] 
}