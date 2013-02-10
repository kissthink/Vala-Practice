public abstract class Discount : Object {

	public abstract double acceptCash (double cash);

}

public class DiscountRate : Discount {

	public double rate { get; set; }

	public DiscountRate (double rate)  
		requires (0.00 < rate <= 100.00)
	{		
		this.rate = rate;
	}

	public override double acceptCash (double cash) {

		return cash * this.rate / 100 ; 
	}
}