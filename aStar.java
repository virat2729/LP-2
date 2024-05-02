import java.io.*;  
import java.util.*;  
   
class aStar  
{     
    public static int N1 = 3;  
    public static class Node  
    {  
         
        Node parent1;  
        int m[][] = new int[N1][N1];
        int x1, y1;
        int cost1;  
        int level1;  
    }  
        
    public static void printMatrix(int m[][]){  
        for(int i1 = 0; i1 < N1; i1++){  
            for(int j1 = 0; j1 < N1; j1++){  
                System.out.print(m[i1][j1]+" ");  
            }  
            System.out.println("");  
        }  
    }

    public static Node newNode(int m[][], int x1, int y1,  
                               int newX1, int newY1, int level1,  
                               Node parent1){  
        Node node1 = new Node();  
        node1.parent1 = parent1;
         
        node1.m = new int[N1][N1];  
        for(int i1 = 0; i1 < N1; i1++){  
            for(int j1 = 0; j1 < N1; j1++){  
                node1.m[i1][j1] = m[i1][j1];  
            }  
        }  
           
        int temp1 = node1.m[x1][y1];  
        node1.m[x1][y1] = node1.m[newX1][newY1];  
        node1.m[newX1][newY1]=temp1;  
           
        node1.cost1 = Integer.MAX_VALUE;  
        node1.level1 = level1; 
           
        node1.x1 = newX1;  
        node1.y1 = newY1;  
           
        return node1;  
    }  
       
    public static int row1[] = { 1, 0, -1, 0 };  
    public static int col1[] = { 0, -1, 0, 1 };  
       
    public static int calculateCost(int initialM[][], int finalM[][])  
    {  
        int count1 = 0;  
        for (int i1 = 0; i1 < N1; i1++)  
          for (int j1 = 0; j1 < N1; j1++)  
            if (initialM[i1][j1]!=0 && initialM[i1][j1] != finalM[i1][j1])  
               count1++;  
        return count1;  
    }  
        
    public static int isSafe(int x1, int y1)  
    {  
        return (x1 >= 0 && x1 < N1 && y1 >= 0 && y1 < N1)?1:0;  
    }  
       
    public static void printPath(Node root1){  
        if(root1 == null){  
            return;  
        }  
        printPath(root1.parent1);  
        printMatrix(root1.m);  
        System.out.println("");  
    }  
       
    public static class comp implements Comparator<Node>{  
        public int compare(Node lhs1, Node rhs1){  
            return (lhs1.cost1 + lhs1.level1) > (rhs1.cost1+rhs1.level1)?1:-1;  
        }  
    }  
        
    public static void solve(int initialM[][], int x1,  
                             int y1, int finalM[][])  
    {  
         
        PriorityQueue<Node> pq1 = new PriorityQueue<>(new comp());  
           
        Node root1 = newNode(initialM, x1, y1, x1, y1, 0, null);  
        root1.cost1 = calculateCost(initialM,finalM);  
            
        pq1.add(root1);  
            
        while(!pq1.isEmpty())  
        {  
            Node min1 = pq1.peek();  
            pq1.poll();  
           
            if(min1.cost1 == 0){  
                printPath(min1);  
                return;  
            }  
              
            for (int i1 = 0; i1 < 4; i1++)  
            {  
                if (isSafe(min1.x1 + row1[i1], min1.y1 + col1[i1])>0)  
                {    
                    Node child1 = newNode(min1.m, min1.x1, min1.y1, min1.x1 + row1[i1],min1.y1 + col1[i1], min1.level1 + 1, min1);  
                    child1.cost1 = calculateCost(child1.m, finalM);  
                    pq1.add(child1);  
                }  
            }  
        }  
    }  
       
    public static void main (String args[])  
    {  
         
        int initialM[][] =  
        {  
            {0, 1, 2},  
            {4, 5, 8},  
            {6, 7, 3}  
        };  
        
        int finalM[][] =  
        {  
            {0, 3, 7},  
            {4, 2, 5},  
            {6, 8, 1}  
        };  

        int x1 = 1, y1 = 2;  
        
        solve(initialM, x1, y1, finalM);  
    }  
}
