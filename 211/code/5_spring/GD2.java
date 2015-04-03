import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


class GridDisplay extends JFrame
{
   private JLabel labels[];

   private Container container;
   private GridLayout grid1;
   int rowCount;
   int colCount;

   // set up GUI
   public GridDisplay(int rows, int cols)
   {
      super( "GridDisplay for CS211" );
      setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );

      // set up grid layout struture of the display
      rowCount = rows;
      colCount = cols;
      grid1 = new GridLayout( rows, cols );
      container = getContentPane();
      container.setLayout( grid1 );

      // create and add buttons
      labels = new JLabel[ rows * cols ];

      for ( int count = 0; count < labels.length; count++ ) {
         labels[ count ] = new JLabel( " " );
         labels[count].setOpaque(true);
         container.add( labels[ count ] );
      }

      // set up the size of the window and show it
      setSize( cols * 15 , rows * 15 );
      setVisible( true );

   } // end constructor GridLayoutDemo

   // display the given char in the (row,col) position of the display
   public void setChar (int row, int col, char c)
   {
     if ((row >= 0 && row < rowCount) && (col >= 0 && col < colCount) )
     {
       int pos = row * colCount + col;
       labels [pos].setText("" + c);  
     }
   }
   
   // display the given color in the (row,col) position of the display
   public void setColor (int row, int col, Color c)
   {
     if ((row >= 0 && row < rowCount) && (col >= 0 && col < colCount) )
     {
       int pos = row * colCount + col;
       labels [pos].setBackground(c);  
     }
   }
   
    // puts the current thread to sleep for some number of milliseconds to allow for "animation"
    public static void mySleep( int milliseconds)
    {
      try
      {
        Thread.sleep(milliseconds);
      }
      catch (InterruptedException ie)
      {
      }
    }
} // end class GridDisplay
