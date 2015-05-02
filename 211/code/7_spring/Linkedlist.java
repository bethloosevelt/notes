
public class Linkedlist {
    Node start;
    Node end;
    int size;
    Linkedlist(){
        size = 0;
        Node st = new Node(-111);
        Node en = new Node(-999);
        start = st;
        end = en;

        start.next = end;
        end.previous = start;

        end.next = null;
        start.previous = null;
    }

    void addNode(int v) {
        if (!exists(v)) {
            Node newNode = new Node(v);
            Node temp = start;
            while ( temp.next != end ) {
                temp = temp.next;
            }

            temp.next = newNode;
            newNode.previous = temp;
            newNode.next = end;
            size++;
        }
    }

    boolean exists(int v) {
        Node newNode = new Node(v);
        Node temp = start.next;

        while ( temp != end ) {

            if ( temp.value == v) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    boolean removeNode(int v) {
        Node newNode = new Node(v);
        Node temp = start.next;

        while ( temp != end ) {

            if ( temp.value == v) {
                temp.next.previous = temp.previous;
                temp.previous.next = temp.next;
                size--;
                return true;
            }

            temp = temp.next;
        }
        return false;
    }

    int[] contents() {
        int[] list = new int[ size ];
        Node temp = start.next;

        for ( int i=0; temp != end; i++ ) {

            list[i] = temp.value;
            temp = temp.next;
        }
        return list;
    }

}
