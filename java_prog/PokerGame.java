package ntou.cs.java2020.hw1;

public class PokerGame {
	private DeckOfCards myDeckOfCards;

	public PokerGame() {
		myDeckOfCards = new DeckOfCards();
		myDeckOfCards.shuffle();
	}
	
	public void dealFiveCards() {
		int total=0,flag=0;
		for(int i=0;i<5;i++){
			Card temp=myDeckOfCards.dealCard();
			if(temp==null){
				flag=1;
				break;
			}
			System.out.printf("You got %s,point is %d\n",temp.toString(),temp.getPoint());
			total+=temp.getPoint();
		}
		if(flag==1) System.out.printf("No card can be dealt, please restart the game!\n");
		else System.out.printf("Your total point is %d\n",total);
	}

} // end class PokerGame
