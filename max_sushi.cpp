import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        for(int j=0;j<m;j++){
            b[j]=sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int c=0;
        int n1=a.length-1;
        int m1=b.length-1;
        while (n1!=0 && m1!=0){
            if(a[n1]*2>=b[m1]){
                c+=1;
                n1-=1;
                m1-=1;
            }
            else{
                m1-=1;
            }
        } 
        System.out.println(c);    }
}
