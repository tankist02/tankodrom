package angar.gensets;

public class Setter {
	
	/**
	 * Processes a set of 6 numbers, their values are from 1 to 60.
	 * Finds matches with previous sets.
	 */
	public static void processSet(int[] set) {
		for (int i = 0; i < Dispatcher.NUMBERS_IN_SET; i++) {
			Dispatcher.allsets[Dispatcher.currentset][i] = set[i];
		}
		Matcher.findAndSaveMatches(set);
		Dispatcher.currentset++;
	}
	
}
