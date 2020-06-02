package ntou.cs.java2020.ex2;

public class GameFirst {
	public static void main(String[] args) {
		Player player1 = new Player();
		System.out.printf("Player1 -> HP: %d, attack: %d%n", player1.getHp(), player1.getAttackPoints());
		Player player2 = new Player();
		System.out.printf("Player2 -> HP: %d, attack: %d%n", player2.getHp(), player2.getAttackPoints());

		while (true) {
			player1.attack(player2);
			System.out.printf("Player1 attacks! Player2's HP becomes %d%n", player2.getHp());

			if(player2.getHp()==0){
				System.out.printf("Player1 wins!\n");
				break;
			}

			player2.attack(player1);
			System.out.printf("Player2 attacks! Player1's HP becomes %d%n", player1.getHp());

			if(player1.getHp()==0){
				System.out.printf("Player2 wins!\n");
				break;
			}
		}
	}
}