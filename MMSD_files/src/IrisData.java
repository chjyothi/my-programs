
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;

public class IrisData {

public static Double sLenth;
public Double sWidth;
public Double pLenth;
public Double pWidth;
public String className;

public IrisData(Double sLenth,Double sWidth,Double pLenth,Double pWidth) {
   this.sLenth=sLenth;
   this.sWidth=sWidth;
   this.pLenth=pLenth;
   this.pWidth=pWidth;
   //this.className=className;
}


public static void main(String[] args) throws IOException {
    IrisData[] e = new IrisData[150];
    int num=0;
    Double t=0.0;
    ArrayList<Double> t_sLenth = new ArrayList();
    ArrayList<Double> t_sWidth = new ArrayList();
    ArrayList<Double> t_pLenth = new ArrayList();
    ArrayList<Double> t_pWidth = new ArrayList();
   
    DecimalFormat df = new DecimalFormat("#.00"); 
  
    FileReader fr=new FileReader("iris.data");
    try {
    BufferedReader br=new BufferedReader(fr);
   
    String line="";
    String[] arrs=null;
    while ((line=br.readLine())!=null) {
        arrs=line.split(",");
       // System.out.println("is" + arrs[5]);
        e[num] = new IrisData(Double.valueOf(arrs[0]), Double.valueOf(arrs[1]), Double.valueOf(arrs[2]),Double.valueOf(arrs[3]));
        t_sLenth.add(Double.valueOf(arrs[0]));
        t_sWidth.add(Double.valueOf(arrs[1]));
        t_pLenth.add(Double.valueOf(arrs[2]));
        t_pWidth.add(Double.valueOf(arrs[3]));
        num++;
  
    }
    br.close();
    fr.close();
    }
   
    catch (Exception e1) {
    	System.out.println("--");
    }
    Double sum_sLenth=0.0,sum_sWidth=0.0,sum_pLenth=0.0,sum_pWidth=0.0;
   
    for(int i=0 ; i< e.length; i++) {
    	//System.out.println("record by record"+ e.length);
      //  System.out.println(e[i].sLenth + " and " + e[i].sWidth + " and " + e[i].pLenth + " and " + e[i].pWidth);
        
    	sum_sLenth = sum_sLenth + e[i].sLenth;
    	
        sum_sWidth= sum_sWidth+e[i].sWidth;
        
        sum_pLenth= sum_pLenth+e[i].pLenth;
        
        sum_pWidth= sum_pWidth+e[i].pWidth;
        
       
        
    }
        System.out.println("  SLength  Swidth  PLength  PWidth");
        System.out.println("----------------mean-------------");
        System.out.println(" " + df.format(sum_sLenth/e.length) +" "+ df.format(sum_sWidth/e.length)+" "+ df.format(sum_pLenth/e.length)+ " "+ df.format(sum_pWidth/e.length));
        System.out.println("---------------meadian------------");
      
        System.out.println("  "+ findMedian(t_sLenth,num)+"  "+ findMedian( t_sWidth,num)+"  "+ findMedian(t_pLenth,num)+"  "+ findMedian(t_pWidth,num));
        System.out.println("----------Stanard deviation-------");
        System.out.println("  "+ df.format(findSD(t_sLenth,num))+"  "+ df.format(findSD( t_sWidth,num))+"  "+ df.format(findSD(t_pLenth,num))+"  "+ df.format(findSD(t_pWidth,num)));
        System.out.println("file format should be in .csv ");
        System.out.println("------------Histogram------------");
        Histogram z = new Histogram();
		z.Histogram();
		System.out.println();
		System.out.println();
}

public static double findMedian(ArrayList<Double> sLenth, int n) 
{ 
    // First we sort the array 
	//sLenth.sort(c);; 
	Collections.sort(sLenth);

    // check for even case 
    if (n % 2 != 0) 
        return (double)sLenth.get(n / 2); 

    return (double)(sLenth.get((n - 1) / 2) + sLenth.get(n / 2)) / 2.0; 
} 




public static double findSD(ArrayList<Double> sLenth, int n)
{
    double sum = 0.0, standardDeviation = 0.0;
    int length =n;

    for(double num : sLenth) {
        sum += num;
    }

    double mean = sum/length;
    for(double num: sLenth) {
        standardDeviation += Math.pow(num - mean, 2);
    }

    return Math.sqrt(standardDeviation/length);
}



}