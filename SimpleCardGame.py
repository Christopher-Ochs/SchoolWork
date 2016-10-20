# Christopher Ochs
# March 17, 2016 

import random

class Card:

    suit_names = ["Clubs", "Diamonds", "Hearts", "Spades"]
    rank_names = [None, "Ace", "2", "3", "4", "5", "6", "7", 
              "8", "9", "10", "Jack", "Queen", "King"]

    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank

    def __str__(self):
        return (Card.rank_names[self.rank] + " " +
                             Card.suit_names[self.suit])

class DeckOfCard:

    def __init__(self):
        self.cards = []
        for suit in range(4):
            for rank in range(1, 14):
                card = Card(suit, rank)
                self.cards.append(card)

    def __str__(self):
        result = "\n" 
        for card in self.cards:
            result += str(card) + "\n"
        return result

    def shuffle(self):
        random.shuffle(self.cards)

    def dealNextCard(self):
        card = self.cards.pop()
        return card


class Hand:
    
    def __init__(self):
        self.cards = []

    def __str__(self):
        result = "\n" 
        for card in self.cards:
            result += str(card) + "\n"
        return result

    def add(self,card):
        self.cards.append(card)

    def evaluate(self):
        for a in self.cards:
            for b in self.cards:
                if (a.rank == b.rank) and (a.suit != b.suit):
                    return True
        return False

    def compare(self,new):
        if (self.evaluate) and !(new.evaluate):
            return True
        if !(self.evaluate) and (new.evaluate):
            return False        

deck = DeckOfCard()
deck.shuffle()
table = []
while (len(table)<5):
    h = Hand()
    table.append(h)

for _card in range(5):
    for h in table:
        h.add(deck.dealNextCard())

for h in table:
    if h.evaluate():
        print(h.__str__() + "\n This hand has a pair!")
    else:
        print(h.__str__() + "\n This hand doesn't have a pair!")


