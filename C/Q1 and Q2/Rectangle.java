
public  class Rectangle extends PrintableObject implements Shape {
	private double sideone;
	private double sidetwo;
	
	public Rectangle() {
		
	}
	
	public Rectangle(double sideone, double sidetwo) {
		super();
		this.sideone = sideone;
		this.sidetwo = sidetwo;
	}

	public double getArea() {
		return sideone*sidetwo;}
	public double getPerimeter() {
		return ((sideone*2)+(sidetwo*2));
		
	}
	public double getSideone() {
		return sideone;
	}

	public void setSideone(double sideone) {
		this.sideone = sideone;
	}

	public double getSidetwo() {
		return sidetwo;
	}

	public void setSidetwo(double sidetwo) {
		this.sidetwo = sidetwo;
	}

	public String toString() {
		return super.toString()+"," +this.sideone + "," + this.sidetwo + ".";
	}
	
	public String getName() {
		return "RECTANGLE";
	}
	
	public static Rectangle parse(String st) {
		
		String rec []= st.split(",",0);
		if (rec[0].equalsIgnoreCase("Rectangle")){
		double a=Double.parseDouble(rec[1]);
		double b=Double.parseDouble(rec[2]);
			return new Rectangle(a,b);}
		else 
			return null;
			
		
	}
}
