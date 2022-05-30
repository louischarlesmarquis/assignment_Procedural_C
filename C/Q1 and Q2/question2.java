import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class question2 {

	public static void main(String... comparator) throws FileNotFoundException, IOException {
		
		//reading the file with BufferedReader
		try (BufferedReader reader = new BufferedReader(new FileReader("Shapes.txt"))){
			
			//Creating an arraylist of Shape
			ArrayList<Shape> Shapes = new ArrayList<>();
		
			String st="";
			//checking to see that the lines to be read are not null
			while((st= reader.readLine()) != null) {
				String arr[]= st.split(",");
				
				//if the array is of length 2, which is a circle shape than store in Shape list 
				if (arr.length==2) {
					Shapes.add(Circle.parse(st));
				}
				//if the array is a length other than 2, than store rectangle in Shape list
				else {
					Shapes.add(Rectangle.parse(st));
				}
				
			}
			
			//sorting the shapes to order them by name
			Collections.sort(Shapes, new Comparator<Shape>() {
				public int compare(Shape s1, Shape s2) {
					return s1.getName().compareTo(s2.getName());
					
				}
				
			});
			
			//sorting the shapes to order them by area
			Collections.sort(Shapes, new Comparator<Shape>() {
				public int compare(Shape s1, Shape s2) {
					
					if (s1.getArea()>s2.getArea()) {
						return 1;
					}
					
					else if (s1.getArea()<s2.getArea()) {
						return 0;
					}
					else {
						return -1;
					}
					
				}
			});
			
			
			//iterating the shapes by calling the print method
			for (Shape shape: Shapes) {
				Printable Printable = (Printable) shape;
				Printable.print();
			}
	
	//catching the exception
	} catch (FileNotFoundException e) {
		System.out.println("File could not be read properly!!");
		System.out.println(0);
	}
		//catching the exception
		catch (IOException e) {
			e.printStackTrace();
		}
	
	}
}
