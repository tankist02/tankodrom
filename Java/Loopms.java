public class Loopms 
{
    public static void loopmillisec(long limit)
    {
        long count = 0;
        long start = System.currentTimeMillis();
        long end = start;
        while (end - start < limit) 
        {
            count += 1;
            end = System.currentTimeMillis();
        }

        System.out.println("start: " + start);
        System.out.println(" end: " + end);
        System.out.println("count: " + count);
    }

    public static void main(String[] args) 
    {
        Loopms.loopmillisec(1000);
    }
}

