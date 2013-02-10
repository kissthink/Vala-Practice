public class DiscountFactory : Object {

	public static Discount CreateDiscount (string rate) {

		return new DiscountRate(double.parse (rate));
	}
}