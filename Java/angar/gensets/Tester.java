package angar.gensets;

public class Tester {
	
	/**
	 * Main test:
	 * 1. Process N sets, where N is passed as totalSets
	 * 2. Print last K sets with details, where K is passed as printLast
	 * 3. Print first L sets that have all 6 same numbers, where L is passed as printFirstSix
	 * 4. Print first M sets that have 5 same numbers, where M is passed as printFirstFive
	 * 
	 * @param totalSets
	 * @param printLast
	 * @param printFirstSix
	 * @param printFirstFive
	 */
	public static void mainТест(int totalSets, int printLast, int printFirstSix, int printFirstFive) {
		System.out.printf("Main test started.\n");
		if (totalSets > Dispatcher.TOTAL_NUMBER_OF_SETS)
		{
			System.err.printf("Error: invalid total number of sets: %d - should be less than %d\n", totalSets, Dispatcher.TOTAL_NUMBER_OF_SETS);
			return;
		}
		System.out.printf("Processing %d sets...\n", Dispatcher.TOTAL_NUMBER_OF_SETS);
		Tester.processSets(Dispatcher.TOTAL_NUMBER_OF_SETS);
		System.out.printf("Print last %d sets with details:\n", printLast);
		Tester.printSets(Dispatcher.TOTAL_NUMBER_OF_SETS - printLast, printLast);
		System.out.printf("Print first %d pairs of sets that have all 6 same numbers:\n", printFirstSix);
		Tester.printMatchesSix(printFirstSix);
		System.out.printf("Print first %d pairs of sets that have 5 same numbers:\n", printFirstFive);
		Tester.printMatchesFive(printFirstFive);
		System.out.printf("Main test is done.\n");
	}
	
	/**
	 * Processes sets of 6 numbers.
	 * Finds matches with previous sets.
	 */
	public static void processSets(int total) {
		for (int i = 0; i < total; i++) {
			Setter.processSet(Generator.generateSet(i));
		}
	}

	/**
	 * Print specified sets
	 */
	public static void printSets(int first, int total) {
		int index = first;
		if (index < 0)
		{
			index = 0;
		}
		for (int i = 0; i < total; i++) {
			if (index >= Dispatcher.currentset)
			{
				break;
			}
			printSet(index);
			System.out.printf("  ");
			printMatches(index);
			System.out.printf("\n");
			index++;
		}
	}
	
	public static void printSet(int index) 
	{
			if (index >= Dispatcher.currentset)
			{
				return;
			}
			StringBuilder stringBuilder = new StringBuilder(256);
			stringBuilder.append("Set " + index);
			stringBuilder.append(":{" + Dispatcher.allsets[index][0]);
			stringBuilder.append(", " + Dispatcher.allsets[index][1]);
			stringBuilder.append(", " + Dispatcher.allsets[index][2]);
			stringBuilder.append(", " + Dispatcher.allsets[index][3]);
			stringBuilder.append(", " + Dispatcher.allsets[index][4]);
			stringBuilder.append(", " + Dispatcher.allsets[index][5]);
			stringBuilder.append("}");
			System.out.printf(stringBuilder.toString());
	}
	
	public static void printMatches(int index)
	{
			if (index >= Dispatcher.currentset)
			{
				return;
			}
			StringBuilder stringBuilder = new StringBuilder(256);
			stringBuilder.append("Matches");
			stringBuilder.append(":{" + Dispatcher.allmatches[index][0]);
			stringBuilder.append(", " + Dispatcher.allmatches[index][1]);
//			stringBuilder.append(", " + Dispatcher.allmatches[index][2]);
//			stringBuilder.append(", " + Dispatcher.allmatches[index][3]);
//			stringBuilder.append(", " + Dispatcher.allmatches[index][4]);
//			stringBuilder.append(", " + Dispatcher.allmatches[index][5]);
//			stringBuilder.append(", " + Dispatcher.allmatches[index][6]);
			stringBuilder.append("}");
			System.out.printf(stringBuilder.toString());
	}
	
	public static void printMatchesFive(int total) {
		for (int i = 0; i < total; i++) {
			if (i >= Matcher.currentSameFive)
			{
				break;
			}
			printSet(Matcher.sameFive[i][0]);
			System.out.printf(" ");
			printMatches(Matcher.sameFive[i][0]);
			System.out.printf("\t\t");
			printSet(Matcher.sameFive[i][1]);
			System.out.printf(" ");
			printMatches(Matcher.sameFive[i][1]);
			System.out.printf("\n");
		}
	}
	
	public static void printMatchesSix(int total) {
		for (int i = 0; i < total; i++) {
			if (i >= Matcher.currentSameSix)
			{
				break;
			}
			printSet(Matcher.sameSix[i][0]);
			System.out.printf(" ");
			printMatches(Matcher.sameSix[i][0]);
			System.out.printf("  \t");
			printSet(Matcher.sameSix[i][1]);
			System.out.printf(" ");
			printMatches(Matcher.sameSix[i][1]);
			System.out.printf("\n");
		}
	}
}
