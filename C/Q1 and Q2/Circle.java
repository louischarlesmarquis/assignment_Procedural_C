
public class Circle extends PrintableObject implements Shape {
	private double radius;

	public Circle () {
		
	}
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	public double getArea() {
		return Math.PI*radius*radius;}
	public double getPerimeter() {
		return 2*Math.PI*radius;
		
	}
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public String toString() {
		return super.toString()+"," +this.radius+".";
	}
	
	public static Circle parse(String st) {
		String cir []= st.split(",",0);
		if (cir[0].equalsIgnoreCase("Circle")) {
		double a=Double.parseDouble(cir[1]);
			return new Circle(a);}
		else 
			return null;
		
	}
	
	public String getName() {
		//return super.getName().toUpperCase();
		return "CIRCLE";
	}

}
