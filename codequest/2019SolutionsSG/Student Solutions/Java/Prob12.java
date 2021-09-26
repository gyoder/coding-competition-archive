import java.util.Scanner;

public class Prob12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());
			for(int testcase = 0; testcase < testCases; testcase++) {
				String[] nums=input.nextLine().split(" ");
				int numDoors=Integer.parseInt(nums[0]);
				double percentage=100.0/numDoors;
				double total=percentage;
				for(int i=0; i<Integer.parseInt(nums[1]);i++)
				{
					numDoors-=Integer.parseInt(nums[2]);
					percentage=(100-total)/(numDoors-1-i);
					total+=percentage;
				}
				String out=Math.round(percentage*100)/100.0+"";
				if(!out.substring(out.length()-3, out.length()-2).equals("."))
					out+="0";
				System.out.println(out+"%");
			}
		}
	}

}
