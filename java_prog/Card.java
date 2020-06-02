package ntou.cs.java2020.hw1;

public class Card {
	private final String face; // face of card ("Ace", "Deuce", ...)
	private final String suit; // suit of card ("Hearts", "Diamonds", ...)

	// two-argument constructor initializes card's face and suit
	public Card(String face, String suit) {
		this.face = face;
		this.suit = suit;
	}

	// return String representation of Card
	public String toString() {
		return face + " of " + suit;
	}

	public int getPoint() {
		int point = -1;
		for(int i=0;i<DeckOfCards.faces.length;i++){
			if(this.face.equals(DeckOfCards.faces[i])){
				if(i==0)point=20;
				else point=i+1;
				break;
			}
		}
		return point;
	}

} // end class Card

