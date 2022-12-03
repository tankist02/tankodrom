package angar.gensets;

import java.util.Random;

public class Generator {
	
	private static final Random rand = new Random(1);
	
	private static final int[] set = new int[Dispatcher.NUMBERS_IN_SET];
	
	/**
	 * Returns a set of 6 numbers, their values are from 1 to 60.
	 */
	public static int[] generateSet(int index) {
		long bits = 0;
		for (int i = 0; i < Dispatcher.NUMBERS_IN_SET; ) {
			int number = getRandom(index);
			if ((bits & (1L << (number - 1))) != 0)
			{
				continue;
			}
			bits |= 1L << (number - 1);
			set[i] = number;
			i++;
		}
		return set;
	}
	
	/**
	 * Returns random integer from 1 to 60.
	 * @param index is not used yet
	 */
	private static int getRandom(int index)
	{
		int randomNumber = rand.nextInt(Dispatcher.MIN_NUMBER_IN_SET, Dispatcher.MAX_NUMBER_IN_SET);
		return randomNumber;
	}
}
