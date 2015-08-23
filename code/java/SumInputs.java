public class SumInputs {
  public static void main(String args[]) {
    float total = 0;

    for (int i = 0; i < args.length; i++) {
      total += Float.parseFloat(args[i]);
    }

    System.out.println(total);
  }
}
