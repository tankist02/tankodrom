package angar.gensets;

public class Dispatcher {
	
	public static final int TOTAL_NUMBER_OF_SETS = 100_000;
	
	public static final int NUMBERS_IN_SET = 6;

	public static final int MIN_NUMBER_IN_SET = 1;
	public static final int MAX_NUMBER_IN_SET = 60;

	/**
	 *  Array to save sets
	 */
	public static final int[][] allsets = new int[TOTAL_NUMBER_OF_SETS][NUMBERS_IN_SET];
	
	/**
	 *  Array to save matches
	 *  Contains array of 6 numbers for each set:
	 *  [0] - total number of same 6 numbers in previous sets
	 *  [1] - total number of same 5 numbers in previous sets
	 */
	public static final int[][] allmatches = new int[TOTAL_NUMBER_OF_SETS][NUMBERS_IN_SET];
	
	/**
	 *  Index of current set. Only Setter can modify its value.
	 */
	public static int currentset = 0;


	/**
	 * Main entrance
	 * @param args - not used.
	 */
	public static void main(String[] args) {
		System.out.printf("GenSet started. Total number of sets: %d\n", TOTAL_NUMBER_OF_SETS);
		Tester.mainТест(TOTAL_NUMBER_OF_SETS, 10,10, 10);
		System.out.printf("GenSet finished\n");
	}
}
