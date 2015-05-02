public class Graph {

    Linkedlist[] graph;
    int size;
    int edges;

    Graph(int capacity) {
        edges = 0;
        size = capacity;
        graph = new Linkedlist[capacity];
        for ( int i=0; i<capacity; i++) {
            graph[i] = new Linkedlist();
        }
    }

    // returns true if added edge successfully
    // false if either airport was out of range
    boolean addEdge(int from, int to) {
        // change them to zero index
        from--;

        if ( from > (size-1) || from < 0 || to >size || to < 1) {
            System.out.println("error out of bounds airport");
            return false;
        }

        graph[from].addNode(to);
        edges++;
        return true;
    }

    void resize(int newSize) {
        if ( newSize < size) {
            System.out.println("invalid next size");
            return;
        }
        Linkedlist[] temp= new Linkedlist[newSize];

        // the new array bits need to be initialized
        for ( int i= (size-1); i<newSize; i++) {
            temp[i] = new Linkedlist();
        }
        System.arraycopy( graph , 0, temp, 0, graph.length );
        size = newSize;
        graph = temp;
    }

    // returns true if added edge successfully
    // false if either airport was out of range
    boolean removeEdge(int from, int to) {
        // change them to zero index
        from--;

        if ( from > (size-1) || from < 0 || to > size || to < 1) {
            System.out.println("error out of bounds airport");
            return false;
        }

        if ( graph[from].removeNode(to) ) {
            edges--;
            return true;
        }
        return false;
    }

    boolean hasPath(int from, int to, Linkedlist beento) {
        beento.addNode(from);
        from--;
        int[] connectedTo = graph[from].contents();
        if ( in(connectedTo, to) ) {
            return true;
        }
        else {
            for( int i=0; i<connectedTo.length; i++) {

                if ( !beento.exists(connectedTo[i]) ) {
                    return hasPath(connectedTo[i], to, beento);
                }
            }
            return false;
        }
    }

    boolean in( int[] arr, int val) {
        for ( int i=0; i<arr.length; i++) {
            if (arr[i] == val) {
                return true;
            }
        }
        return false;
    }


    // // returns true if added edge successfully
    // // false if either airport was out of range
    // boolean addTwoWayEdge(int from, int to) {
    //     // change them to zero index
    //     from--;
    //     to--;
    //
    //     if ( from > 9 || from < 0 || to >9 || to < 0) {
    //         System.out.println("error out of bounds airport");
    //         return false;
    //     }
    //
    //     graph[from].addNode(to);
    //     graph[to].addNode(from);
    //     edges += 2;
    //     return true;
    // }

    // print the values in each linked list of the graph
    // note that since .size() will return zero if the list is empty,
    // empty linked lists aren't a problem. They will skip the for loop
    void printAll() {
        Linkedlist temp;
        int[] listContents;

        System.out.println();
        for( int i=0; i<size; i++) {

            System.out.print( (i+1) + ": ");
            listContents = graph[i].contents();
            for (int j=0; j<graph[i].size; j++) {
                System.out.print(listContents[j] + " ");
            }
            System.out.println();
        }

        System.out.println();
    }

}
