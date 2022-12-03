package angar.gensets;

public class Matcher {
	
	/**
	 *  Array to save bits for comparison
	 */
	public static final long[][] allSetsAsBits = new long[Dispatcher.TOTAL_NUMBER_OF_SETS][Dispatcher.NUMBERS_IN_SET];

	public static final int[][] sameSix = new int[Dispatcher.TOTAL_NUMBER_OF_SETS][2];
	public static final int[][] sameFive = new int[Dispatcher.TOTAL_NUMBER_OF_SETS][2];

	public static int currentSameSix = 0;
	public static int currentSameFive = 0;
	
	/**
	 * Compare set with previous sets and save results of comparison
	 */
	public static void findAndSaveMatches(int[] set)
	{
		 // Save bits for fast comparison
		saveBits(Dispatcher.currentset, set);
		// Compare current set with previous sets and save matches
		for (int index = 0; index < Dispatcher.currentset; index++) {
			compareSets(index, Dispatcher.currentset);
		}
	}

	/**
	 * Compare sets specified by index
	 */
	private static void compareSets(int oldindex, int newindex)
	{
		// Compare all 6 numbers
		if (allSetsAsBits[oldindex][0] == allSetsAsBits[newindex][0])
		{
			Dispatcher.allmatches[newindex][0] += 1;
			sameSix[currentSameSix][0] = oldindex;
			sameSix[currentSameSix][1] = newindex;
			currentSameSix++;
			return;
		}
		// Compare 5 of 6 numbers
		for (int i = 0; i < Dispatcher.NUMBERS_IN_SET; i++) {
			long bit = 1L << (Dispatcher.allsets[newindex][i] - 1);
			long fivebits = allSetsAsBits[newindex][0] ^ bit;
			if ((allSetsAsBits[oldindex][0] & fivebits) == fivebits)
			{
				// found match
				Dispatcher.allmatches[newindex][1] += 1;
				sameFive[currentSameFive][0] = oldindex;
				sameFive[currentSameFive][1] = newindex;
				currentSameFive++;
				return;
			}
		}
	}
	
	/**
	 * Save bits of the set for comparison
	 */
	public static void saveBits(int index, int[] set)
	{
		long bits = 0;
		for (int i = 0; i < Dispatcher.NUMBERS_IN_SET; i++) {
			bits |= 1L << (set[i] - 1);
		}
		allSetsAsBits[index][0] = bits;
	}

}
