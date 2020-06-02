package ntou.cs.java2020.hw1;

import java.security.SecureRandom;
import java.util.Scanner;

public class PokerGameTest {
	public static void main(String[] args) {
		PokerGame game = new PokerGame();
		Scanner input = new Scanner(System.in);
		int cmd,flag=0;
		for(;flag!=1;){
			System.out.printf("Please input your choice (0: quit, 1: play, 2: restart):");
			cmd=input.nextInt();
			switch(cmd){
				case 0:
					flag=1;
					System.out.printf("It's nice having you.Good bye!");
					break;
				case 1:
					game.dealFiveCards();
					break;
				case 2:
					game = new PokerGame();
					game.dealFiveCards();
					break;
				default:
					System.out.printf("Invalid input, please try again.");
					break; 
			}
			if(flag==1)break;
		}
	}
} // end class PokerGame
