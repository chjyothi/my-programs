import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author chjyo
 *
 */
public class Histogram {
	public void Histogram() {
		
		
		String fileName = "iris.csv";
		File file = new File(fileName);
		DecimalFormat df = new DecimalFormat("#.00"); 
		
		//SL
		try {
			Scanner inputStream = new Scanner(file);
			inputStream.next();
			List<Double> temps = new ArrayList<Double>();
			while (inputStream.hasNext()) {
				String data = inputStream.next();
				String[] values = data.split(",");
				double SepalLength = Double.parseDouble(values[0]);
				temps.add(SepalLength);
				//System.out.println(PetalWidth);
			}
			inputStream.close();
			
			Double[] tempsArray = temps.toArray(new Double[0]);
			Arrays.sort(tempsArray);
			int totalElements = tempsArray.length;
			Double min = tempsArray[0];
			Double max = tempsArray[totalElements-1];
			Double intSize = (max-min)/10;
			int count = 0;
			
			for(double i = min; i <= max; i=i+intSize) {
				System.out.println("\n"+df.format(i) + " - " + df.format((i+intSize)) + ": ");
				for (int x = 0; x < totalElements; x++) {
					if ((tempsArray[x] == i) || (tempsArray[x] < i+intSize)) count++;
				}
				System.out.println();
				System.out.print("("+(count)+")");
				for(int j=0;j<count;)
				{
					System.out.print("*");
					j=j+10;
				}
				
			}
			
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	}
	


