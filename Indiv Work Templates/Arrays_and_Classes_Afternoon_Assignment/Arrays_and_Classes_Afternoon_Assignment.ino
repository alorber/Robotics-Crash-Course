// Arrays & Classes afternoon assignment

// Card class
class Card {
    char suit;
    int value;

  public:
    Card(char s, int v);
    char getSuit() {return suit;}
    int getValue() {return value;}
};

// Card constructor
Card::Card(char s, int v){
  suit = s;
  // Makes sure the card value is between 1 & 13.
  value = constrain(v, 1, 13);
}

// Deck class
class Deck {
    Card* cards[52];
    int topcard = -1;

  public:
    Deck();
    Card getTopCard();
    void reset();
    void shuffle();
    void printDeck();
};


Deck::Deck() {
  char suits[4] = {'H', 'S', 'C', 'D'};
  int ind = 0;
  for(char s : suits){
    for(int i = 1; i <= 13; i++){
      cards[ind] = new Card(s, i);
      ind++;
    }
  }
}

Card Deck::getTopCard(){
  if(topcard == 51){
    Serial.println("Deck is empty.");
    Serial.println("Shuffling...");
    shuffle();
  }
  topcard++;
  return *(cards[topcard]);
}

void Deck::reset(){
  char suits[4] = {'H', 'S', 'C', 'D'};
  int ind = 0;
  for(char s : suits){
    for(int i = 1; i <= 13; i++){
      cards[ind] = new Card(s, i);
      ind++;
    }
  }
  topcard = 0;
}

void Deck::shuffle(){
  for(int i = 0; i < 52; i++){
    int r = random(52);
    Card* tempC = cards[i];
    cards[i] = cards[r];
    cards[r] = tempC;
  }
  topcard = 0;
}

void Deck::printDeck(){
  for(Card* c : cards){
    Serial.print(c->getSuit());
    Serial.println(c->getValue());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Deck d;
  d.shuffle();
  d.printDeck();
}

void loop() {
  // put your main code here, to run repeatedly:

}
