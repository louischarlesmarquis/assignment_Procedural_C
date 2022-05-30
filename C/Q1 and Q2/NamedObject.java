
public interface NamedObject {

	public default String getName() {
		return (String)this.getClass().getSimpleName();
	}
	
}
