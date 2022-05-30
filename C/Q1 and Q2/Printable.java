
public interface Printable{
	public abstract void print();
	
	public static void print(Printable...print) {
		for (Printable pr: print)
		pr.print();
	}
}